#include <stdio.h>
#include <iostream>
#include <time.h>

using namespace std;

class Greeter
{
public:
	// fields
	tm * currentTime;			// pointer to current time

	// constructor
	Greeter()
	{
		// allocate memory for the currenttime 

		currentTime = new tm();
		*currentTime = GetCurrentTime();
	};

	// destructor
	~Greeter()
	{
		// deallocate memory dedicated to the current time
		delete currentTime;
		cout << currentTime << endl;
		currentTime = NULL;
	}

	// displays a short message that varies with the time of day
	void SayIt()
	{
		if (currentTime->tm_hour < 12)
			cout << "Good morning." << endl;
		else if (currentTime->tm_hour >= 12 && currentTime->tm_hour < 17)
			cout << "Good afternoon." << endl;
		else if (currentTime->tm_hour >= 17)
			cout << "Good evening." << endl;
	};

	tm GetTime()
	{
		return *currentTime;
	};

	// returns the current time
	tm GetCurrentTime()
	{
		// load the system time into our current time struct
		const time_t t = time(0);
#if (defined(WIN32) || defined(_WIN32) || defined(__WIN32__))
		localtime_s(&*currentTime, &t);
#else
		localtime_r(&t, &*currentTime);
#endif

		return *currentTime;
	};

	// sets the current time
	tm SetCurrentTime(int hour, int min, int sec)
	{
		// load the parameters into the time struct
		currentTime->tm_hour = hour;
		currentTime->tm_min = min;
		currentTime->tm_sec = sec;
		return *currentTime;
	}

private:

protected:

};

int main(int argc, char** argv)
{
	// build a greeter and demonstrate functionality
	Greeter * g = new Greeter();
	g->SayIt();
	g->SetCurrentTime(14, 35, 0);
	g->SayIt();

	// destruct the greeter
	delete g;
	g = NULL;

	return 0;
};