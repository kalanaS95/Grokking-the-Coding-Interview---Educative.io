/*
	Question: This problem follows the Cyclic Sort pattern and shares similarities with Find the Duplicate Number. Following a similar approach, we will place each number at its correct index. 
			  After that, we will iterate through the array to find all numbers that are not at the correct indices. All these numbers are duplicates.
	Input: [3, 4, 4, 5, 5]
	Ouput: [4, 5]
*/
#include <vector>
using std::vector;

class find_all_duplicate_nunbers {
private:
	vector<int> arr;

	void swap(int* a, int* b) {

		int temp = *a;
		*a = *b;
		*b = temp;
	}

public:
	find_all_duplicate_nunbers() {
		this->arr = { 3, 4, 4, 5, 5 };
	}

	find_all_duplicate_nunbers(vector<int> arr) {
		this->arr = arr;
	}

	vector<int> all_duplicates() {

		vector<int> missing_elements;

		for (int index = 0; index < this->arr.size();) {

			if (this->arr[index] != index + 1) {

				if (this->arr[index] != this->arr[this->arr[index] - 1]) {

					swap(&(this->arr[index]), &(this->arr[this->arr[index] - 1]));
				}
				else {

					missing_elements.push_back(this->arr[index]);
					index++;
				}
			}
			else {

				index++;
			}
		}

		return missing_elements;
	}
};