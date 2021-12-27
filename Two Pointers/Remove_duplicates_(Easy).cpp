/*
	Question: Given an array of sorted numbers, remove all duplicates from it. You should not use any extra space; after removing the duplicates in-place return
			  the length of the subarray that has no duplicate in it.
			  Array: [2, 3, 3, 3, 6, 9, 9]
*/
#include <iostream>
#include <vector>
using namespace std;

/*
	Time Complexity: O(n), where n is number of elements in the vector
	Space Complexity: O(1)
*/
class remove_duplicates {

private:
	vector<int> arr;

public:
	remove_duplicates() {

		this->arr = { 2, 2, 2, 11 };
	}

	remove_duplicates(vector<int>& arr) {

		this->arr = arr;
	}

	int remove_dups() {

		int non_duplicate = 1;

		for (int curr_index = 1; curr_index < this->arr.size(); curr_index++) {

			if (this->arr[non_duplicate - 1] != this->arr[curr_index]) {

				this->arr[non_duplicate] = this->arr[curr_index];
				non_duplicate++;
			}
		}

		return non_duplicate;
	}
};