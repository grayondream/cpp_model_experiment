#include "base.hpp"


int base::_static_x = 10;

base::base()
{
	_nonstatic_x = 77;
	_nonstatic_ch = 'a';
}

base::~base()
{

}

void base::nonstatic_func()
{

}

void base::static_func()
{

}