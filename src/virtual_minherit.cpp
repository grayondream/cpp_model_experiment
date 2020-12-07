#include "virtual_minherit.hpp"
#include <iostream>

using namespace std;

void vbase_left::vbase_left_virtual_function1()
{
	cout << "vbase_left::vbase_left_virtual_function1" << endl;
}

void vbase_left::vbase_left_virtual_function2()
{
	cout << "vbase_left::vbase_left_virtual_function2" << endl;
}

void vbase_right::vbase_right_virtual_function1()
{
	cout << "vbase_right::vbase_right_virtual_function1" << endl;
}

void vbase_right::vbase_right_virtual_function2()
{
	cout << "vbase_right::vbase_right_virtual_function2" << endl;
}

void vminherit::vbase_left_virtual_function1()
{
	cout << "vminherit::vbase_left_virtual_function1" << endl;
}

void vminherit::vbase_right_virtual_function1()
{
	cout << "vminherit::vbase_right_virtual_function1" << endl;
}

void vminherit::vminherit_virtual_function()
{
	cout << "vminherit::vminherit_virtual_function" << endl;
}