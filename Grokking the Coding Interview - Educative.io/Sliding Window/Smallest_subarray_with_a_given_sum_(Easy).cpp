/*
	Question: Given an array of positive numbers and a positive number ‘S,’ find the length of the smallest contiguous subarray whose sum is greater than or equal to ‘S’.
			  Return 0 if no such subarray exists.
			  Array: [2, 1, 5, 2, 3, 2]
			  S = 7
*/
#include <iostream>
#include <vector>
using namespace std;

/*
	Time complexity: O(n), where n is number of elements in the vector
	Space complexity: O(1)
*/
class MinSizeSubArraySum {

private:
	int s;
	vector<int>* arr;

public:
	MinSizeSubArraySum() {

		this->s = 7;
		this->arr = new vector<int>({ 2, 1, 5, 2, 3, 2 });
		cout << "curr_sum: " << this->arr->size() << endl;
	}

	MinSizeSubArraySum(int s, vector<int>& arr) {

		this->s = s;
		this->arr = new vector<int>(arr);
	}


	int findMinSubArray() {

		int window_start = 0;
		int current_sum = 0;
		int sub_array_len = INT_MAX; 

		
		for (int window_end = 0; window_end < this->arr->size(); window_end++) {

			current_sum += this->arr->at(window_end);

			while (current_sum >= this->s) {

				sub_array_len = min(sub_array_len, (window_end - window_start + 1));
				current_sum -= this->arr->at(window_start);
				window_start++;
			}
		}

		// if sub_array_len == INT_MAX at this point, that means we did not find the smallest sub array that is >= S, so return 0
		return (sub_array_len == INT_MAX) ? 0 : sub_array_len;
	}
};