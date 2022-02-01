#include <iostream>
#include "cyclic_sort.cpp"
#include "find_the_missing_number.cpp"
#include "find_all_missing_numbers.cpp"
#include "find_the_duplicate_number.cpp"
#include "find_all_duplicate_numbers.cpp"
#include "find_the_corrupt_pair.cpp"
#include "find_the_smallest_missing_positive_number.cpp"
using namespace std;

int main()
{
    cout << "Cyclic Sort: " << endl;
    for (int x : (cyclic_sort()).cycle_sort()) {

        cout << x << " ";
    }
    cout << endl << endl;

    cout << "Find the missing number: " << (find_missing_number()).find_missing() <<endl <<endl;

    cout << "Find all missing numbers: ";
    for (int elem : (find_all_missing_numbers()).missing_elements()) {
        cout << elem << " ";
    }
    cout << endl << endl;

    cout << "Find the duplicate number: " << (find_the_duplicate_number()).duplicate_element() << endl << endl;

    cout << "Find all duplicate numbers: ";
    for (int elem : (find_all_duplicate_nunbers()).all_duplicates()) {
        cout << elem << " ";
    }
    cout << endl << endl;

    vector<int> m_d = (find_the_corrupt_pair()).find_missing_duplicate_pair();
    cout << "Duplicate Element: " << m_d[0] << " Missing element: " << m_d[1] << endl << endl;

    cout << "Find the smallest Missing Positive Number: " << (find_the_smallest_missing_positive_number()).smallest_missing_number() << endl << endl;

}

