#include "LogFieldPort.h"

LogFieldPort::LogFieldPort(const std::string s) : LogField(s)
{
}

const std::string LogFieldPort::toString() const
{
	// prepend the out put to distinguish
	return "Port: " + str;
}