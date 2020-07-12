
#include "FollowMaximumFoodAutomatedController.h"

void FollowMaximumFoodAutomatedController::GetNewInput(bool &running, Pacman &pacman) const {
	SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            running = false;
            return;
        }
    }

    std::shared_ptr<TrafficObject> currentIntersectionOrStreet = pacman.getCurrentIntersectionOrStreet();
    if (currentIntersectionOrStreet->getType() != ObjectType::intersection) {return; }
 	Direction newDirection = GetUpdatedDirectionForMaximumFood(std::reinterpret_pointer_cast<Intersection>(currentIntersectionOrStreet));
 	pacman.updateDirection(newDirection);
}

Direction FollowMaximumFoodAutomatedController::GetUpdatedDirectionForMaximumFood (std::shared_ptr<Intersection> currentIntersection) const {
	std::array<int, 4> availableFood = {0, 0, 0, 0};
	availableFood.at(0) = SearchDepthFirst(currentIntersection->getLeftStreet(), searchDepth, currentIntersection);
	availableFood.at(1) = SearchDepthFirst(currentIntersection->getRightStreet(), searchDepth, currentIntersection);
	availableFood.at(2) = SearchDepthFirst(currentIntersection->getUpStreet(), searchDepth, currentIntersection);
	availableFood.at(3) = SearchDepthFirst(currentIntersection->getDownStreet(), searchDepth, currentIntersection);
	int indexOfNewDirection = FindIndexOfNewDirection(availableFood);
	return GetDirectionFromIndex(indexOfNewDirection);
}

int FollowMaximumFoodAutomatedController::SearchDepthFirst(std::shared_ptr<Street> streetToSearch, int depthRemaining, 
	std::shared_ptr<Intersection> currentIntersection) const {
	if (streetToSearch == nullptr) {return -1;}
	if (depthRemaining < 0) {return 0;}
	depthRemaining = depthRemaining - 1;
	std::shared_ptr<Intersection> otherIntersection = streetToSearch->getOtherIntersection(currentIntersection);
	return streetToSearch->getRemainingFoodOnStreet() + std::max({SearchDepthFirst(otherIntersection->getLeftStreet(),depthRemaining,otherIntersection),
		SearchDepthFirst(otherIntersection->getRightStreet(),depthRemaining,otherIntersection),
		SearchDepthFirst(otherIntersection->getUpStreet(),depthRemaining,otherIntersection),
		SearchDepthFirst(otherIntersection->getDownStreet(),depthRemaining,otherIntersection)});
}

int FollowMaximumFoodAutomatedController::FindIndexOfNewDirection(std::array<int,4> availableFood) const {
	std::vector<int> indexOfMaximumElement = FindIndexOfMaximumElements(availableFood);
	if (indexOfMaximumElement.size() == 1) {return indexOfMaximumElement.at(0);}
	return BreakTiesRandomly(indexOfMaximumElement);
}

int FollowMaximumFoodAutomatedController::BreakTiesRandomly(std::vector<int> indexOfMaximumElement) const {
	std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<int> distr(0, indexOfMaximumElement.size()-1);
    int indexOfNewDirection = distr(eng);
    return indexOfMaximumElement.at(indexOfNewDirection);
}

std::vector<int> FollowMaximumFoodAutomatedController::FindIndexOfMaximumElements(std::array<int,4> availableFood) const{
	std::vector<int> indexOfMaximumElement;
	int currentMaximum;
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