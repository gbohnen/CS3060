#ifndef PARTOFSPEECH_H
#define PARTOFSPEECH_H

#include <utility>
#include <string>
#include <map>

using namespace std;

class PartOfSpeech
{
public:
	// default constructor
	PartOfSpeech(const ifstream& file);

private:
	string GetValue(const string& key);

protected:
	map<string, string> dictionary;
};

#endif