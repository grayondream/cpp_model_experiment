#pragma once

class vbase_left
{
public:
	int _base_left_int;
	char _base_left_ch;
public:
	virtual void vbase_left_virtual_function1();
	virtual void vbase_left_virtual_function2();
};

class vbase_right
{
public:
	int _base_right_int;
	char _base_right_ch;
public:
	virtual void vbase_right_virtual_function1();
	virtual void vbase_right_virtual_function2();
};

class vminherit : public vbase_left, public vbase_right
{
public:
	char _minherit_ch;
public:
	virtual void vminherit_virtual_function();
	virtual void vbase_left_virtual_function1();
	virtual void vbase_right_virtual_function1();
};