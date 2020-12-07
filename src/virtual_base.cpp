#include "virtual_base.hpp"
#include <iostream>

using namespace std;

virtual_base::virtual_base()
{

}

virtual_base::~virtual_base()
{

}


void virtual_base::nonstatic_func()
{}

void virtual_base::virtual_func1()
{
	cout << "virtual_base::virtual_func1" << endl;
}

void virtual_base::virtual_func2()
{
	cout << "virtual_base::virtual_func2" << endl;
}

void virtual_base::virtual_func3()
{
	cout << "virtual_base::virtual_func3" << endl;
}

void virtual_base::virtual_func4()
{
	cout << "virtual_base::virtual_func4" << endl;
}