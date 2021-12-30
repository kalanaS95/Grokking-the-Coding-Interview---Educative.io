/*
	Question: Given an array of unsorted numbers and a target number, find all unique quadruplets in it, whose sum is equal to the target number.
			  Array: [4, 1, 2, -1, 1, -3]
			  Target: 1
*/
#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::sort;

/*
	Time Complexity: O(n^3), where n is number of elements present in the vector
	Space Complexity: Auxiliary array created by STL sort -> O(n), where n is number of elements in the vector
					  Space needed to hold results -> O(4*k), where k is number of quadripets in the results vector
					  Therefore total space complexity -> O(n) + O(4*k) == O(n + k) 
*/
class quadruple_sum_to_target {

private:
	vector<int> arr;
	int target;

	void find_matching(int &first_value, int &second_value, int start_index, int end_index, vector<vector<int>>& results) {

		while (start_index < end_index) {

			int curr_sum = first_value + second_value + this->arr[start_index] + this->arr[end_index];

			if (curr_sum == this->target) {

				results.push_back(vector<int>{first_value, second_value, this->arr[start_index], this->arr[end_index]});
				start_index++;
				end_index--;
			}
			else if (curr_sum < this->target) {

				start_index++;
			}
			else {

				end_index--;
			}
		}
	}

public:
	quadruple_sum_to_target() {

		this->arr = { 2, 0, -1, 1, -2, 2 };
		this->target = 2;
	}

	quadruple_sum_to_target(vector<int>& arr, int& target) {

		this->arr = arr;
		this->target = target;
	}

	vector<vector<int>> search_quadriplets() {

		vector<vector<int>> results;
		// sort the vector s.t we can use two pointer method
		sort(this->arr.begin(), this->arr.end());

		for (int first_ptr = 0; first_ptr < this->arr.size() - 3; first_ptr++) {

			if (first_ptr > 0 && this->arr[first_ptr] == this->arr[first_ptr - 1]) {
				continue;
			}

			for (int second_ptr = first_ptr + 1; second_ptr < this->arr.size() - 2; second_ptr++) {

				if (second_ptr > first_ptr + 1 && this->arr[second_ptr] == this->arr[second_ptr - 1]) {
					continue;
				}

				this->find_matching(this->arr[first_ptr], this->arr[second_ptr], second_ptr + 1, this->arr.size() - 1, results);
			}
		}

		return results;
	}
};