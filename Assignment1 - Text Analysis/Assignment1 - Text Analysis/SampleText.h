#ifndef SAMPLETEXT_H
#define SAMPLETEXT_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include "Word.h"
#include "PartOfSpeech.h"

using namespace std;

class SampleText
{
public:
	// default constructor
	SampleText();

	// analyzes the files
	void Analyze(ifstream& file, PartOfSpeech& dictionary);

	// returns various metrics
	Word GetLongestWord();
	Word GetShortestWord();
	void DisplayPOSCounts();	

private:
	// checks for longest word
	void CheckLongestWord(Word& str);
	void CheckShortestWord(Word& str);
	void UpdateCounts(Word& str);

protected:
	string line;																				// the current line
	Word longestWord = Word("");																// the longest word found
	Word shortestWord = Word("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");		// the shortest word found
	vector<Word> words;																			// vector array that will hold all the words from the text document

	int nounCount = 0;
	int verbCount = 0;
	int adjCount = 0;
	int advCount = 0;
	int prepCount = 0;
	int unknCount = 0;
};

#endif