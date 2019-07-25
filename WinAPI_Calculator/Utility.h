#pragma once
// https://stackoverflow.com/questions/236129/how-do-i-iterate-over-the-words-of-a-string

#include <string>
#include <sstream>
#include <vector>
#include <iterator>
using namespace std;

class Utility {
public:

	static vector<string> split(const string& s, char delim) {
		vector<string> elems;
		split(s, delim, back_inserter(elems));
		return elems;
	}

private:

	template<typename Out>
	static void split(const string& s, char delim, Out result) {
		stringstream ss(s);
		string item;
		while (getline(ss, item, delim)) {
			*(result++) = item;
		}
	}
};