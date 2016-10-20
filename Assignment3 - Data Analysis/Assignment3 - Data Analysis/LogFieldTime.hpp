//
//  Time.hpp
//  tconley-hw3
//
//  Created by Thomas Alan Conley on 10/6/16.
//  Copyright © 2016 Thomas Alan Conley. All rights reserved.
//

#ifndef Time_hpp
#define Time_hpp
#include "LogField.hpp"

class LogFieldTime : public LogField
{
public:
    LogFieldTime(const std::string s);

    virtual const std::string toString() const;
};
#endif /* Time_hpp */
