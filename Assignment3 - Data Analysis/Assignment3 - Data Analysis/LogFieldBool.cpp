#include "LogFieldBool.h"

LogFieldBool::LogFieldBool(const std::string s) : LogField(s)
{

}

const std::string LogFieldBool::toString() const
{
	return "Bool: " + str;
}