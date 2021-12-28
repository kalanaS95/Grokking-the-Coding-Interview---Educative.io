/*
	Question: Given an array of unsorted numbers, find all unique triplets in it that add up to zero.
			  Array: [-3, 0, 1, 2, -1, 1, -2]
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
	Time Complexity:
					Sorting -> O(n log n)
					Selecting element -> O(n)
					finding pair for selected element -> O(n)
					Therefore complete runtime = O(n log n + n * n) = O(n^2)
					Where n is number of elements in the vector

	Space Complexity: O(3*m) = O(m), where m is number of triplets found 
*/
class triplet_sum_to_zero {

private:
	vector<int> arr;

	void find_pair(int target, int begin_index, int end_index, vector<vector<int>> &res) {

		while (begin_index < end_index) {

			if (this->arr[begin_index] + this->arr[end_index] == target) {

				res.push_back(vector<int>{target* (-1), this->arr[begin_index], this->arr[end_index]});
				begin_index++;
				end_index--;
			}
			else if (this->arr[begin_index] + this->arr[end_index] > target) {

				end_index--;
			}
			else {

				begin_index++;
			}
		}
	}

public:
	triplet_sum_to_zero() {

		this->arr = { -5, 2, -1, -2, 3 };
	}

	triplet_sum_to_zero(vector<int>& arr) {

		this->arr = arr;
	}

	vector<vector<int>> find_triplets() {

		vector<vector<int>> res;
		// first sort the array, so we can use two pointer technique
		sort(this->arr.begin(), this->arr.end()); // time complexity O(N log N)

		for (int index = 0; index < this->arr.size() - 2; index++) { // O(n)

			if (index > 0 && this->arr[index] == this->arr[index - 1]) {
				continue;
			}

			this->find_pair(this->arr[index] * (-1), index + 1, this->arr.size() - 1, res); // O(n)
		}

		return res;
	}
};