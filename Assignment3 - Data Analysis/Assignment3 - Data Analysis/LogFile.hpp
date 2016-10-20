//
//  LogFile.hpp
//  tconley-hw3
//
//  Created by Thomas Alan Conley on 10/6/16.
//  Copyright © 2016 Thomas Alan Conley. All rights reserved.
//

#ifndef LogFile_hpp
#define LogFile_hpp
#include <string>
#include <vector>
#include "LogRecord.hpp"

typedef std::vector<const LogRecord*> records_t;
class LogFile
{
    records_t records;
public:
    ~LogFile();
    void Add(const LogRecord* lr);
    void Add(const std::string & line);
    void Display(std::ostream & out);
};

#endif /* LogFile_hpp */
