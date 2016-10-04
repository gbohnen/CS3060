#include <iostream>
#include <fstream>
#include <string>
#include "SampleText.h"
#include "PartOfSpeech.h"
#include "gsb_string.h"

using namespace std;
using namespace gsb;


int main()
{
	typedef gsb::string string;

	// load the parts of speech library
	cout << "Loading POS reference..." << endl;
	ifstream posLibraryFile("pos.txt");
	cout << "Building dictionary..." << endl;
	PartOfSpeech posLibrary = PartOfSpeech(posLibraryFile);

	// load the text file into a wrapper class
	cout << "Loading sampletext.txt..." << endl;
	ifstream sampleTextFile ("sampletext.txt");
	cout << "Processing text file..." << endl;
	SampleText text = SampleText();
	text.Analyze(sampleTextFile, posLibrary);

	// print the longest word
	cout << endl;
	cout << "The longest word found is: \'" << text.GetLongestWord().Text() << "\'." << endl;
	cout << "'" << text.GetLongestWord().Text() << "'" << " has approx. " << text.GetLongestWord().Syllables() << " syllables, " 
		<< " and is a(n) " << text.GetLongestWord().PartOfSpeech() << "." << endl;

	// print the shortest word
	cout << endl;
	cout << "The shortest word found is: '" << text.GetShortestWord().Text() << "'." << endl;
	cout << "'" << text.GetShortestWord().Text() << "'" << " has approx. " << text.GetShortestWord().Syllables() << " syllables, "
		<< " and is a(n) " << text.GetShortestWord().PartOfSpeech() << "." << endl;

	// display various metrics
	cout << endl;
	text.DisplayPOSCounts();
};