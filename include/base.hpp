/*!
 * \brief 普通的类，只包含静态函数，非静态函数，静态成员变量和非静态成员变量，其中添加char变量是为了查看内存对齐
 *
 * \author grayondream
 * \date 十二月 2020
 * 
 */ 
#pragma once
class base
{
public:
	base();
	~base();

	static void static_func();
	void nonstatic_func();
public:
	int _nonstatic_x;
	static int _static_x;
	char _nonstatic_ch;
};

