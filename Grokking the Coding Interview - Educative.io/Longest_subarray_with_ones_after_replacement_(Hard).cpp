/*
	Question: Given an array containing 0s and 1s, if you are allowed to replace no more than ‘k’ 0s with 1s,
			  find the length of the longest contiguous subarray having all 1s.
			  Array: [0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1]
			  k = 2
*/
#include <iostream>
#include <vector>
using namespace std;

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
		int last_zero_index = 0;

		for (int window_end = 0; window_end < this->array->size(); window_end++) {
			
			if (this->array->at(window_end) == 0) {

				if (replaced < this->k) {

					last_zero_index = window_end;
					replaced++;
					max_len = max(max_len, (window_end - window_start) + 1);
				}
				else {

					window_start = last_zero_index;
					window_end = window_start - 1;
					replaced = 0;
				}
			}
			else {

				max_len = max(max_len, (window_end - window_start) + 1);
			}
		}

		return max_len;
	}
};