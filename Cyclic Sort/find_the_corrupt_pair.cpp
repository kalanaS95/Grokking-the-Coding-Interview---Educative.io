/*
	Question: We are given an unsorted array containing ‘n’ numbers taken from the range 1 to ‘n’. The array originally contained all the numbers from 1 to ‘n’, but due to a data error, 
			  one of the numbers got duplicated which also resulted in one number going missing. Find both these numbers.
	Input: [3, 1, 2, 5, 2]
	Output: [2, 4]
*/
#include <vector>
using std::vector;

/*
	Time Complexity: O(n), where n is number of elements in the vector
	Space Complexity: O(1)
*/
class find_the_corrupt_pair {
private:
	vector<int> arr;

	void swap(int* a, int* b) {

		int temp = *a;
		*a = *b;
		*b = temp;
	}

public:
	find_the_corrupt_pair() {
		this->arr = { 3, 1, 2, 5, 2 };
	}

	find_the_corrupt_pair(vector<int> arr) {
		this->arr = arr;
	}

	vector<int> find_missing_duplicate_pair() {
		
		vector<int> duplicate_missing = { -1, -1 };
		for (int index = 0; index < this->arr.size();) {

			if (this->arr[index] != index + 1 && this->arr[index] != this->arr[this->arr[index] - 1]) {

				swap(&(this->arr[index]), &(this->arr[this->arr[index] - 1]));
			}
			else {
				index++;
			}
		}

		for (int index = 0; index < this->arr.size(); index++) {

			if (this->arr[index] != index + 1) {

				duplicate_missing[0] = this->arr[index];
				duplicate_missing[1] = index + 1;
				break;
			}
		}

		return duplicate_missing;
	}
};