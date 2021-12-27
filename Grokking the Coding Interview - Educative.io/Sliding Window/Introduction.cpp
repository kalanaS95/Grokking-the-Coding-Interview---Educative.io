/*
	Question: Given an array, find the average of all contiguous subarrays of size ‘K’ in it.
			  Array: [1, 3, 2, 6, -1, 4, 1, 8, 2]
			  K = 5
*/

#include <iostream>
#include <vector>
using namespace std;

/*
	Time complexity: O(n), n is number of elements in the array
	Space complexity: O(m), m is number of sliding windows of size k we can fit within array size of n
*/
class AverageOfSubarrayOfSizeK {

private:
	int k;
	vector<int>* arr;

public:
	AverageOfSubarrayOfSizeK() {

		k = 5;
		arr = new vector<int>({ 1, 3, 2, 6, -1, 4, 1, 8, 2 });
	}

	AverageOfSubarrayOfSizeK(int k, vector<int>& arr) {

		this->k = k;
		this->arr = new vector<int>(arr);
	}

	vector<double> findAverage() {

		// vector to store average at each sliding window
		vector<double> averages(arr->size() - k + 1, 0);

		int window_start = 0;
		double current_sum = 0;

		for (int window_end = 0; window_end < arr->size(); window_end++) {

			current_sum = current_sum + this->arr->at(window_end);

			// When our sliding window size is 5, then we need to calculate the average
			if (window_end - window_start >= this->k - 1) {

				averages[window_start] = current_sum / this->k;
				// substract the first element from the current sum
				current_sum -= this->arr->at(window_start);
				// move start position by one to start the new window
				window_start++;
			}
		}

		return averages;
	}
};