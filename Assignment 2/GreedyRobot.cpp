#include "GreedyRobot.h"
#include <cstdlib> 


GreedyRobot::GreedyRobot(int x1, int y1, int x2, int y2, int maxD) : MAX_STEP(maxD)
{
	if (x1 == x2 && y1 == y2) //checks to see if already on treasure
		std::cout << "You are already found the Treasure!" << endl;
	else
		std::cout << "Number of Paths: " << this->count(x1, y1, x2, y2, "", 0, 0) << endl; //calls the recursive function
}

/*
The count method is a recrusive function that takes in 7 values
XR = x coordinate for robot
YR = y coordinate for robot
XT = x coordinate for treasure
YT = y coordinate for treasure
path = the path that robot follows
hStep = number of steps taken horizontally
vStep = number of steps taken vertically
*/
int GreedyRobot::count(int XR, int YR, const int XT, const int YT, string path, int hStep, int vStep)
{
	if (XR == XT && YR == YT) { //if treasure is found 
		std::cout << path << endl; //print the path to treasure
		return 1; //return 1
	}
	int xDir = XT - XR; // horizontal distance needed to travel
	int yDir = YT - YR; // vertical distance needed to travel
	int retVal = 0; //total return value
	
	if (xDir > 0 && hStep < MAX_STEP) //stops calling function if max step reached
	{
		int tempH = hStep; 
		int tempV = vStep;

		string tempPath = string(path); //deep copy of string path

		tempH += 1; //a vertical step was taken
		tempV = 0; //resets the horizontal step
		tempPath += "E"; //adds to the path

		retVal += this->count((XR + 1), YR, XT, YT, tempPath, tempH, tempV); //recursive call and one added to XR

	}
	
	if (xDir < 0 && hStep < MAX_STEP)
	{
		int tempH = hStep;
		int tempV = vStep;
		string tempPath = string(path);
		tempH += 1;
		tempV = 0;
		tempPath += "W";
		retVal += this->count((XR - 1), YR, XT, YT, tempPath, tempH, tempV);
	}

	if (yDir > 0 && vStep < MAX_STEP)
	{
		int tempH = hStep;
		int tempV = vStep;
		string tempPath = string(path);
		tempV += 1;
		tempH = 0;
		tempPath += "N";
		retVal += this->count(XR, (YR + 1), XT, YT, tempPath, tempH, tempV);
	}
	
	if (yDir < 0 && vStep < MAX_STEP)
	{
		int tempH = hStep;
		int tempV = vStep;
		string tempPath = string(path);
		tempV += 1;
		tempH = 0;
		tempPath += "S";
		retVal += this->count(XR, (YR - 1), XT, YT, tempPath, tempH, tempV);
	}
	return retVal; //returns the final return value
}



GreedyRobot::~GreedyRobot()
{
	//nothing is initilized so no need for a destrocter
}



int main(int argc, char* argv[]) { //takes in arguements 
	if (argc > 5) //if argument size not right, calls predefined tests
	{
		std::cout << "(" << atoi(argv[1]) << ", " << atoi(argv[2]) << ") -> (" << atoi(argv[3]) << ", " << atoi(argv[4]) << ") with " << atoi(argv[5]) << " max steps" <<endl;
		GreedyRobot testBot = GreedyRobot(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), atoi(argv[5])); //starts the program
	}
	else
	{
		std::cout << "If you have reached this part, you inputted wrong number of paramters for constructor. Or ur in windows (shame)" << endl;
		std::cout << "Pre-Defined test that I have made." << endl;


		std::cout << "\nTesting going up by 4, limit of 2 steps max" << endl;
		GreedyRobot test = GreedyRobot(3, 3, 3, 7, 2);
		std::cout << "Should be 0" << endl;


		std::cout << "\nTesting (1,2) -> (3,5) with 2 steps" << endl;
		GreedyRobot test2 = GreedyRobot(1, 2, 3, 5, 2);
		std::cout << "Should be 7" << endl;

		std::cout << "\nTesting (-1,-1) -> (1,1) with 1 step" << endl;
		GreedyRobot test3 = GreedyRobot(-1, -1, 1, 1, 1);
		std::cout << "Should be 2" << endl;

		std::cout << "\nTesting (1,1) -> (-1,-1) with 1 step" << endl;
		GreedyRobot test4 = GreedyRobot(1, 1, -1, -1, 1);
		std::cout << "Should be 2" << endl;

		std::cout << "\nTesting (1,1) -> (-1,-1) with 2 step" << endl;
		GreedyRobot test5 = GreedyRobot(1, 1, -1, -1, 2);
		std::cout << "Should be 6" << endl;

		std::cout << "\nTesting (1,1) -> (1, 5) with 2 steps" << endl;
		GreedyRobot test6 = GreedyRobot(1, 1, 1, 5, 2);
		std::cout << "should be 0" << endl;
	}

}

