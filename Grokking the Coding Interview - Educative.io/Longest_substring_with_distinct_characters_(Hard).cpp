/*
	Question: Given a string, find the length of the longest substring, which has all distinct characters.
			  String: "aabccbb"
*/
#include <iostream>
#include <map>
#include <string>

using namespace std;

class NoRepeatSubstring {

private:
	string the_string;

public:
	NoRepeatSubstring() {

		this->the_string = "abccde";
	}

	NoRepeatSubstring(string& the_string) {

		this->the_string = the_string;
	}

	int findLength() {

		int window_start = 0;
		int max_len = INT_MIN;
		map<char, int> char_map;
		// key - chracter, value - index of the chracter
		map<char, int>::iterator map_itr;
		
		for (int window_end = 0; this->the_string[window_end] != '\0'; window_end++) {

			map_itr = char_map.find(this->the_string[window_end]);

			if (map_itr == char_map.end()) {

				char_map.insert(pair<char, int>(this->the_string[window_end], window_end));
				// calculate the substring size
				max_len = max(max_len, (window_end - window_start) + 1);
			}
			else {

				// at this point we found a duplicate char, meaning sub-string is not distinct anymore
				// we clear out the map and insert the new entry
				char_map.clear();
				char_map.insert(pair<char, int>(this->the_string[window_end], window_end));
				// so we move our start window to the window end, s.t we don't have any duplicates
				window_start = window_end;

			}
				
		}
		
		return max_len;
	}
};