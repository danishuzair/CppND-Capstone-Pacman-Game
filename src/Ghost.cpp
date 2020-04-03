//
// Created by dansid on 4/1/20.
//

#include "Ghost.h"

Ghost::Ghost(Color colorin):color(colorin) {
    switch(color) {
        case(Color::red):
            location.x = 252;
            location.y = 221;
            break;
        case(Color::pink):
            location.x = 246;
            location.y = 278;
            break;
        case(Color::cyan):
            location.x = 222;
            location.y = 278;
            break;
        case(Color::orange):
            location.x = 275;
            location.y = 278;
            break;
        default:
            std::cerr<<"Invalid color received\n";
            break;
    }
}
