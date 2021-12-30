/*
	Question: Given two strings containing backspaces (identified by the character ‘#’), check if the two strings are equal.
			  string 1: "xy#z"
			  string 2: "xzz#"
*/

#include <iostream>
#include <vector>
using std::vector;
using std::string;

/*
	Time Complexity: O(m * n), where m is shortest string from given 2 strings and n is the maximum number of # signs found in given strings
	Space Complexity: O(1)
*/
class backspace_compare {

private:
	string str1;
	string str2;

	int count_backspaces(int curr_index, string& str) {

		int backspaces = 0;
		while (str[curr_index] == '#' && curr_index >= 0) {

			backspaces++;
			curr_index--;
		}

		return backspaces;
	}

public:
	backspace_compare() {

		this->str1 = "xywrrmp";
		this->str2 = "xywrrmu#p";
	}

	backspace_compare(string& str1, string& str2) {

		this->str1 = str1;
		this->str2 = str2;
	}

	bool compare() {

		int str1_length = 0;
		int str2_length = 0;
		int str1_index = this->str1.length() - 1;
		int str2_index = this->str2.length() - 1;

		while (str1_index >= 0 && str2_index >= 0) {

			if (this->str1[str1_index] == '#') {
				str1_index -= count_backspaces(str1_index, this->str1) * 2;
			}

			if (this->str2[str2_index] == '#') {
				str2_index -= count_backspaces(str2_index, this->str2) * 2;
			}

			if (this->str1[str1_index] == this->str2[str2_index]) {

				str1_length++;
				str2_length++;
				str1_index--;
				str2_index--;
			}
			else {

				// meaning chars are not matching. So no need to comapare again
				return false;
			}
		}

		// if are at this point, it means we matched all the chars in both strings correct. 
		// But one of the strings might be lengthier than the other or they both are equal in length
		return (str1_length == str2_length) ? true : false;
	}
};