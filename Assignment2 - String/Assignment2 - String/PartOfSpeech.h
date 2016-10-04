#ifndef PARTOFSPEECH_H
#define PARTOFSPEECH_H

#include <utility>
#include <string>
#include <map>
#include <iostream>
#include <fstream>

using namespace std;

enum POS { NOUN, VERB, ADJECTIVE, ADVERB, ARTICLE, INTERJECTION, PREPOSITION, UNKNOWN };

class PartOfSpeech
{
public:
	// default constructor
	PartOfSpeech(ifstream& file);

	string GetValue(const string& key);
private:
	string ParsePOS(const string& part);

protected:
	map<string, string> dictionary;
	string line;
};

#endif