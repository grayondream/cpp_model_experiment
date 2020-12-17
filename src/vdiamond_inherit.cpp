#include "vdiamond_inherit.hpp"
#include <iostream>
using namespace std;

void vgrand::vgrand_virtual_func1()
{
	cout<<"vgrand::";
	cout << __FUNCTION__ << endl;
}

void vgrand::vgrand_virtual_func2()
{
	cout<<"vgrand::";
	cout << __FUNCTION__ << endl;
}

void vgrand::vgrand_virtual_func3()
{
	cout<<"vgrand::";
	cout << __FUNCTION__ << endl;
}

void vgrand::vgrand_virtual_func4()
{
	cout<<"vgrand::";
	cout << __FUNCTION__ << endl;
}

void vgrand::vgrand_virtual_func5()
{
	cout<<"vgrand::";
	cout << __FUNCTION__ << endl;
}

void vfather::vfather_virtual_func1()
{
	cout<<"vfather::";
	cout << __FUNCTION__ << endl;
}

void vfather::vfather_virtual_func2()
{
	cout<<"vfather::";
	cout << __FUNCTION__ << endl;
}

void vfather::vgrand_virtual_func1()
{
	cout<<"vfather::";
	cout << __FUNCTION__ << endl;
}

void vfather::vgrand_virtual_func3()
{
	cout<<"vfather::";
	cout << __FUNCTION__ << endl;
}

void vmother::vmother_virtual_func1()
{
	cout<<"vmother::";
	cout << __FUNCTION__ << endl;
}

void vmother::vmother_virtual_func2()
{
	cout<<"vmother::";
	cout << __FUNCTION__ << endl;
}

void vmother::vgrand_virtual_func2()
{
	cout<<"vmother::";
	cout << __FUNCTION__ << endl;
}

void vmother::vgrand_virtual_func3()
{
	cout<<"vmother::";
	cout << __FUNCTION__ << endl;
}

void vchild::vchild_virtual_func()
{
	cout<<"vchild::";
	cout << __FUNCTION__ << endl;
}

void vchild::vfather_virtual_func1()
{
	cout<<"vchild::";
	cout << __FUNCTION__ << endl;
}

void vchild::vgrand_virtual_func4()
{
	cout<<"vchild::";
	cout << __FUNCTION__ << endl;
}

void vchild::vmother_virtual_func1()
{
	cout<<"vchild::";
	cout << __FUNCTION__ << endl;
}

void vchild::vgrand_virtual_func3()
{
	cout<<"vchild::";
	cout << __FUNCTION__ << endl;
}