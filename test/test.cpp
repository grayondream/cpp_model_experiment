#include "test.hpp"
#include "base.hpp"
#include "virtual_base.hpp"
#include "inherit.hpp"
#include "virtual_inherit.hpp"
#include "minherit.hpp"
#include "virtual_minherit.hpp"
#include "diamond_inherit.hpp"
#include "type_info.hpp"
#include "vdiamond_inherit.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

/**
 *  需要注意的是，代码中包含虚函数探测的代码需要根据具体的代码修改offset，同时修改虚函数的个数
 */

/**
 * 普通类：分为包含虚函数和不包含虚函数
 */

void test_simple_object()
{
	base b;
	cout << "开始简单类别内存模型测试!" << endl;
	cout.setf(ios::left);
	COUT_SIZE(base, b);
	COUT_ADDR(base, b);
	COUT_VAL_ADDR(base, b, _nonstatic_x);
	COUT_VAL_ADDR(base, b, _nonstatic_ch);
	COUT_STATIC_VAL_ADDR(base, _static_x);
	//COUT_STATIC_FUNC_ADDR(base, static_func);
	//COUT_FUNC_ADDR(base, nonstatic_func);

	cout << "简单类别内存模型测试结束!" << endl;
}

void test_simple_virtual_object()
{
	virtual_base b;

	cout << "开始简单包含虚函数的类的内存模型测试!" << endl;
	cout.setf(ios::left);
	COUT_SIZE(virtual_base, b);
	COUT_ADDR(virtual_base, b);
	COUT_VAL_ADDR(virtual_base, b, _nonstatic_x);
	COUT_VAL_ADDR(virtual_base, b, _nonstatic_ch);
	//(void**)(int*)*(int**)
	COUT_VPTR(virtual_base, 1, &b);
	void **vptr = GET_VIRTUAL_TABLE(b);
	int vir_cnt = 4;
	for (int i = 0; i < vir_cnt; i++)
	{
		cout << "第" << i << "个虚函数执行结果:\t\t\t\t";
		virtual_func func = (virtual_func)vptr[i];
		func();
		COUT_VIRTUAL_FUNC_ADDR(virtual_base, i, (void*)func);
	}
	
	cout << "开始简单包含虚函数的类的内存模型测试结束!" << endl;
}

/**
 * 单继承：分为包含虚函数和不包含虚函数
 */

void test_single_dervied()
{
	inherit b;

	cout << "开始单继承简单类的内存模型测试!" << endl;
	cout.setf(ios::left);
	COUT_SIZE(inherit, b);
	COUT_ADDR(inherit, b);
	COUT_VAL_ADDR(inherit, b, base::_nonstatic_x);
	COUT_VAL_ADDR(inherit, b, base::_nonstatic_ch);
	COUT_VAL_ADDR(inherit, b, _inherit_ch);

	cout << "开始单继承简单类的内存模型测试结束!" << endl;
}

void test_single_virtual_dervied()
{
	cout << "开始单继承包含虚函数类的内存模型测试!" << endl;

	virtual_inherit b;
	cout.setf(ios::left);
	COUT_SIZE(virtual_inherit, b);
	COUT_ADDR(virtual_inherit, b);
	COUT_VAL_ADDR(virtual_inherit, b, virtual_base::_nonstatic_x);
	COUT_VAL_ADDR(virtual_inherit, b, virtual_base::_nonstatic_ch);
	COUT_VAL_ADDR(virtual_inherit, b, _virtual_inherit_ch);

	COUT_VPTR(virtual_inherit, 1, &b);
	void **vptr = GET_VIRTUAL_TABLE(b);
	int vir_cnt = 5;
	for (int i = 0; i < vir_cnt; i++)
	{
		cout << "第" << i << "个虚函数执行结果:\t\t\t\t";
		virtual_func func = (virtual_func)vptr[i];
		func();
		COUT_VIRTUAL_FUNC_ADDR(virtual_base, i, (void*)func);
	}

	cout << "单继承包含虚函数类的内存模型测试结束!" << endl;
}


/**
 * 多继承：分为包含虚函数和不包含虚函数
 */

void test_mdervied()
{
	cout << "开始多继承不包含虚函数类的内存模型测试!" << endl;

	minherit b;
	cout.setf(ios::left);
	COUT_SIZE(minherit, b);
	COUT_ADDR(minherit, b);
	COUT_VAL_ADDR(minherit, b, base_left::_base_left_int);
	COUT_VAL_ADDR(minherit, b, base_left::_base_left_ch);
	COUT_VAL_ADDR(minherit, b, base_right::_base_right_int);
	COUT_VAL_ADDR(minherit, b, base_right::_base_right_ch);
	COUT_VAL_ADDR(minherit, b, _minherit_ch);

	
	cout << "多继承不包含虚函数类的内存模型测试结束!" << endl;
}

void test_virtual_mdervied()
{
	cout << "开始多继承包含虚函数类的内存模型测试!" << endl;

	vminherit b;
	cout.setf(ios::left);
	COUT_SIZE(vminherit, b);
	COUT_ADDR(vminherit, b);
	COUT_VAL_ADDR(vminherit, b, vbase_left::_base_left_int);
	COUT_VAL_ADDR(vminherit, b, vbase_left::_base_left_ch);
	COUT_VAL_ADDR(vminherit, b, vbase_right::_base_right_int);
	COUT_VAL_ADDR(vminherit, b, vbase_right::_base_right_ch);
	COUT_VAL_ADDR(vminherit, b, _minherit_ch);
	
	cout << "\n第一个虚函数表:" << endl;
	COUT_VPTR(vminherit, 1, &b);
	void **vptr = GET_VIRTUAL_TABLE(b);
	int vir_cnt = 4;
	for (int i = 0; i < vir_cnt; i++)
	{
		cout << "第" << i << "个虚函数执行结果:\t\t\t\t";
		virtual_func func = (virtual_func)vptr[i];
		func();
		COUT_VIRTUAL_FUNC_ADDR(vminherit, i, func);
	}


	cout << "\n第二个虚函数表:" << endl;
	
	long long offset = 16;
	int* vptr_snd_ab = (int*)((long long)(&b) + offset);		//第二个虚函数表的绝对地址
	COUT_VPTR(vminherit, 2, vptr_snd_ab);
	void **vptr_snd = GET_VIRTUAL_TABLE(*vptr_snd_ab);
	vir_cnt = 2;
	for (int i = 0; i < vir_cnt; i++)
	{
		cout << "第" << i << "个虚函数执行结果:\t\t\t\t";
		virtual_func func = (virtual_func)vptr_snd[i];
		func();
		COUT_VIRTUAL_FUNC_ADDR(vminherit, i, func);
	}

	cout << "多继承包含虚函数类的内存模型测试结束!" << endl;
}

/**
 * 菱形继承：分为包含虚函数和不包含虚函数
 * 菱形继承测试中，是否使用虚继承直接修改代码，而不会建立特定的测试类
 */
void test_dimond_inherit()
{
	cout << "开始不包含虚函数的菱形继承类的内存模型测试!" << endl;

	child b;
	cout.setf(ios::left);
	COUT_SIZE(child, b);
	COUT_ADDR(child, b);
	COUT_VAL_ADDR(child, b, father::_grand_x);
	COUT_VAL_ADDR(child, b, father::_grand_ch);
	COUT_VAL_ADDR(child, b, father::_father_ch);

	COUT_VAL_ADDR(child, b, mother::_grand_x);
	COUT_VAL_ADDR(child, b, mother::_grand_ch);
	COUT_VAL_ADDR(child, b, mother::_mother_ch);

	COUT_VAL_ADDR(child, b, _child_ch);

	cout << "不包含虚函数的菱形继承类的内存模型测试结束!" << endl;
	
}


void test_vdimond_inherit()
{
	cout << "开始包含虚函数的菱形继承类的内存模型测试!" << endl;

	vchild b;
	cout.setf(ios::left);
	COUT_SIZE(vchild, b);
	COUT_ADDR(vchild, b);
	COUT_VAL_ADDR(vchild, b, vfather::_vgrand_x);
	COUT_VAL_ADDR(vchild, b, vfather::_vgrand_ch);
	COUT_VAL_ADDR(vchild, b, vfather::_vfather_ch);

	COUT_VAL_ADDR(vchild, b, vmother::_vgrand_x);
	COUT_VAL_ADDR(vchild, b, vmother::_vgrand_ch);
	COUT_VAL_ADDR(vchild, b, vmother::_vmother_ch);

	COUT_VAL_ADDR(vchild, b, _vchild_ch);

	cout << "\n第一个虚函数表:" << endl;
	long long offset = 0;
	int* pvptr = (int*)((long long)(&b) + offset);		//第二个虚函数表的绝对地址
	COUT_VPTR(vchild, 1, pvptr);
	void **vptr = GET_VIRTUAL_TABLE(*pvptr);
	int vir_cnt = 7;
	for (int i = 0; i < vir_cnt; i++)
	{
		cout << "第" << i << "个虚函数执行结果:\t\t\t\t";
		virtual_func func = (virtual_func)vptr[i];
		func();
		COUT_VIRTUAL_FUNC_ADDR(vchild, i, func);
	}


	cout << "\n第二个虚函数表:" << endl;
	offset = 16;
	pvptr = (int*)((long long)(&b) + offset);		//第二个虚函数表的绝对地址
	COUT_VPTR(vchild, 1, pvptr);
	vptr = GET_VIRTUAL_TABLE(*pvptr);
	vir_cnt = 7;
	for (int i = 0; i < vir_cnt; i++)
	{
		cout << "第" << i << "个虚函数执行结果:\t\t\t\t";
		virtual_func func = (virtual_func)vptr[i];
		func();
		COUT_VIRTUAL_FUNC_ADDR(vchild, i, func);
	}
	cout << "包含虚函数的菱形继承类的内存模型测试结束!" << endl;
}

void test_vdimond_vinherit()
{
		cout << "开始包含虚函数的菱形虚继承类的内存模型测试!" << endl;

	vchild b;
	cout.setf(ios::left);
	COUT_SIZE(vchild, b);
	COUT_ADDR(vchild, b);
	COUT_VAL_ADDR(vchild, b, vfather::_vgrand_x);
	COUT_VAL_ADDR(vchild, b, vfather::_vgrand_ch);
	COUT_VAL_ADDR(vchild, b, vfather::_vfather_ch);

	COUT_VAL_ADDR(vchild, b, vmother::_vgrand_x);
	COUT_VAL_ADDR(vchild, b, vmother::_vgrand_ch);
	COUT_VAL_ADDR(vchild, b, vmother::_vmother_ch);

	COUT_VAL_ADDR(vchild, b, _vchild_ch);

	cout << "\n第一个虚函数表:" << endl;
	long long offset = 0;
	int* pvptr = (int*)((long long)(&b) + offset);		//第二个虚函数表的绝对地址
	COUT_VPTR(vchild, 1, pvptr);

	void **vptr = GET_VIRTUAL_TABLE(*pvptr);
	int vir_cnt = 6;
	for (int i = 0; i < vir_cnt; i++)
	{
		cout << "第" << i << "个虚函数执行结果:\t\t\t\t";
		virtual_func func = (virtual_func)vptr[i];
		func();
		COUT_VIRTUAL_FUNC_ADDR(vchild, i, func);
	}


	cout << "\n第二个虚函数表:" << endl;
	offset = 16;
	pvptr = (int*)((long long)(&b) + offset);		//第二个虚函数表的绝对地址
	COUT_VPTR(vchild, 2, pvptr);
	vptr = GET_VIRTUAL_TABLE(*pvptr);
	vir_cnt =4;
	for (int i = 0; i < vir_cnt; i++)
	{
		cout << "第" << i << "个虚函数执行结果:\t\t\t\t";
		virtual_func func = (virtual_func)vptr[i];
		func();
		COUT_VIRTUAL_FUNC_ADDR(vchild, i, func);
	}

	cout << "\n第三个虚函数表:" << endl;
	offset = 32;
	pvptr = (int*)((long long)(&b) + offset);		//第二个虚函数表的绝对地址
	COUT_VPTR(vchild, 3, pvptr);
	vptr = GET_VIRTUAL_TABLE(*pvptr);
	vir_cnt = 5;
	for (int i = 0; i < vir_cnt; i++)
	{
		cout << "第" << i << "个虚函数执行结果:\t\t\t\t";
		virtual_func func = (virtual_func)vptr[i];
		func();
		COUT_VIRTUAL_FUNC_ADDR(vchild, i, func);
	}
	cout << "包含虚函数的菱形虚继承类的内存模型测试结束!" << endl;
}