/*
	Question: Given a string and a pattern, find all anagrams of the pattern in the given string.
			  String: "ppqp"
			  Pattern: "pq"
*/
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class StringAnagrams {

private:
	string the_string;
	string pattern;

public:
	StringAnagrams() {

		this->the_string = "abbcabc";
		this->pattern = "abc";
	}

	StringAnagrams(string& the_string, string& pattern) {

		this->the_string = the_string;
		this->pattern = pattern;
	}

	vector<int> findStringAnagrams() {

		int window_start = 0;
		int window_end = 0;
		int indexes_index = 0;
  		vector<int> indexes(this->pattern.length(), 0);
		map<char, int> char_map;
		map<char, int>::iterator map_itr;

		// adding pattern elements to the char map
		for (string::iterator itr = this->pattern.begin(); itr != this->pattern.end(); itr++) {

			map_itr = char_map.find(*itr);

			if (map_itr == char_map.end()) {

				char_map.insert(pair<char, int>(*itr, 1));
			}
			else {

				map_itr->second++;
			}
		}

		while (this->the_string[window_end] != '\0') {

			map_itr = char_map.find(this->the_string[window_end]);
			
			if (map_itr != char_map.end()) {

				if (map_itr->second <= 0) {

					map_itr = char_map.find(this->the_string[window_start]);
					map_itr->second++;
					// removing index from the vector
					indexes[--indexes_index] = 0;
					window_start++;
				}
				else {

					map_itr->second--;
					// adding index to the vector
					indexes[indexes_index++] = window_end;
					int window_size = (window_end - window_start) + 1;
					window_end++;

					if (window_size == char_map.size()) {

						return indexes;
					}
				}		
			}
		}

		return indexes;
	}
};