#ifndef Bool_hpp
#define Bool_hpp

#include "LogField.hpp"

class LogFieldBool : public LogField
{
public:
	LogFieldBool(const std::string);

	virtual const std::string toString() const;
};



#endif
