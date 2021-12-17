/*
	Question: Given a string with lowercase letters only, if you are allowed to replace no more than k letters with any letter, 
			  find the length of the longest substring having the same letters after replacement.
			  String: "aabccbb"
			  k = 2

*/
#include <iostream>
#include <string>
using namespace std;

/*
	Time complexity: O(n)
	Space complexity: O(1)
*/
class CharacterReplacement {

private:
	string the_string;
	int k;

public:
	CharacterReplacement() {

		this->the_string = "abccde";
		this->k = 1;
	}

	CharacterReplacement(string the_string, int k) {

		this->the_string = the_string;
		this->k = k;
	}

	int findLength() {

		int window_start = 0;
		int max_len = INT_MIN;
		int replaced = 0;

		for (int window_end = 0; this->the_string[window_end] != '\0'; window_end++) {

			// if window_end and window_start pointing to the same type of char, move forward
			if (this->the_string[window_end] == this->the_string[window_start]) {
				
				max_len = max(max_len, (window_end - window_start) + 1);
			}
			else {

				// if we have characters left to repalce then replace and count length
				if (replaced < this->k) {

					replaced++;
					max_len = max(max_len, (window_end - window_start) + 1);
				}
				else { 

					// all the characters are used for replacing. move both pointers to where we first 
					// started repalcing the characters and reset replaced as well
					replaced = 0;
					window_start = (window_end - this->k);
					window_end = window_start - 1; // we set window_end one index behind because in the for loop we are increment by 1
					// so by the end of for loop window_end++ they both end up at the same index
				}
			}
		}

		return max_len;
	}
};
