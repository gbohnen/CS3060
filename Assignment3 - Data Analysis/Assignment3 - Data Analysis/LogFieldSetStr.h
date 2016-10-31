#ifndef SetStr_hpp
#define SetStr_hpp

#include "LogField.hpp"

class LogFieldSetStr : public LogField
{
public:
	LogFieldSetStr(const std::string s);

	virtual const std::string toString() const;
};

#endif SetStr_hpp
