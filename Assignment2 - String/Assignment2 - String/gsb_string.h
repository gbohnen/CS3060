#ifndef GSB_STRING_H
#define GSB_STRING_H

namespace gsb
{
	class string
	{
	public:
		// default constructor
		string();

		// default destructor
		~string();

		// constructor, accepts a char pointer parameter
		string(const char* d);

		// copy constructor
		string(string& str);

		// basic assignment operator
		string& operator=(char* d);

		// assignment operator, functions as copy constructor
		string& operator=(const string& str);

		// convert object to string
		const char* ToString() const;

		// casting operators?
		operator const char*() const;

		// length of the string
		int Length();


	private:

		void InitData(const char* d);
		void FreeData();
	protected:
		int length = 0;
		char* data = nullptr;			// string data
	};
}

#endif