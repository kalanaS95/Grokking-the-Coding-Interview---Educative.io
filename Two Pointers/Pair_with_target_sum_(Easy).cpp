/*
	Question: Given an array of sorted numbers and a target sum, find a pair in the array whose sum is equal to the given target.
			  Array: [1, 2, 3, 4, 6]
			  Target: 6
*/
#include <iostream>
#include <vector>
using namespace std;

/*
	Time Complexity: O(n), where n is number of elements in the vector
	Space Complexity: O(1)
*/
class pair_with_target_sum {

private:
	vector<int> numbers;
	int target;

public:
	pair_with_target_sum() {

		this->numbers = { 1, 2, 3, 4, 6 };
		this->target = 6;
	}

	pair_with_target_sum(vector<int>& numbers, int target) {

		this->numbers = numbers;
		this->target = target;
	}

	pair<int, int> search() {

		int start_ptr = 0;
		int end_ptr = this->numbers.size() - 1;
		pair<int, int> indexes(-1, -1);

		while (start_ptr < end_ptr) {

			if (this->numbers[start_ptr] + this->numbers[end_ptr] == this->target) {

				indexes.first = start_ptr;
				indexes.second = end_ptr;
				break;
			}
			else if (this->numbers[start_ptr] + this->numbers[end_ptr] > this->target) {

				end_ptr--;
			}
			else {

				start_ptr++;
			}
		}

		return indexes;
	}
};