#include <iostream>
#include <fstream>
#include <string>
#include "SampleText.h"

using namespace std;

int main()
{
	// load the text file into a wrapper class
	ifstream sampleTextFile ("sampletext.txt");
	SampleText text = SampleText(sampleTextFile);

	// print the longest word
	cout << "The longest word found is: \'" << text.GetLongestWord().Text() << "\'." << endl;
	cout << "'" << text.GetLongestWord().Text() << "'" << " has " << text.GetLongestWord().Syllables() << " syllables. Isn't that great?" << endl;
};