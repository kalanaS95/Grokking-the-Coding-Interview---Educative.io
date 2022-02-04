#include <iostream>
#include "reverse_a_linked_list.cpp"
#include "reverse_a_sublist.cpp"
#include "reverse_every_k_element_sublist.cpp"
using namespace std;

int main()
{
    cout << "Reverse a Linked List" << endl << endl;
    (reverse_a_linked_list()).print_reversed_list();
    cout << endl;

    cout << "Reverse a sublist: " << endl << endl;
    (reverse_a_sublist()).print_results(3, 5);
    cout << endl << endl;

    cout << "Reverse every k element sublist" << endl;
    (reverse_every_k_element_sublist()).print_reversed_k_sublists(4);
    cout << endl;
}
