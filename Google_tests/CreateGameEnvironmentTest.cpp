
#include "CreateGameEnvironmentTest.h"
#include "../src/Ghost.h"

TEST_F(CreateGameEnvironmentTest, InitializeGhostsTest) {
	int numberOfGhost = 0;
	std::vector<std::shared_ptr<Ghost>> ghosts;
	std::vector<std::shared_ptr<Intersection>> intersections;
    std::vector<std::shared_ptr<Street>> streets;
    CreateTraffic(intersections, streets);
	initializeGhosts(ghosts,numberOfGhost,streets);
	EXPECT_EQ(numberOfGhost,ghosts.size());
	numberOfGhost = 2;
	ghosts.clear();
	initializeGhosts(ghosts,numberOfGhost,streets);
	EXPECT_EQ(numberOfGhost,ghosts.size());
	numberOfGhost = 4;
	ghosts.clear();
	initializeGhosts(ghosts,numberOfGhost,streets);
	EXPECT_EQ(numberOfGhost,ghosts.size());
	numberOfGhost = 4;
	ghosts.clear();
	initializeGhosts(ghosts,numberOfGhost,streets);
	EXPECT_EQ(numberOfGhost,ghosts.size());
	numberOfGhost = 5;
	ghosts.clear();
	initializeGhosts(ghosts,numberOfGhost,streets);
	EXPECT_EQ(4, ghosts.size());
}