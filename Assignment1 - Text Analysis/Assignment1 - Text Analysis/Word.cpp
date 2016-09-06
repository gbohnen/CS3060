#include "Word.h"

using namespace std;

// default constructor
Word::Word(string str) : word{ str }
{
	syllables = GetSyllables();
	partOfSpeech = GetPOS();
};

// accessor methods
string Word::Text()
{
	return word;
};
int Word::Syllables()
{
	return syllables;
};
string Word::PartOfSpeech()
{
	return partOfSpeech;
};

// find the number of syllables
int Word::GetSyllables()
{

	return 0;
};

// find the part of speech
string Word::GetPOS()
{

	return NULL;
};