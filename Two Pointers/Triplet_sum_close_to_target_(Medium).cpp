/*
	Question: Given an array of unsorted numbers and a target number, find a triplet in the array whose sum is as close to the target number as possible, 
			  return the sum of the triplet. If there are more than one such triplet, return the sum of the triplet with the smallest sum.
			  Array: [-2, 0, 1, 2]
			  Target: 2
*/
#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::sort;

/*
	Time Complexity: O(n log n) + O(n) * O(n) == O(n^2), where n is number of elements in the vector 
	Space Complexity: O(1)
*/
class triptlet_sum_close_to_target {

private:
	vector<int> arr;
	int target;

	// O(n)
	void find_closest(int begin_index, int end_index, int& first_value, int& curr_difference, vector<int>& selected_values) {
		
		while (begin_index < end_index) {

			int difference = abs(this->target - (first_value + this->arr[begin_index] + this->arr[end_index]));

			if (difference < curr_difference) {

				curr_difference = difference;
				selected_values[0] = first_value;
				selected_values[1] = this->arr[begin_index];
				selected_values[2] = this->arr[end_index];
			}

			if (difference == 0) {

				return;
			}
			else if (difference < 0) {

				end_index--;
			}
			else {

				begin_index++;
			}
		}
	}

public:
	triptlet_sum_close_to_target() {

		this->arr = { 1, 0, 1, 1 };
		this->target = 100;
	}

	triptlet_sum_close_to_target(vector<int>& arr, int target) {

		this->arr = arr;
		this->target = target;
	}

	int search_triplet() {

		int curr_difference = INT_MAX;
		vector<int> selected_values(3, -1);
		// sort the array to use two pointer method
		sort(this->arr.begin(), this->arr.end()); // O(n log n)

		for (int index = 0; index < this->arr.size() - 2; index++) { // O(n)

			find_closest(index + 1, this->arr.size() - 1, this->arr[index], curr_difference, selected_values);
		}

		return selected_values[0] + selected_values[1] + selected_values[2];
	}
};