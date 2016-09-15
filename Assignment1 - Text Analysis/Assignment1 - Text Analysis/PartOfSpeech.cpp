#include "PartOfSpeech.h"

using namespace std;


// default constructor
PartOfSpeech::PartOfSpeech(ifstream& file)
{
	if (file.is_open())
	{
		string str;
		while (file >> str)
		{
			size_t deliminator = str.find_first_of(":");
			string word = str.substr(0, deliminator);
			string pos = str.substr(deliminator + 1);

			dictionary[word] = pos;
		}
	}
}


string PartOfSpeech::GetValue(const string& key)
{
	map<string, string>::iterator search = dictionary.find(key);

	if (search != dictionary.end())
	{
		return ParsePOS(search->second);
	}
	else
	{
		return "Unknown";
	}
}

string PartOfSpeech::ParsePOS(const string& part)
{
	if (part == "N")
		return "Noun";
	else if (part == "V")
		return "Verb";
	else if (part == "A")
		return "Adjective";
	else if (part == "v")
		return "Adverb";
	else if (part == "P")
		return "Preposition";
	else
		return "Unknown";
}