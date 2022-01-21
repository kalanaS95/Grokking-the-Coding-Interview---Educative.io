#include <iostream>
#include "Linked_list_cycle_(Easy).cpp"
#include "start_of_a_linked_list_cycle_(medium).cpp"
#include "happy_number.cpp"
#include "middle_of_linked_list.cpp"
#include "palindrome_linked_list.cpp"
#include "rearrange_linked_list.cpp"
using namespace std;

int main()
{
	cout << "LinkedList Cycle" << endl;
	linked_list_cycle(false).find_cycle_length();
	linked_list_cycle(true).find_cycle_length();
	cout << endl << endl;

	cout << "Start Node of the linked list" << endl;
	cout << "Start nod of the cycle is: " << (start_of_LL_cycle(true).cycle_start())->get_value() << endl << endl;;
		
	cout << "Happy Number" << endl;
	string res = (happy_number().is_happy_number()) ? "Yes" : "No";
	cout << "12 is a happy number: " << res << endl << endl;

	cout << "Middle of a linked list" << endl;
	cout << "Middle of the linked list is: " << ((middle_of_ll()).middle_of_the_linked_list())->get_value() << endl << endl;

	cout << "Palindrome Linked List" << endl;
	string result = (((palindrome_linked_list(false)).check_palindrome()) == true) ? "Yes" : "No";
	cout << "Linked List is a palindrome? : " << result <<endl <<endl;

	(rearrange_linked_list(false)).re_arrange_linked_list();
}

