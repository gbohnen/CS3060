#ifndef Interval_hpp
#define Interval_hpp
#include "LogField.hpp"

class LogFieldInterval : public LogField
{
public:
	LogFieldInterval(const std::string s);

	virtual const std::string toString() const;
};

#endif