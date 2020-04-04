#pragma once
#include <iostream>
using namespace std;

class TimeSpan
{
public:
	TimeSpan();
	TimeSpan(double hours, double minutes, double seconds); //should they be const reference?
	TimeSpan(double minutes, double seconds);
	TimeSpan(double seconds);
	~TimeSpan();
	int getHours() const;
	int getMinutes() const;
	int getSeconds() const;
	bool setTime(double hours, double minutes, double seconds);
	friend ostream& operator<<(ostream& outStream, const TimeSpan& time);
	friend istream& operator>>(istream& inStream, TimeSpan& time);
	TimeSpan operator+(const TimeSpan& other) const;
	TimeSpan operator-(const TimeSpan& other) const;
	TimeSpan operator-();
	bool operator==(const TimeSpan& other) const;
	bool operator!=(const TimeSpan& other) const;
	TimeSpan& operator+=(const TimeSpan other);
	TimeSpan& operator-=(const TimeSpan other);




private:
	int hour = 0;
	int minute = 0;
	int second = 0;
	void convertTime(int seconds);
};

