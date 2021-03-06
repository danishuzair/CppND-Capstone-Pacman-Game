
#ifndef FOLLOWMAXIMUMFOODAUTOMATEDCONTROLLER_H
#define FOLLOWMAXIMUMFOODAUTOMATEDCONTROLLER_H

#include "SDL.h"
#include "Pacman.h"
#include "Controller.h"
#include "memory"
#include "TrafficObject.h"
#include "Street.h"
#include "Ghost.h"
#include "Intersection.h"
#include <algorithm>
#include <array>
#include <random>

class FollowMaximumFoodAutomatedController : public Controller {
 public:
 	void GetNewInput(bool &running, Pacman &pacman);
 	void attachGhosts(std::vector<std::shared_ptr<Ghost>> ghosts_in);
 private:
 	Direction GetUpdatedDirectionForMaximumFood(std::shared_ptr<Intersection> currentIntersection, int indexOfCurrentDirection);
 	Direction GetUpdatedDirectionForGhostFound(std::shared_ptr<Street> currentStreet, int indexOfCurrentDirection, int xPacmanCurrentLocation, int yPacmanCurrentLocation) const;
 	double SearchDepthFirst(std::shared_ptr<Street> streetToSearch, int depthRemaining, 
		std::shared_ptr<Intersection> currentIntersection, int previousStreetLength) const;
 	int FindIndexOfNewDirection(std::array<double,4> availableFood, int indexOfCurrentDirection) const;
 	Direction GetDirectionFromIndex(int indexOfNewDirection) const;
 	std::vector<int> FindIndexOfMaximumElements(std::array<double,4> availableFood) const;
 	int BreakTiesRandomly(std::vector<int> indexOfMaximumElement, int indexOfCurrentDirection) const;
 	int searchDepth = 3;
 	int GetIndexFromDirection (Direction currentDirection) const;
 	Direction switchDirection(Direction currentDirection) const;
};

#endif // followmaximumfoodautomatedcontroller