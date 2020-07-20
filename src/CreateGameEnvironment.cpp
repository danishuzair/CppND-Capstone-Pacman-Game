
#include "CreateGameEnvironment.h"
void initializeGhosts(std::vector<std::shared_ptr<Ghost>> &ghosts, int numberOfGhosts, std::vector<std::shared_ptr<Street>> &streets){
	std::array<Color, 4> ghostColor {Color::red, Color::pink, Color::cyan, Color::orange};
    std::array<int, 4> ghostStreetIndex{32,36,36,36};
    std::array<Direction, 4> ghostDirection{Direction::left, Direction::up,
        Direction::up, Direction::up};
    std::array<int, 4> ghostStartDelay{0, 120, 240, 360};
    numberOfGhosts = numberOfGhosts <= 4 ? numberOfGhosts : 4;
    for (int i=0; i<numberOfGhosts; i++) {
        ghosts.push_back(std::make_shared<Ghost>(ghostColor[i],streets.at(ghostStreetIndex[i]),
            ghostDirection[i],ghostStartDelay[i]));
    }
}