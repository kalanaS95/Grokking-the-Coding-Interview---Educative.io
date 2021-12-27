/*
	Question: Given an array of positive numbers and a positive number ‘k,’ find the maximum sum of any contiguous subarray of size ‘k’.
			  Array: [2, 1, 5, 1, 3, 2]
			  k = 3
*/
#include <iostream>
#include <vector>

using namespace std;

/*
	Time complexity: O(n), where n is number of elements in the array
	Space complexity: O(1), we not using any dynamic structure to solve the problem
*/
class MaxSumSubArrayOfSizeK {

private:
	int k;
	vector<int> *arr;

public:
	MaxSumSubArrayOfSizeK() {

		this->k = 3;
		this->arr = new vector<int>({ 2, 1, 5, 1, 3, 2 });
	}

	MaxSumSubArrayOfSizeK(int k, vector<int>& arr) {

		this->k = k;
		this->arr = new vector<int>(arr);
	}

	int findMaxSumSubArray() {

		int window_start = 0;
		int current_sum = 0;
		int max_sum = INT_MIN;

		for (int window_end = 0; window_end < this->arr->size(); window_end++) {

			current_sum += this->arr->at(window_end);

			if (window_end - window_start >= k - 1) {

				max_sum = max(current_sum, max_sum);
				current_sum -= this->arr->at(window_start);
				window_start++;
			}
		}

		return max_sum;
	}
};