#include "gsb_string.h"

using namespace gsb;

// default constructor
string::string()
{

}

// default destructor
string::~string()
{

}

// constructor, accepts a char pointer parameter
string::string(const char* d)
{
	InitData(d);
}

// copy constructor
string::string(string& str)
{

}

// basic assignment operator
string& string::operator=(char* d)
{

}

// assignment operator, functions as copy constructor
string& string::operator=(const string& str)
{

}

// convert object to string
const char* string::ToString() const
{

}

// casting operators?
string::operator const char*() const
{

}

// length of the string
int string::length()
{

}

void string::InitData(const char* d)
{

}

void string::FreeData()
{

}