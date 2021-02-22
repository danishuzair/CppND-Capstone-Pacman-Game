#include "ScreenShot.h"

ScreenShot::ScreenShot(int x, int y, int width, int height):
        x(x),
        y(y),
        width(width),
        height(height)
    {
        display = XOpenDisplay(nullptr);
        root = DefaultRootWindow(display);
        time_t theTime = time(NULL);
		struct tm *aTime = localtime(&theTime);
		int day = aTime->tm_mday;
		int month = aTime->tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
		int year = aTime->tm_year + 1900; // Year is # years since 1900
		if (month < 10) {datelocation = std::to_string(0) + std::to_string(month);}
		else {datelocation = std::to_string(month);}
		if (day < 10) {datelocation = datelocation + std::to_string(0) + std::to_string(day);}
		else {datelocation = datelocation + std::to_string(day);}
		datelocation = datelocation + std::to_string(year);
		mkdir((storagelocation+datelocation).c_str(), 0777);
		for (const auto & entry : std::filesystem::directory_iterator(storagelocation+datelocation)) {
			run_num = (std::stoi(entry.path().filename()) >= run_num) ? std::stoi(entry.path().filename()) + 1 : run_num;
		}
    }

void ScreenShot::getImage()
    {
        if(img != nullptr)
            XDestroyImage(img);
        img = XGetImage(display, root, x, y, width, height, AllPlanes, ZPixmap);
        cvImg = cv::Mat(height, width, CV_8UC4, img->data);
    }

ScreenShot::~ScreenShot()
    {
        if(img != nullptr)
            XDestroyImage(img);
        XCloseDisplay(display);
    }

void ScreenShot::updateRun() {
	runlocation = "/" + std::to_string(run_num);
	++run_num;
	storageindex_left = 0;
    storageindex_right = 0;
    storageindex_up = 0;
    storageindex_down = 0;
	mkdir((storagelocation+datelocation+runlocation).c_str(), 0777);
}

void ScreenShot::setStorageIndex(std::string action) {
	if (action.compare(0,action.size(),"right") == 0) {
		storageindex = storageindex_right;
		++storageindex_right;
	}
	else if (action.compare(0,action.size(),"left") == 0) {
		storageindex = storageindex_left;
		++storageindex_left;
	}
	else if (action.compare(0,action.size(),"up") == 0) {
		storageindex = storageindex_up;
		++storageindex_up;
	}
	else {
		storageindex = storageindex_down;
		++storageindex_down;
	}
}

void ScreenShot::captureImage(std::string action) {
	this->getImage();
	this->setStorageIndex(action);
	cv::imwrite(storagelocation+datelocation+runlocation+"/"+action+"_"+std::to_string(storageindex)+".jpg", cvImg);
	++storageindex;
}

void ScreenShot::writeReward(int reward) {
	std::string locationreward = storagelocation+datelocation+runlocation+"/"+std::to_string(reward)+".txt";
	std::ofstream o(locationreward.c_str());
	o<<reward<<std::endl;
}