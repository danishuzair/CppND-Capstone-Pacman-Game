//
// Created by dansid on 4/27/20.
//

#ifndef SDL2TEST_INTERSECTIONTEST_H
#define SDL2TEST_INTERSECTIONTEST_H

#include <gtest/gtest.h>
#include <../src/Intersection.h>
#include "../src/Street.h"

class IntersectionTest : public testing::Test  {
protected:
    virtual void SetUp() {intersection = std::make_shared<Intersection>();}
    std::shared_ptr<Intersection> intersection;
};

#endif //SDL2TEST_INTERSECTIONTEST_H
