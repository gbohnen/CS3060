#include "LogFieldSetStr.h"

LogFieldSetStr::LogFieldSetStr(const std::string s) : LogField(s)
{

}

const std::string LogFieldSetStr::toString() const
{
	return "Set: " + str;
}