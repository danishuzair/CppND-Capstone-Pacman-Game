
#ifndef MANUALCONTROLLER_H
#define MANUALCONTROLLER_H

#include "SDL.h"
#include "Pacman.h"
#include "Controller.h"

class ManualController : public Controller {
 public:
 	void GetNewInput(bool &running, Pacman &pacman);
 private:
};

#endif // manualcontroller