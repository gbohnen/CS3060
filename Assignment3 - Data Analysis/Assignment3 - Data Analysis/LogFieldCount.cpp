//
//  LogFieldCount.cpp
//  tconley-hw3
//
//  Created by Thomas Alan Conley on 10/7/16.
//  Copyright © 2016 Thomas Alan Conley. All rights reserved.
//

#include "LogFieldCount.hpp"


LogFieldCount::LogFieldCount(const std::string s) : LogField(s)
{

}

const std::string LogFieldCount::toString() const
{
	return "Count: " + str;
}