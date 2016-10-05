#include "gsb_string.h"
#include <string>

using namespace gsb;

// default constructor, exists for stub purposes only
string::string() {}

// default destructor
string::~string()
{
	delete[] data;
	data = nullptr;
}

// constructor, accepts a char pointer parameter
string::string(const char* d)
{
	length = strlen(d) + 1;
	data = new char[length];
	for (int i = 0; i < length - 1; i++)
	{
		data[i] = d[i];
	}
}

// copy constructor
string::string(string& str)
{
	length = str.length + 1;
	data = new char[length];
	for (int i = 0; i < length - 1; i++)
	{
		data[i] = str[i];
	}
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
int string::Length()
{
	return length - 1;
}

void string::InitData(const char* d)
{

}

void string::FreeData()
{

}