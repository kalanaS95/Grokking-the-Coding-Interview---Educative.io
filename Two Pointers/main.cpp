#include <iostream>
#include "Pair_with_target_sum_(Easy).cpp"
#include "Remove_duplicates_(Easy).cpp"
#include "Squaring_a_sorted_array_(Easy).cpp"
#include "Triplet_sum_to_zero_(Medium).cpp"
#include "Triplet_sum_close_to_target_(Medium).cpp"
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
}

