/*
	Question: Given an array arr of unsorted numbers and a target sum, count all triplets in it such that arr[i] + arr[j] + arr[k] < target 
		      where i, j, and k are three different indices. Write a function to return the count of such triplets.
			  Array: [-1, 0, 2, 3]
			  Target: 3
*/
#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::sort;

class triplet_with_smaller_sum {

private:
	vector<int> arr;
	int target;

	void count_triplets(int start_index, int end_index, int& first_value, int& triplet_count) {

		while (start_index < end_index) {

			if (first_value + this->arr[start_index] + this->arr[end_index] < this->target) {

				triplet_count+= end_index - start_index;
				start_index++;
			}
			else {

				end_index--;
			}
		}
	}

public:
	triplet_with_smaller_sum() {

		this->arr = { -1, 0, 2, 3 };
		this->target = 3;
	}

	triplet_with_smaller_sum(vector<int>& arr, int& target) {

		this->arr = arr;
		this->target = target;
	}

	int find_tripets() {

		int triplet_count = 0;
		// sort the array - Time O(n log n), space - O(n)
		sort(this->arr.begin(), this->arr.end());

		for (int index = 0; index < this->arr.size() - 2; index++) {

			count_triplets(index + 1, this->arr.size() - 1, this->arr[index], triplet_count);
		}

		return triplet_count;
	}
};