project(Pacman_lib)

set(HEADER_FILES
        Controller.h
        CreateTraversableArea.h
        Game.h
        Ghost.h
        Intersection.h
        Pacman.h
        Renderer.h
        Street.h
        CreateGameEnvironment.h
        ManualController.h
        FollowMaximumFoodAutomatedController.h
        ScreenShot.h
        )

set(SOURCE_FILES
        Controller.cpp
        CreateTraversableArea.cpp
        Game.cpp
        Ghost.cpp
        Intersection.cpp
        Pacman.cpp
        Renderer.cpp
        Street.cpp
        CreateGameEnvironment.cpp
        ManualController.cpp
        FollowMaximumFoodAutomatedController.cpp
        ScreenShot.cpp
        )

add_library(Pacman_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} src)
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)

target_link_libraries(Pacman_lib ${SDL2_LIBRARIES} stdc++fs)