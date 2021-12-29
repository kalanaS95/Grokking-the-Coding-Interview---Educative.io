/*
	Question: Given an array with positive numbers and a positive target number, find all of its contiguous subarrays whose product is less than the target number.
			  Array: [2, 5, 3, 10]
			  Target: 30
*/
#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::sort;

/*
	Time Complexity: O(n^2), where n is number of elements in the given vector
	Space Complexity: O(m*k), where k is number of elements in each vector within main vector and k is number of elements in the main vector
*/
class subarray_product_less_than_k {

private:
	vector<int> arr;
	int target;

	void find_elements(int start_index, vector<int>& curr_list, vector<vector<int>>& res) {

		int curr_product = curr_list[0];

		for (int index = start_index; index < this->arr.size(); index++) {

			if (curr_product * this->arr[index] < this->target) {

				curr_list.push_back(this->arr[index]);
				res.push_back(curr_list);
				curr_product *= this->arr[index];
			}
			else {

				return;
			}
		}
	}

public:
	subarray_product_less_than_k() {

		this->arr = { 8, 2, 6, 5 };
		this->target = 50;
	}

	subarray_product_less_than_k(vector<int>& arr, int& target) {

		this->arr = arr;
		this->target = target;
	}

	vector<vector<int>> find_triplets() {

		vector<vector<int>> res;
		vector<int> curr_list;

		for (int index = 0; index < this->arr.size(); index++) {

			if (this->arr[index] < this->target) {

				curr_list.push_back(this->arr[index]);
				res.push_back(curr_list);

				if (index < this->arr.size() - 1) {

					find_elements(index + 1, curr_list, res);					
				}

				// clear the curr_list for the next iteration
				curr_list.clear();
			}
		}

		return res;
	}
};
