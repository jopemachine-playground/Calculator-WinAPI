#pragma once
// https://stackoverflow.com/questions/236129/how-do-i-iterate-over-the-words-of-a-string
// https://stackoverflow.com/questions/8362094/replace-multiple-spaces-with-one-space-in-a-string

#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <iostream>

using namespace std;

class Utility {
public:

	static vector<string> split(string str, char delim) {

		// 여러 개의 공백을 하나로 만든다
		string::iterator new_end = unique(str.begin(), str.end(), BothAreSpaces);
		str.erase(new_end, str.end());

		vector<string> elems;
		split(str, delim, back_inserter(elems));
		return elems;
	}

private:

	static bool BothAreSpaces(char lhs, char rhs) {
		return (lhs == rhs) && (lhs == ' ');
	}

	template<typename Out>
	static void split(const string& s, char delim, Out result) {
		stringstream ss(s);
		string item;
		while (getline(ss, item, delim)) {
			*(result++) = item;
		}
	}
};