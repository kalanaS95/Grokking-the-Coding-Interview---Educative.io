#include <iostream>
#include <vector>
#include "Introduction.cpp"
#include "Maximum_sum_subarray_of_size_k_(Easy).cpp"

using namespace std;

int main() {

	cout << "Average Of Subarray Of Size K" << endl;
	AverageOfSubarrayOfSizeK average_k;
	vector<double> results = average_k.findAverage();
	cout << "Averages are: [ ";
	for (double x : results) {

		cout << x << " ";
	}
	cout << "]" << endl << endl;

	cout << "find MaxSum SubArray" << endl;
	MaxSumSubArrayOfSizeK max_sum;
	cout << "Max sum is: " << max_sum.findMaxSumSubArray() << endl << endl;


	return 0;
}