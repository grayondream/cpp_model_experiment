#include "vdiamond_inherit.hpp"
#include <iostream>
using namespace std;

void vgrand::vgrand_virtual_func1()
{
	cout << __FUNCTION__ << endl;
}

void vgrand::vgrand_virtual_func2()
{
	cout << __FUNCTION__ << endl;
}

void vgrand::vgrand_virtual_func3()
{
	cout << __FUNCTION__ << endl;
}

void vgrand::vgrand_virtual_func4()
{
	cout << __FUNCTION__ << endl;
}

void vgrand::vgrand_virtual_func5()
{
	cout << __FUNCTION__ << endl;
}

void vfather::vfather_virtual_func1()
{
	cout << __FUNCTION__ << endl;
}

void vfather::vfather_virtual_func2()
{
	cout << __FUNCTION__ << endl;
}

void vfather::vgrand_virtual_func1()
{
	cout << __FUNCTION__ << endl;
}

void vfather::vgrand_virtual_func3()
{
	cout << __FUNCTION__ << endl;
}

void vmother::vmother_virtual_func1()
{
	cout << __FUNCTION__ << endl;
}

void vmother::vmother_virtual_func2()
{
	cout << __FUNCTION__ << endl;
}

void vmother::vgrand_virtual_func2()
{
	cout << __FUNCTION__ << endl;
}

void vmother::vgrand_virtual_func3()
{
	cout << __FUNCTION__ << endl;
}

void vchild::vchild_virtual_func()
{
	cout << __FUNCTION__ << endl;
}

void vchild::vfather_virtual_func1()
{
	cout << __FUNCTION__ << endl;
}

void vchild::vgrand_virtual_func4()
{
	cout << __FUNCTION__ << endl;
}

void vchild::vmother_virtual_func1()
{
	cout << __FUNCTION__ << endl;
}