/*
	Question: We are given an unsorted array containing ‘n+1’ numbers taken from the range 1 to ‘n’. The array has only one duplicate but it can be repeated multiple times. 
			  Find that duplicate number without using any extra space. You are, however, allowed to modify the input array.
	Input: [ 2, 1, 3, 3, 5, 4]
	Output: 3
*/
#include <vector>
using std::vector;

/*
	Time Complexity: O(n), number of elements in the given vector
	Space Complexity: O(1)
*/
class find_the_duplicate_number {
private:
	vector<int> arr;
	void swap(int* a, int* b) {
		
		int temp = *a;
		*a = *b;
		*b = temp;
	}

public:
	find_the_duplicate_number() {
		this->arr = { 2, 1, 3, 3, 5, 4 };
	}

	find_the_duplicate_number(vector<int> arr) {
		this->arr = arr;
	}

	int duplicate_element() {

		for (int index = 0; index < this->arr.size();) {

			if (this->arr[index] != index + 1) {

				if (this->arr[index] != this->arr[this->arr[index] - 1]) {

					swap(&(this->arr[index]), &(this->arr[this->arr[index] - 1]));
				}
				else {
					return this->arr[index];
				}
			}
			else {
				index++;
			}
		}

		return -1;
	}
};