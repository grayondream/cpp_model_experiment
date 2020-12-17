#pragma  once
#include "virtual_base.hpp"


class virtual_inherit : public virtual_base
{
public:
	char _virtual_inherit_ch;
public:
	virtual void virtual_func1();
	virtual void virtual_inherit_func();
};

