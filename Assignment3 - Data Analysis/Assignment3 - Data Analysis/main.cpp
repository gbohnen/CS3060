//
//  main.cpp
//  tconley-hw3
//
//  Created by Thomas Alan Conley on 10/6/16.
//  Copyright © 2016 Thomas Alan Conley. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "LogFile.hpp"

#include "LogFieldAddr.hpp"
#include "LogFieldTime.hpp"

int main(int argc, const char * argv[])
{
    std::ifstream ifs("conn.100000.log");
    
    // empty log file object
    LogFile lf;

    std::string line;
    while ( std::getline(ifs,line) )
    {
        // skip lines that begin with a #
        // these lines are the header lines
        // that describe the log file
        if ( (*line.begin()) != '#' )
        {
            lf.Add(line);
        }
    }
    lf.Display(std::cout); 
    return 0;
}
