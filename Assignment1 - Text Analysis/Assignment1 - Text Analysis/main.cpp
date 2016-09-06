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
	cout << "The longest word found is: \'" << text.GetLongestWord().first << "\'." << endl;
	cout << "'" << text.GetLongestWord().first << "'" << " has " << text.GetLongestWord().second << " syllables. Isn't that great?" << endl;
};