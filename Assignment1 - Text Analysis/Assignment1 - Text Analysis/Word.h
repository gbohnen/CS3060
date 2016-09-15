#ifndef WORD_H
#define WORD_H

#include <string>
#include <cctype>

using namespace std;

class Word
{
public:
	// default constructor
	Word(string str);

	// accessor methods
	string Text();
	int Syllables();
	string PartOfSpeech();

	// set the part of speech
	string SetPOS(const string& key);

private:
	// get the number of syllables in a given word
	int GetSyllables();

	// check if a character is a vowel
	bool IsVowel(const char c);

	// check if a character is a consonant
	bool IsConsonant(const char c);

	// converts all characters in a given string to lowercase
	void ToLower();

protected:
	string word;
	int syllables;
	string partOfSpeech;
};

#endif