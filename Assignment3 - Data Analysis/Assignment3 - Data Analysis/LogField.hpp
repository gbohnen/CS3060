//
//  LogField.hpp
//  tconley-hw3
//
//  Created by Thomas Alan Conley on 10/6/16.
//  Copyright © 2016 Thomas Alan Conley. All rights reserved.
//

#ifndef LogField_hpp
#define LogField_hpp
#include <string>
class LogField
{
protected:
    std::string str;
public:
    LogField(const std::string s);
    virtual const std::string toString() const;
};
#endif /* LogField_hpp */
