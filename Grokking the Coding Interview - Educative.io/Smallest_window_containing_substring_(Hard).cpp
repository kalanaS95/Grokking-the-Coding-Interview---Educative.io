/*
	Question: Given a string and a pattern, find the smallest substring in the given string which has all the characters of the given pattern.
			  String: "aabdec"
			  Pattern: "abc"
*/
#include <iostream>
#include <string>
#include <map>
using namespace std;

class MinimumWindowSubstring {

private:
	string the_string;
	string pattern;

public:
	MinimumWindowSubstring() {

		this->the_string = "aabdec";
		this->pattern = "abc";
	}

	MinimumWindowSubstring(string& the_string, string& pattern) {

		this->the_string = the_string;
		this->pattern = pattern;
	}

	string find_substring() {

		int window_start = 0;
		int str_length = INT_MAX;
		int chars_used = 0;
		string small_str = "";
		map<char, int> char_map;
		map<char, int>::iterator map_itr;

		for (string::iterator str_itr = this->pattern.begin(); str_itr != this->pattern.end(); str_itr++) {

			map_itr = char_map.find(*str_itr);

			if (map_itr == char_map.end()) {

				char_map.insert(pair<char, int>(*str_itr, 1));
			}
			else {

				map_itr->second++;
			}
		}

		for (int window_end = 0; this->the_string[window_end] != '\0'; window_end++) {

			map_itr = char_map.find(this->the_string.at(window_end));
			if (map_itr != char_map.end()) {

				if (map_itr->second > 0) {

					// decrement the character count
					map_itr->second--;
					chars_used++;

					// check if all the letters are used, the its time to calculate string length
					if (chars_used >= char_map.size()) {

						str_length = min(str_length, (window_end - window_start) + 1);
						// means we found a new smaller string.
						if (str_length == (window_end - window_start) + 1) {

							small_str = this->the_string.substr(window_start, window_end);
						}
					}
				}
				else {
					// now close the window
					while (window_start < window_end) {

						map_itr = char_map.find(this->the_string.at(window_start));
						if (map_itr != char_map.end()) {

							map_itr->second++;
							chars_used--;
						}
						window_start++;
					}
					// reduce window_end by 1
					window_end--;
				}
			}
			// if character not found we just move the window_end, so need of else here
		}

		return small_str;
	}
};