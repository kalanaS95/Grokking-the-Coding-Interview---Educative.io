/*
	Question: Given a string, find the length of the longest substring in it with no more than K distinct characters.
			  String: araaci
			  k = 2
*/
#include <iostream>
#include <map>
#include <string>
using namespace std;

class LongestSubstringKDistinct {

private:
	string the_string;
	int k;

public: 
	LongestSubstringKDistinct() {

		this->the_string = "cbbebi";
		this->k = 10;
	}

	LongestSubstringKDistinct(string& the_string, int k) {

		this->the_string = the_string;
		this->k = k;
	}

	int findLength() {

		int windows_start = 0;
		int max_len = INT_MIN;
		map<char, int> char_map;
		map<char, int>::iterator map_itr;

		for (int window_end = 0; this->the_string[window_end] != '\0'; window_end++) {

			map_itr = char_map.find(this->the_string[window_end]);

			if (map_itr == char_map.end()) {

				char_map.insert(pair<char, int>(this->the_string[window_end], 1));
			}
			else {

				map_itr->second++;
			}

			while (char_map.size() > this->k) {

				map_itr = char_map.find(this->the_string[windows_start]);
				map_itr->second--;

				if (map_itr->second < 1) {

					char_map.erase(map_itr);
				}

				windows_start++;
			}

			max_len = max(max_len, (window_end - windows_start + 1));
		}

		return max_len;
	}
};