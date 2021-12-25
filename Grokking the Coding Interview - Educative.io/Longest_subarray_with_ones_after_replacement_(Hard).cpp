/*
	Question: Given an array containing 0s and 1s, if you are allowed to replace no more than ‘k’ 0s with 1s,
			  find the length of the longest contiguous subarray having all 1s.
			  Array: [0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1]
			  k = 2
*/
#include <iostream>
#include <vector>
using namespace std;

/*
	Time Complexity: O(n), where n is number of elements in the vector
	Space Complexity: O(1)
*/
class ReplacingOnes {

private:
	vector<int> *array;
	int k;

public:
	ReplacingOnes() {

		this->array = new vector<int>({ 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1 });
		this->k = 3;
	}

	ReplacingOnes(vector<int>& array, int k) {

		this->array = new vector<int>(array);
		this->k = k;
	}

	int findLength() {

		int window_start = 0;
		int max_len = INT_MIN;
		int replaced = 0;

		for (int window_end = 0; window_end < this->array->size(); window_end++) {

			if (this->array->at(window_end) == 0) {

				replaced++;
			}

			if (replaced > this->k) {

				if (this->array->at(window_start) == 0) {

					replaced--;
				}

				window_start++;
			}

			max_len = max(max_len, window_end - window_start + 1);
		}

		return max_len;
	}
};