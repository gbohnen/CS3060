#include "SampleText.h"

using namespace std;

// constructor
// takes a text file by reference and parses it into usable data types
SampleText::SampleText()
{	
};


void SampleText::Analyze(ifstream& file, PartOfSpeech& dictionary)
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
				word.SetPOS(dictionary.GetValue(word.Text()));

				// add the word
				words.push_back(word);

				// check words metrics
				CheckLongestWord(word);
				CheckShortestWord(word);
				UpdateCounts(word);

				// check to see if it's the last word, and remove it if that's the case
				if (line == word.Text())
					line.erase(0, line.length());

				// remove the current word
				line.erase(0, pos + 1);
			}
		}
	}

	//// test display the first hundred lines
	//for (int i = 0; i < 100; i++)
	//{
	//	cout << words[i].Text() << " " << words[i].Syllables() << " " << words[i].PartOfSpeech() << endl;
	//}
}

// return the longest word
Word SampleText::GetLongestWord()
{
	return longestWord;
}

// return the shortest word
Word SampleText::GetShortestWord()
{
	return shortestWord;
}

void SampleText::DisplayPOSCounts()
{
	cout << "Nouns:\t\t"		<< nounCount << endl;
	cout << "Verbs:\t\t"		<< verbCount << endl;
	cout << "Adjectives:\t"	<< adjCount << endl;
	cout << "Adverbs:\t"		<< advCount << endl;
	cout << "Prepositions:\t" << prepCount << endl;
	cout << "Unknown:\t"		<< unknCount << endl;
}

// compare current word to the previous longest word
void SampleText::CheckLongestWord(Word& str)
{
	if (str.Text().length() > longestWord.Text().length())
		longestWord = str;
};

// compare current word to previous shortest word
void SampleText::CheckShortestWord(Word& str)
{
	if (str.Text().length() > 0 && str.Text().length() < shortestWord.Text().length())
		shortestWord = str;
};

// update part of speech totals
void SampleText::UpdateCounts(Word& str)
{
	if (str.PartOfSpeech() == "Noun")
		nounCount++;
	else if (str.PartOfSpeech() == "Verb")
		verbCount++;
	else if (str.PartOfSpeech() == "Adjective")
		adjCount++;
	else if (str.PartOfSpeech() == "Adverb")
		advCount++;
	else if (str.PartOfSpeech() == "Preposition")
		prepCount++;
	else
		unknCount++;
}