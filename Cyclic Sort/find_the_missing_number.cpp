/*
	Question: We are given an array containing ‘n’ distinct numbers taken from the range 0 to ‘n’. Since the array has only ‘n’ numbers out of the total ‘n+1’ numbers, find the missing number.
	Input: [4, 0, 3, 1]
	output: 2
*/
#include<vector>
using std::vector;

class find_missing_number {
private:
	vector<int>arr;

	void swap(int* a, int* b) {

		int temp = *a;
		*a = *b;
		*b = temp;
	}

public:
	find_missing_number(){

		this->arr = { 4, 0, 3, 1 };
	}

	int find_missing() {

		int index = 0;
		while (index < this->arr.size()) {

			if (this->arr[index] != index && this->arr[index] < this->arr.size()) {

				swap(&(this->arr[index]), &(this->arr[this->arr[index]]));
			}
			else {
				index++;
			}
		}


		// find the missing element
		for (int index = 0; index < this->arr.size(); index++) {

			if (this->arr[index] != index) {

				return index;
			}
		}

		// if we are here that means all the values we have maps to the indexes. Meaning, we only missing n, since (0...n) and out array maps to 0....n-1
		return this->arr.size();
	}
};