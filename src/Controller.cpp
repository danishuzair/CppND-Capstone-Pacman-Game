//
// Created by dansid on 4/1/20.
//

#include "Controller.h"

void Controller::attachGhosts(std::vector<std::shared_ptr<Ghost>> ghosts_in) {
	for (auto ghost : ghosts_in) {
		ghosts.push_back(ghost);
	}
}