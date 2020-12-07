#pragma once


class virtual_base
{
public:
	virtual_base();
	~virtual_base();

	void nonstatic_func();
	virtual void virtual_func1();
	virtual void virtual_func2();
	virtual void virtual_func3();
	virtual void virtual_func4();
public:
	int _nonstatic_x;
	char _nonstatic_ch;
};

