
#ifndef CREATEGAMEENVIRONMENT_H
#define CREATEGAMEENVIRONMENT_H
#include "Ghost.h"
#include <vector>

void initializeGhosts(std::vector<std::shared_ptr<Ghost>> &ghosts, int numberOfGhosts, std::vector<std::shared_ptr<Street>> &streets);

#endif //CREATEGAMEENVIRONMENT_H