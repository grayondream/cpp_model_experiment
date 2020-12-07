#include "virtual_inherit.hpp"
#include <iostream>

using std::cout;
using std::endl;

void virtual_inherit::virtual_func1()
{
	cout << "virtual_inherit::virtual_func1" << endl;
}

void virtual_inherit::virtual_inherit_func()
{
	cout << "virtual_inherit::virtual_inherit_func" << endl;
}