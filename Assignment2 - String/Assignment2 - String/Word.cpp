#include "Word.h"
#include "PartOfSpeech.h"

using namespace std;

// default constructor
Word::Word(string str) : word{ str }
{
	syllables = GetSyllables();
	//ToLower();
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

// returns the approximate number of syllables in a word
int Word::GetSyllables()
{
	// count the number of letter type changes
	int count = 1;
	bool characterVowelState = false;

	for (const char& c : word)
	{
		// protect first character case
		if (c == word[0])
		{
			characterVowelState = IsVowel(c);
		}

		// check all subsequent cases
		if (IsVowel(c) != characterVowelState)
		{
			count++;
			characterVowelState = IsVowel(c);
		}
	}

	// return half the number of vowel / consonant switches
	return count / 2;
};

// set the part of speech
string Word::SetPOS(const string& key)
{
	partOfSpeech = key;
	return partOfSpeech;
};

// check if a given character is a vowel
bool Word::IsVowel(const char c)
{
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y' ||
		c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y')
		return true;
	else
		return false;
};

// check if the given character is a consonant
bool Word::IsConsonant(const char c)
{
	return !IsVowel(c);
};

// converts all characters to lowercase - possibly uses too much memory, or leaks. needs debugging
void Word::ToLower()
{
	if (isalpha(word[0]) && isupper(word[0]))
		word[0] = tolower(word[0]);

	//int i = 0;
	//char c;
	//string newWord = "";

	//// iterate the word and tolower each character
	//while (word[i])
	//{
	//	c = word[i];
	//	c = tolower(c);
	//	newWord = newWord + c;
	//	i++;
	//}

	//return newWord;
};