/*
	Question(Problem Challenge 1): Given a string and a pattern, find out if the string contains any permutation of the pattern.
								   String: "oidbcaf"
								   Pattern: "abc"
*/
#include <iostream>
#include <map>
#include <string>
using namespace std;

class StringPermutation {

private:
	string the_string;
	string pattern;

public:
	StringPermutation() {

		this->the_string = "aaacb";
		this->pattern = "abc";
	}

	StringPermutation(string& the_string, string& pattern) {

		this->the_string = the_string;
		this->pattern = pattern;
	}

	bool findPermutation() {

		int window_start = 0;
		int window_end = 0;
		int current_count = 0;
		map<char, int> char_map;
		map<char, int>::iterator map_itr;
		
		// initiaze the map
		for (string::iterator str_itr = this->pattern.begin(); str_itr != this->pattern.end(); str_itr++) {

			map_itr = char_map.find(*str_itr);

			if (map_itr == char_map.end()) {

				char_map.insert(pair<char, int>(*str_itr, 1));
			}
			else {

				map_itr->second++;
			}
		}

		while (this->the_string[window_end] != '\0') {

			// if the character not in the map
			map_itr = char_map.find(this->the_string[window_end]);
			if (map_itr == char_map.end()) {

				// if both start and end at the same we need to move both to next
				if (window_start == window_end) {

					window_end++;
					window_start++;
				}
				else { // to do

					if (char_map[this->the_string[window_start]] <= 0) {

						current_count--;
					}
					char_map[this->the_string[window_start]];
					window_start++;
				}
			}
			else {

				// if character found decrement count in map
				if (map_itr->second > 0) {

					map_itr->second--;
					if (map_itr->second == 0) {

						current_count++;
					}
					window_end++;
				}
				else {

					// put the letter back to the map
					char_map[this->the_string[window_start]]++;
					// increment the window start
					window_start++;
					// decrement current count
					current_count--;
				}

				if (current_count == char_map.size()) {

					return true;
				}
			}

		}

		return false;
	}
};