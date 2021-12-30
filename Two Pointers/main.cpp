#include <iostream>
#include "Pair_with_target_sum_(Easy).cpp"
#include "Remove_duplicates_(Easy).cpp"
#include "Squaring_a_sorted_array_(Easy).cpp"
#include "Triplet_sum_to_zero_(Medium).cpp"
#include "Triplet_sum_close_to_target_(Medium).cpp"
#include "Triplet_with_smaller_sum_(Medium).cpp"
#include "Subarray_with_products_less_than_a_target_(Medium).cpp"
#include "Dutch_national_flag_problem_(Medium).cpp"
#include "Quadruple_sum_to_target_(Medium).cpp"
using namespace std;

int main()
{
    cout << "Pair with Target Sum" << endl;
    pair_with_target_sum target_sum;
    pair<int, int> indexes = target_sum.search();
    cout << "Pair in the array whose sum is equal to the given target " << indexes.first << ", " << indexes.second << endl << endl;

    cout << "Remove Duplicates" << endl;
    remove_duplicates remov_dups;
    cout << "Array length after removing duplicates: " << remov_dups.remove_dups() << endl << endl;

    cout << "Squaring a Sorted Array" << endl;
    cout << "Squares of all the numbers of the input array: [";
    sorted_array_squared squared;
    for (auto element : squared.square_array()) {

        cout << element << " ";
    }
    cout << "]" << endl << endl;

    cout << "Triplet Sum to Zero" << endl;
    cout << "All unique triplets in it that add up to zero: [ ";
    triplet_sum_to_zero sum_zero;
    for (auto vec : sum_zero.find_triplets()) {

        cout << "[ ";
        for (auto element : vec) {

            cout << element << " ";
        }
        cout << "] ";
    }
    cout << "]" << endl << endl;

    cout << "Triplet Sum Close to Target" << endl;
    triptlet_sum_close_to_target triplet_close;
    cout << "triplet in the array whose sum is as close to the target number as possible is: " << triplet_close.search_triplet() << endl << endl;

    cout << "Triplets with Smaller Sum" << endl;
    triplet_with_smaller_sum triplet_smaller;
    cout << "Number of triplets s.t sum is smaller than target: " << triplet_smaller.find_tripets() << endl << endl;

    cout << "Subarrays with Product Less than a Target" << endl;
    subarray_product_less_than_k subarray;
    cout << "Subarrays whose product is less than the target number: [ ";
    for (auto vec : subarray.find_triplets()) {

        cout << "[ ";
        for (auto element : vec) {

            cout << element << " ";
        }
        cout << "] ";
    }
    cout << " ]" << endl << endl;

    cout << "Dutch National Flag Problem" << endl;
    dutch_flag d_flag;
    vector<int> res = d_flag.sort_flag();
    cout << "After sorting: [ ";
    for (auto element : res) {

        cout << element << " ";
    }
    cout << "]" << endl << endl;

    cout << "Quadruple Sum to Target" << endl;
    quadruple_sum_to_target quad_sum;
    cout << "All unique quadruplets in it, whose sum is equal to the target number: [ ";
    for (auto vec : quad_sum.search_quadriplets()) {

        cout << "[ ";
        for (auto element : vec) {

            cout << element << " ";
        }
        cout << "] ";
    }
    cout << "]" << endl << endl;
}

