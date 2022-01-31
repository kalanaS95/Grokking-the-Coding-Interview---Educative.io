/*
	Question: We are given an unsorted array containing numbers taken from the range 1 to ‘n’. The array can have duplicates, which means some numbers will be missing. Find all those missing numbers.
	Input: [2, 3, 1, 8, 2, 3, 5, 1]
	Output: 4, 6, 7
*/
#include <vector>
using std::vector;

/*
	Time Complexity: O(n), where n is number of elements in the vector
	Space Complexity: O(1)
*/
class find_all_missing_numbers {
private:
	vector<int> arr;

	void swap(int* a, int* b) {

		int temp = *a;
		*a = *b;
		*b = temp;
	}

public:
	find_all_missing_numbers() {
		this->arr = { 2, 3, 1, 8, 2, 3, 5, 1 };
	}

	find_all_missing_numbers(vector<int> arr) {
		this->arr = arr;
	}

	vector<int> missing_elements() {

		for (int index = 0; index < this->arr.size();) {

			if (this->arr[index] != this->arr[this->arr[index] - 1]) {

				swap(&(this->arr[index]), &(this->arr[this->arr[index] - 1]));
			}
			else {
				index++;
			}
		}

		vector<int> missing_elements;

		for (int index = 0; index < this->arr.size(); index++) {

			if (this->arr[index] != index + 1) {

				missing_elements.push_back(index + 1);
			}
		}

		return missing_elements;
	}

};