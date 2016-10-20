#ifndef Port_hpp
#define Port_hpp

#include "LogField.hpp"

class LogFieldPort : public LogField
{
public:
	LogFieldPort(const std::string s);

	virtual const std::string toString() const;
};

#endif