#include "TimeSpan.h"
#include <ostream>
#include <math.h>
#include <cstdlib>

/*
 * Author: Behnam Khabazan
 * Class: TimeSpan: A class which reperesents time. It has 3 private variables, hours, minutes, seconds. 
 */
using namespace std;

TimeSpan::TimeSpan()
{
}

TimeSpan::TimeSpan(double hours, double minutes, double seconds)
{
	setTime(hours, minutes, seconds);
}

TimeSpan::TimeSpan(double minutes, double seconds)
{
	setTime(0, minutes, seconds);
}

TimeSpan::TimeSpan(double seconds)
{
	setTime(0, 0, seconds);
}


TimeSpan::~TimeSpan()
{
	hour = 0;
	minute = 0;
	second = 0;
}

int TimeSpan::getHours() const
{
	return this->hour;
}

int TimeSpan::getMinutes() const
{
	return this->minute;
}

int TimeSpan::getSeconds() const
{
	return this->second;
}

//sets time using seconds (moves up from seconds to minutes and to hours)
void TimeSpan::convertTime(int seconds)
{
	
	this->second = seconds;

	this->minute = (int)(this->second / 60); //using seconds to make minutes
	this->second -= ((int)(this->second / 60) * 60); //manual mod functions
	this->hour = (int)(this->minute / 60); //using minutes to make hours
	this->minute -= ((int)(this->minute / 60) * 60); //manual mod function


}

// initilizes everything to 0 then turns everything to seconds and calls converter
bool TimeSpan::setTime(double hours, double minutes, double seconds)
{
	this->second = 0;
	this->minute = 0;
	this->hour = 0;

	int tempSeconds = round(seconds);
	tempSeconds += round(minutes * 60);
	tempSeconds += round(hours * 3600);
	this->convertTime(tempSeconds);
	return true;
}

//overloading + (takes in reference to save space, returns a new time with both added)
TimeSpan TimeSpan::operator+(const TimeSpan& other) const
{
	int tempHours = this->hour + other.getHours();
	int tempMinutes = this->minute + other.getMinutes();
	int tempSeconds = this->second + other.getSeconds();

	TimeSpan retVal = TimeSpan(tempHours, tempMinutes, tempSeconds);
	return retVal;
}
//overloading - (takes in reference to save space, returns a new time with both added)

TimeSpan TimeSpan::operator-(const TimeSpan& other) const
{
	int tempHours = this->hour - other.getHours();
	int tempMinutes = this->minute - other.getMinutes();
	int tempSeconds = this->second - other.getSeconds();

	TimeSpan retVal = TimeSpan(tempHours, tempMinutes, tempSeconds);
	return retVal;
}

TimeSpan TimeSpan::operator-()
{
	TimeSpan retVal = TimeSpan(-this->getHours(), -this->getMinutes(), -this->getSeconds());//everything negative
	return retVal;
}


bool TimeSpan::operator==(const TimeSpan& other) const
{
	return ((this->second == other.getSeconds()) && (this->minute == other.getMinutes()) && (this->hour == other.getHours()));
}

bool TimeSpan::operator!=(const TimeSpan& other) const
{
	return((this->second != other.getSeconds()) || (this->minute != other.getMinutes()) || (this->hour != other.getHours()));
}

TimeSpan& TimeSpan::operator+=(const TimeSpan other)
{
	int tempHours = this->hour + other.getHours();
	int tempMinutes = this->minute + other.getMinutes();
	int tempSeconds = this->second + other.getSeconds();

	this->setTime(tempHours, tempMinutes, tempSeconds);
	return *this;
}

TimeSpan& TimeSpan::operator-=(const TimeSpan other)
{
	int tempHours = this->hour - other.getHours();
	int tempMinutes = this->minute - other.getMinutes();
	int tempSeconds = this->second - other.getSeconds();

	this->setTime(tempHours, tempMinutes, tempSeconds);
	return *this;
}

ostream& operator <<(ostream& outStream, const TimeSpan& time)
{
	outStream << "Hours: " << time.getHours() << ", Minutes: " << time.getMinutes() << ", Seconds: " << time.getSeconds() << endl;
	return outStream;
}
istream& operator>>(istream& inStream, TimeSpan& time)
{
	double tempHour, tempMinute, tempSecond = 0;
	inStream >> tempHour >> tempMinute >> tempSecond; //takes in 3 values for hour minute and second
	time.setTime(tempHour, tempMinute, tempSecond); //calls set time function
	return inStream;
}





