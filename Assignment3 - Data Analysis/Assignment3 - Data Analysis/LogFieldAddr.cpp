//
//  IP.cpp
//  tconley-hw3
//
//  Created by Thomas Alan Conley on 10/6/16.
//  Copyright © 2016 Thomas Alan Conley. All rights reserved.
//

#include "LogFieldAddr.hpp"

LogFieldAddr::LogFieldAddr(const std::string s) : LogField(s)
{
}

const std::string LogFieldAddr::toString() const
{
    // here I only prepend the output
    // to show that the derived function
    // is indeed being called
    return "IP:" + str;
}
