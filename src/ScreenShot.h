#include <opencv2/opencv.hpp>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "string.h"
#include <time.h>
#include <filesystem>
#include <iostream>
#include <fstream>

class ScreenShot
{
private:
    Display* display;
    Window root;
    int x,y,width,height;
    XImage* img{nullptr};
    std::string storagelocation = "/home/danish/Desktop/CodingProjects/Pacman_Data/";
    std::string datelocation, runlocation;
    int run_num = 0;
    int storageindex_left;
    int storageindex_right;
    int storageindex_up;
    int storageindex_down;
    int storageindex;
    cv::Mat cvImg;
    void setStorageIndex(std::string action);
public:
    ScreenShot(int x, int y, int width, int height);
    void getImage();
    void updateRun();
    void captureImage(std::string action);
    ~ScreenShot();
    void writeReward(int reward);
};