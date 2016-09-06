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
				Word word = Word(line.substr(0, pos));
				//word = ToLower(word); deprecated, uses too much memory

				// add the word
				words.push_back(word);

				// check if the word is the longest
				CheckLongestWord(word);

				// check to see if it's the last word, and remove it if that's the case
				if (line == word.Text())
					line.erase(0, line.length());

				// remove the current word
				line.erase(0, pos + 1);
			}
		}
	}

	// test display the first hundred lines
	for (int i = 0; i < 100; i++)
	{
		cout << words[i].Text() << " " << words[i].Syllables() << endl;
	}
};

// return the longest word
Word SampleText::GetLongestWord()
{
	return longestWord;
}

// compare current word to the previous longest word
void SampleText::CheckLongestWord(Word str)
{
	if (str.Text().length() > longestWord.Text().length())
		longestWord = str;
};