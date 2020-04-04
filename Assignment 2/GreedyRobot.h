#pragma once
#include <iostream>
using namespace std;
class GreedyRobot
{
public:
	GreedyRobot(int x1, int y1, int x2, int y2, int maxStep);
	int count(int XR, int YR, const int XT, const int YT, string path, int hStep, int vStep);
	~GreedyRobot();
private:
	const int MAX_STEP;
};

