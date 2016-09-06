#ifndef WORD_H
#define WORD_H

#include <string>

using namespace std;

class Word
{
public:
	// default constructor
	Word(string str, int syll, string pos) : word{ str }, syllables { syll }, partOfSpeech{ pos };

	// accessor methods
	string Text();
	int Syllables();
	string PartOfSpeech();

private:
	// find the number of syllables
	int GetSyllables();

	// find the part of speech
	string GetPOS();

protected:
	string word;
	int syllables;
	string partOfSpeech;
};

#endif