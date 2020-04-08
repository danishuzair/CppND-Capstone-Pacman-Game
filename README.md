# CPPND: Capstone Pacman Game

This is the Capstone project for Udacity's C++ nano-degree. In this project, a version of the PacMan game was created. This project borrowed code from the Snake example game that was provided.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./PacMan`.

## Expected Behavior of the Game

When the program is run, there will be a game window along with a Pacman, and 4 Ghosts. The objective is for Pacman to collect all the food to win the game without losing his three lives.

On the top of the program the current score and available lives of the Pacman can be seen. Pacman has a total of three available lives, and for each food collected, Pacman receives 10 points.

The game is ended under two situations. One situation is if Pacman loses all his life, in which case a message will be displayed at the top stating "You lost! Please try again".

The other situation is when Pacman collects all the food, in which case a message will be displayed at the top stating "Congratulations! You won!".

To navigate Pacman along the maze, the left, right, up, and down keys can be used. It should be noted that Pacman will only change direction if the key is pressed a sufficiently close distance to an intersection.

In addition, the Ghosts move randomly. At each intersection, they randomly decide what action to take.

## Rubric Points

Criteria: The project uses Object Oriented Programming techniques.
Specification met via: There are multiple classes in the project, including Ghost, Intersection, Pacman, Street, and TrafficObject.

Criteria: Classes use appropriate access specifiers for class members.
Specification met via: Each of the above listed class has private and public methods.

Criteria: Class constructors utilize member initialization lists.
Specification met via: The following classes use initialization lists: Ghost, Pacman, Street

Criteria: Classes follow an appropriate inheritance hierarchy.
Specification met via: In almost all cases, composition was used in this project. The only situation in which inheritance was used was in the case of the TrafficObject base class, which has two child classes, Intersection & Street.

Criteria: The project makes use of references in function declarations.
Specification met via: The following classes use a reference to Intersection & Street objects: Ghost, Pacman

Criteria: The project uses smart pointers instead of raw pointers.
Specification met via: The Intersection & Street class instances were defined used smart pointers.

## Resources

pacman background image: https://wallpapersafari.com/w/SLJTV0
https://yangcha.github.io/iview/iview.html
