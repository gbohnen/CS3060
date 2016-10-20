//
//  LogField.cpp
//  tconley-hw3
//
//  Created by Thomas Alan Conley on 10/6/16.
//  Copyright © 2016 Thomas Alan Conley. All rights reserved.
//

#include "LogField.hpp"

LogField::LogField(const std::string s) : str(s)
{
}
const std::string LogField::toString() const
{
    return "Field:" + str;
}
