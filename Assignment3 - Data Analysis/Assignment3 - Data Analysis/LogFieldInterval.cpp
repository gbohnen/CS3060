#include "LogFieldInterval.h"

LogFieldInterval::LogFieldInterval(const std::string s) : LogField(s)
{

}

const std::string LogFieldInterval::toString() const
{
	return "Interval: " + str;
}