//
// Created by dansid on 5/12/20.
//

#ifndef PACMAN_STREETTEST_H
#define PACMAN_STREETTEST_H

#include <gtest/gtest.h>
#include <../src/Intersection.h>
#include "../src/Street.h"
#include "../src/Pacman.h"

class StreetTest : public testing::Test  {
protected:
	virtual void SetUp() {street = std::make_shared<Street>();}
    std::shared_ptr<Street> street;
};


#endif //PACMAN_STREETTEST_H
