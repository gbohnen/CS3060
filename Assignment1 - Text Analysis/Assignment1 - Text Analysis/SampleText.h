#ifndef SAMPLETEXT_H
#define SAMPLETEXT_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

class SampleText
{
public:
	// default constructor
	SampleText(ifstream& file);

	// returns the longest word found
	pair<string, int> GetLongestWord();

	// checks for longest word
	void CheckLongestWord(pair<string, int> str);

private:
	// check if a character is a vowel
	bool IsVowel(const char c);

	// check if a character is a consonant
	bool IsConsonant(const char c);

	// get the number of syllables in a given word
	int GetSyllables(const string& word);

	// converts all characters in a given string to lowercase
	string ToLower(string word);

protected:
	string line;					// the current line
	pair<string, int> longestWord = pair<string, int>("", 0);		// the longest word found
	vector<pair<string, int>> words;			// vector array that will hold all the words from the text document

};

#endif