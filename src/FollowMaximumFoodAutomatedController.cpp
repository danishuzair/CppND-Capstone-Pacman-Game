
#include "FollowMaximumFoodAutomatedController.h"

void FollowMaximumFoodAutomatedController::GetNewInput(bool &running, Pacman &pacman) {
	SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            running = false;
            return;
        }
    }

    std::shared_ptr<TrafficObject> currentIntersectionOrStreet = pacman.getCurrentIntersectionOrStreet();
    if (currentIntersectionOrStreet->getType() != ObjectType::intersection) {
		Direction newDirection = GetUpdatedDirectionForGhostFound(std::reinterpret_pointer_cast<Street>(currentIntersectionOrStreet), GetIndexFromDirection(pacman.getCurrentDirection()), pacman.getLocationX(), pacman.getLocationY());
		pacman.updateDirection(newDirection);
    }
    else {
    	Direction newDirection = GetUpdatedDirectionForMaximumFood(std::reinterpret_pointer_cast<Intersection>(currentIntersectionOrStreet), GetIndexFromDirection(pacman.getCurrentDirection()));
 		pacman.updateDirection(newDirection);
    }
}

Direction FollowMaximumFoodAutomatedController::GetUpdatedDirectionForGhostFound(std::shared_ptr<Street> currentStreet, int indexOfCurrentDirection, int xPacmanCurrentLocation, int yPacmanCurrentLocation) const {
	bool ghostFound = false;
	for (auto ghost: ghosts) {
		ghostFound = currentStreet->isGhostFound(GetDirectionFromIndex(indexOfCurrentDirection),xPacmanCurrentLocation,yPacmanCurrentLocation,ghost->getLocationX(),ghost->getLocationY());
		if (ghostFound) {break;}
	}
	if (ghostFound){return switchDirection(GetDirectionFromIndex(indexOfCurrentDirection));}
	return GetDirectionFromIndex(indexOfCurrentDirection);
}

Direction FollowMaximumFoodAutomatedController::switchDirection(Direction currentDirection) const{
	if (currentDirection == Direction::left){return Direction::right;}
	if (currentDirection == Direction::right){return Direction::left;}
	if (currentDirection == Direction::up){return Direction::down;}
	return Direction::up;
}

Direction FollowMaximumFoodAutomatedController::GetUpdatedDirectionForMaximumFood (std::shared_ptr<Intersection> currentIntersection, int indexOfCurrentDirection) {
	std::array<double, 4> availableFood = {0, 0, 0, 0};
	availableFood.at(0) = SearchDepthFirst(currentIntersection->getLeftStreet(), searchDepth, currentIntersection, 0);
	availableFood.at(1) = SearchDepthFirst(currentIntersection->getRightStreet(), searchDepth, currentIntersection, 0);
	availableFood.at(2) = SearchDepthFirst(currentIntersection->getUpStreet(), searchDepth, currentIntersection, 0);
	availableFood.at(3) = SearchDepthFirst(currentIntersection->getDownStreet(), searchDepth, currentIntersection, 0);
	if (std::max({availableFood.at(0),availableFood.at(1),availableFood.at(2),availableFood.at(3)}) <= 0.01) {
		searchDepth = searchDepth + 3;
	}
	else if (searchDepth > 3) {
		searchDepth = 3;
	}
	int indexOfNewDirection = FindIndexOfNewDirection(availableFood, indexOfCurrentDirection);
	return GetDirectionFromIndex(indexOfNewDirection);
}

double FollowMaximumFoodAutomatedController::SearchDepthFirst(std::shared_ptr<Street> streetToSearch, int depthRemaining, 
	std::shared_ptr<Intersection> currentIntersection, int previousStreetLength) const {
	if (streetToSearch == nullptr) {return -1;}
	if (depthRemaining < 0) {return 0;}
	depthRemaining = depthRemaining - 1;
	std::shared_ptr<Intersection> otherIntersection = streetToSearch->getOtherIntersection(currentIntersection);
	bool ghostFound = false;
	double length = streetToSearch->getStreetLength() + previousStreetLength;
	for (auto ghost : ghosts) {
		if (streetToSearch->checkifonstreet(ghost->getLocationX(), ghost->getLocationY())) {
			ghostFound = true;
			break;
		}
	}
	return streetToSearch->getRemainingFoodOnStreet()/length - 10000 * ghostFound/length + 
		std::max({SearchDepthFirst(otherIntersection->getLeftStreet(),depthRemaining,otherIntersection, length),
		SearchDepthFirst(otherIntersection->getRightStreet(),depthRemaining,otherIntersection, length),
		SearchDepthFirst(otherIntersection->getUpStreet(),depthRemaining,otherIntersection, length),
		SearchDepthFirst(otherIntersection->getDownStreet(),depthRemaining,otherIntersection, length)});
}

int FollowMaximumFoodAutomatedController::FindIndexOfNewDirection(std::array<double,4> availableFood, int indexOfCurrentDirection) const {
	std::vector<int> indexOfMaximumElement = FindIndexOfMaximumElements(availableFood);
	if (indexOfMaximumElement.size() == 1) {return indexOfMaximumElement.at(0);}
	return BreakTiesRandomly(indexOfMaximumElement, indexOfCurrentDirection);
}

int FollowMaximumFoodAutomatedController::BreakTiesRandomly(std::vector<int> indexOfMaximumElement, int indexOfCurrentDirection) const {
	for (int i=0; i<indexOfMaximumElement.size(); i++) {
		if (indexOfMaximumElement.at(i) == indexOfCurrentDirection) {
			indexOfMaximumElement.erase(indexOfMaximumElement.begin() + i);
		}
	}
	std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<int> distr(0, indexOfMaximumElement.size()-1);
    int indexOfNewDirection = distr(eng);
    return indexOfMaximumElement.at(indexOfNewDirection);
}

std::vector<int> FollowMaximumFoodAutomatedController::FindIndexOfMaximumElements(std::array<double,4> availableFood) const{
	std::vector<int> indexOfMaximumElement;
	double currentMaximum;
	currentMaximum = availableFood.at(0);
	indexOfMaximumElement.push_back(0);
	for (int i = 1; i < 4; i++) {
		if (availableFood.at(i) == currentMaximum) {
			indexOfMaximumElement.push_back(i);
		}
		else if (availableFood.at(i) > currentMaximum) {
			currentMaximum = availableFood.at(i);
			indexOfMaximumElement.clear();
			indexOfMaximumElement.push_back(i);
		}
	}
	return indexOfMaximumElement;
}

Direction FollowMaximumFoodAutomatedController::GetDirectionFromIndex (int indexOfNewDirection) const {
	switch (indexOfNewDirection) {
		case (0):
			return Direction::left;
		case (1):
			return Direction::right;
		case (2):
			return Direction::up;
		case (3):
			return Direction::down;
	}
}

int FollowMaximumFoodAutomatedController::GetIndexFromDirection (Direction currentDirection) const {
	switch (currentDirection) {
		case (Direction::left):
			return 0;
		case (Direction::right):
			return 1;
		case (Direction::up):
			return 2;
		case (Direction::down):
			return 3;
	}
}