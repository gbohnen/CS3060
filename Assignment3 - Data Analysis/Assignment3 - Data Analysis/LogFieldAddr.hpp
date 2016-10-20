//
//  IP.hpp
//  tconley-hw3
//
//  Created by Thomas Alan Conley on 10/6/16.
//  Copyright © 2016 Thomas Alan Conley. All rights reserved.
//

#ifndef IP_hpp
#define IP_hpp
#include "LogField.hpp"

class LogFieldAddr : public LogField
{
public:
    LogFieldAddr(const std::string s);
    virtual const std::string toString() const;
};

#endif /* IP_hpp */
