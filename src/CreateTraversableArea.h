//
// Created by dansid on 4/1/20.
//

#ifndef SDL2TEST_CREATETRAVERSABLEAREA_H
#define SDL2TEST_CREATETRAVERSABLEAREA_H

#include <iostream>
#include <memory>
#include <vector>
#include "Intersection.h"
#include "Street.h"

void CreateTraffic(std::vector<std::shared_ptr<Intersection>> &intersections, std::vector<std::shared_ptr<Street>> &streets);

#endif //SDL2TEST_CREATETRAVERSABLEAREA_H
