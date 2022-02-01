/*
	Question: Given an unsorted array containing numbers, find the smallest missing positive number in it.
	Input: [-3, 1, 5, 4, 2]
	Output: 3
*/
#include <vector>
using std::vector;
using std::min;

/*
	Time Complexity: O(n), where n is number of elements in the vector
	Space Complexity: O(1)
*/
class find_the_smallest_missing_positive_number {
private:
	vector<int> arr;

	void swap(int& a, int& b) {

		int temp = a;
		a = b;
		b = temp;
	}

public:
	find_the_smallest_missing_positive_number() {
		this->arr = { -3, 1, 5, 4, 2 };
	}

	find_the_smallest_missing_positive_number(vector<int> arr) {
		this->arr = arr;
	}

	int smallest_missing_number() {
		
		int smallest = INT_MAX;

		for (int index = 0; index < this->arr.size();) {

			if (this->arr[index] != index + 1 && this->arr[index] > 0 && this->arr[index] < this->arr.size()) {

				this->swap(this->arr[index], this->arr[this->arr[index] - 1]);
			}
			else {
				index++;
			}
		}

		for (int index = 0; index < this->arr.size(); index++) {

			if (this->arr[index] != index + 1) {

				smallest = min(smallest, index + 1);
			}
		}

		return smallest;
	}
};