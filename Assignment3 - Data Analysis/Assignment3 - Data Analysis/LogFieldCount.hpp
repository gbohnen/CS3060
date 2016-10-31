//
//  LogFieldCount.hpp
//  tconley-hw3
//
//  Created by Thomas Alan Conley on 10/7/16.
//  Copyright © 2016 Thomas Alan Conley. All rights reserved.
//

#ifndef LogFieldCount_hpp
#define LogFieldCount_hpp

#include <stdio.h>
#include "LogField.hpp"

class LogFieldCount : public LogField
{
public:
	LogFieldCount(const std::string s);

	virtual const std::string toString() const;
};
#endif /* LogFieldCount_hpp */
