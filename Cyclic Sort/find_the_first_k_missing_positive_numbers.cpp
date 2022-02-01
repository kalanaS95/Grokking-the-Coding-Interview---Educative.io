/*
	Question: Given an unsorted array containing numbers and a number ‘k’, find the first ‘k’ missing positive numbers in the array.
	Input: [3, -1, 4, 5, 5]
	k: 3
	Output: [1, 2, 6]
*/
#include <vector>
using std::vector;
using std::max;

/*
	Time Complexity: O(n + x), where n is number of elements in the vector and x is remaining missing elements (if we could not find all the missing elements by scanning the vector)
	Space Complexity: O(k), where k is number of missing elements
*/
class find_the_first_k_missing_positive_numbers {
private:
	vector<int> arr;
	int k;

	void swap(int& a, int& b) {

		int temp = a;
		a = b;
		b = temp;
	}

public:
	find_the_first_k_missing_positive_numbers() {
		
		this->arr = { 3, -1, 4, 5, 5 };
		this->k = 3;
	}

	find_the_first_k_missing_positive_numbers(vector<int> arr, int k) {

		this->arr = arr;
		this->k = k;
	}

	vector<int> find_missing_k_numbers() {

		// record the maximum value when we are scanning the array, we can use this knowledge when we are looking for missing positive values
		int global_max = INT_MIN;
		int current_k = 0;
		vector<int> missing_numbers;

		// O(n)
		for (int index = 0; index < this->arr.size();) {

			global_max = max(global_max, this->arr[index]);

			if (this->arr[index] != index + 1 && this->arr[index] > 0 && this->arr[index] <= this->arr.size() &&
				this->arr[index] != this->arr[this->arr[index] - 1]) {

				this->swap(this->arr[index], this->arr[this->arr[index] - 1]);
			}
			else {

				index++;
			}
		}

		// finding the missing k positive numbers
		// O(n)
		for (int index = 0; index < this->arr.size() && current_k < this->k; index++) {

			if (this->arr[index] != index + 1) {

				missing_numbers.push_back(index + 1);
				current_k++;
			}
		}

		// In case we did not find all the K elements we need to find the rest
		// This is where our max is coming in clutch
		// O(x), where x is remaining missing elements
		for (int missing_value = global_max + 1; current_k < this->k; missing_value++) {

			missing_numbers.push_back(missing_value);
			current_k++;
		}

		return missing_numbers;
	}
};