#ifndef SAMPLETEXT_H
#define SAMPLETEXT_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include "Word.h"

using namespace std;

class SampleText
{
public:
	// default constructor
	SampleText(ifstream& file);

	// returns the longest word found
	Word GetLongestWord();

	// checks for longest word
	void CheckLongestWord(Word str);

private:

protected:
	string line;					// the current line
	Word longestWord = Word("");		// the longest word found
	vector<Word> words;			// vector array that will hold all the words from the text document

};

#endif