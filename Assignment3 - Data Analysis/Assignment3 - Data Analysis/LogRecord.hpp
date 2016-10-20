//
//  LogRecord.hpp
//  tconley-hw3
//
//  Created by Thomas Alan Conley on 10/6/16.
//  Copyright © 2016 Thomas Alan Conley. All rights reserved.
//

#ifndef LogRecord_hpp
#define LogRecord_hpp
#include "LogField.hpp"
#include <vector>
#include <iostream>
#include <sstream>

// why are we storing pointers instead of objects?
typedef std::vector<const LogField*> fields_t;

class LogRecord
{
    fields_t fields;
public:
    LogRecord(const std::string &);
    ~LogRecord();
    void Add(const LogField* lf);
    virtual const std::string toString() const;
};
#endif /* LogRecord_hpp */
