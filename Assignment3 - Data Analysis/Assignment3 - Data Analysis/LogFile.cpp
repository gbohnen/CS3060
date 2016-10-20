//
//  LogFile.cpp
//  tconley-hw3
//
//  Created by Thomas Alan Conley on 10/6/16.
//  Copyright © 2016 Thomas Alan Conley. All rights reserved.
//

#include "LogFile.hpp"

LogFile::~LogFile()
{
    // I'm responsible for deleting records
    //                   -- LogFile
    for(const LogRecord *lr : records)
    {
        delete lr;
    }
}
void LogFile::Add(const LogRecord* lr)
{
    records.push_back(lr);
    
}
void LogFile::Add(const std::string & line)
{
    records.push_back(new LogRecord(line));
}

void LogFile::Display(std::ostream & out)
{
    for(const LogRecord *lr : records)
    {
        out << lr->toString() << std::endl;
    }
    out << records.size() << " total records." << std::endl;
}
