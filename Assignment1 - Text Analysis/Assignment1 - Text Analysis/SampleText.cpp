#include "SampleText.h"

using namespace std;

// constructor
// takes a text file by reference and parses it into usable data types
SampleText::SampleText(ifstream& file)
{
	// import all text lines and load them into the vector array
	while (getline(file, line))
	{
		// check for line breaks
		// add each word to the array
		if (line != "")
		{
			while (line.length() > 0)
			{
				// grab the size of the next word
				size_t pos = line.find_first_of(",.?-:/ \n");

				// grab the substring and convert to lowercase
				pair<string, int> word = pair<string, int>(line.substr(0, pos), GetSyllables(line.substr(0, pos)));
				//word = ToLower(word); deprecated, uses too much memory

				// add the word
				words.push_back(word);

				// check if the word is the longest
				CheckLongestWord(word);

				// check to see if it's the last word, and remove it if that's the case
				if (line == word.first)
					line.erase(0, line.length());

				// remove the current word
				line.erase(0, pos + 1);
			}
		}
	}

	// test display the first hundred lines
	for (int i = 0; i < 100; i++)
	{
		cout << words[i].first << " " << words[i].second << endl;
	}
};

// return the longest word
pair<string, int> SampleText::GetLongestWord()
{
	return longestWord;
}

// compare current word to the previous longest word
void SampleText::CheckLongestWord(pair<string, int> str)
{
	if (str.first.length() > longestWord.first.length())
		longestWord = str;
};

// check if a given character is a vowel
bool SampleText::IsVowel(const char c)
{
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y' ||
		c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y')
		return true;
	else
		return false;
};

// check if the given character is a consonant
bool SampleText::IsConsonant(const char c)
{
	return !IsVowel(c);
};

// converts all characters to lowercase - possibly uses too much memory, or leaks. needs debugging
string SampleText::ToLower(string word) 
{
	int i = 0;
	char c;
	string newWord = "";

	// iterate the word and tolower each character
	while (word[i])
	{
		c = word[i];
		c = tolower(c);
		newWord = newWord + c;
		i++;
	}

	return newWord;
};

// returns the approximate number of syllables in a word
int SampleText::GetSyllables(const string& word)
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