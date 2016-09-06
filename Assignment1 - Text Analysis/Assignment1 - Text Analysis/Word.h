#ifndef WORD_H
#define WORD_H

#include <string>

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

private:
	// get the number of syllables in a given word
	int GetSyllables();

	// find the part of speech
	string GetPOS();

	// check if a character is a vowel
	bool IsVowel(const char c);

	// check if a character is a consonant
	bool IsConsonant(const char c);

protected:
	string word;
	int syllables;
	string partOfSpeech;
};

#endif