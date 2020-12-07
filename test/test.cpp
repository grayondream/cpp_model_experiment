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

void test_simple_object()
{
	base b;
	cout << "��ʼ������ڴ�ģ�Ͳ���!" << endl;
	cout.setf(ios::left);
	COUT_SIZE(base, b);
	COUT_ADDR(base, b);
	COUT_VAL_ADDR(base, b, _nonstatic_x);
	COUT_VAL_ADDR(base, b, _nonstatic_ch);
	COUT_STATIC_VAL_ADDR(base, _static_x);
	COUT_STATIC_FUNC_ADDR(base, static_func);
	COUT_FUNC_ADDR(base, nonstatic_func);

	cout << "������ڴ�ģ�Ͳ��Խ���!" << endl;
}

void test_simple_virtual_object()
{
	virtual_base b;

	cout << "��ʼ�򵥰����麯��������ڴ�ģ�Ͳ���!" << endl;
	cout.setf(ios::left);
	COUT_SIZE(virtual_base, b);
	COUT_ADDR(virtual_base, b);
	COUT_VAL_ADDR(virtual_base, b, _nonstatic_x);
	COUT_VAL_ADDR(virtual_base, b, _nonstatic_ch);
	COUT_VPTR(virtual_base, b);
	//(void**)(int*)*(int**)
	void **vptr = GET_VIRTUAL_TABLE(b);
	int vir_cnt = 4;
	for (int i = 0; i < vir_cnt; i++)
	{
		cout << "��" << i << "���麯��ִ�н��:\t\t\t\t";
		virtual_func func = (virtual_func)vptr[i];
		func();
		COUT_VIRTUAL_FUNC_ADDR(virtual_base, i, func);
	}
	
	cout << "��ʼ�򵥰����麯��������ڴ�ģ�Ͳ��Խ���!" << endl;
}

void test_single_dervied()
{
	inherit b;

	cout << "��ʼ���̳м�����ڴ�ģ�Ͳ���!" << endl;
	cout.setf(ios::left);
	COUT_SIZE(inherit, b);
	COUT_ADDR(inherit, b);
	COUT_VAL_ADDR(inherit, b, base::_nonstatic_x);
	COUT_VAL_ADDR(inherit, b, base::_nonstatic_ch);
	COUT_VAL_ADDR(inherit, b, _inherit_ch);

	cout << "��ʼ���̳м�����ڴ�ģ�Ͳ��Խ���!" << endl;
}

void test_single_virtual_dervied()
{
	cout << "��ʼ���̳а����麯������ڴ�ģ�Ͳ���!" << endl;

	virtual_inherit b;
	cout.setf(ios::left);
	COUT_SIZE(virtual_inherit, b);
	COUT_ADDR(virtual_inherit, b);
	COUT_VAL_ADDR(virtual_inherit, b, virtual_base::_nonstatic_x);
	COUT_VAL_ADDR(virtual_inherit, b, virtual_base::_nonstatic_ch);
	COUT_VAL_ADDR(virtual_inherit, b, _virtual_inherit_ch);

	COUT_VPTR(virtual_inherit, b);
	void **vptr = GET_VIRTUAL_TABLE(b);
	int vir_cnt = 5;
	for (int i = 0; i < vir_cnt; i++)
	{
		cout << "��" << i << "���麯��ִ�н��:\t\t\t\t";
		virtual_func func = (virtual_func)vptr[i];
		func();
		COUT_VIRTUAL_FUNC_ADDR(virtual_base, i, func);
	}
	cout << "���̳а����麯������ڴ�ģ�Ͳ��Խ���!" << endl;
}

void test_mdervied()
{
	cout << "��ʼ��̳в������麯������ڴ�ģ�Ͳ���!" << endl;

	minherit b;
	cout.setf(ios::left);
	COUT_SIZE(minherit, b);
	COUT_ADDR(minherit, b);
	COUT_VAL_ADDR(minherit, b, base_left::_base_left_int);
	COUT_VAL_ADDR(minherit, b, base_left::_base_left_ch);
	COUT_VAL_ADDR(minherit, b, base_right::_base_right_int);
	COUT_VAL_ADDR(minherit, b, base_right::_base_right_ch);
	COUT_VAL_ADDR(minherit, b, _minherit_ch);

	
	cout << "��̳в������麯������ڴ�ģ�Ͳ��Խ���!" << endl;
}

void test_virtual_mdervied()
{
	cout << "��ʼ��̳в������麯������ڴ�ģ�Ͳ���!" << endl;

	vminherit b;
	cout.setf(ios::left);
	COUT_SIZE(vminherit, b);
	COUT_ADDR(vminherit, b);
	COUT_VAL_ADDR(vminherit, b, vbase_left::_base_left_int);
	COUT_VAL_ADDR(vminherit, b, vbase_left::_base_left_ch);
	COUT_VAL_ADDR(vminherit, b, vbase_right::_base_right_int);
	COUT_VAL_ADDR(vminherit, b, vbase_right::_base_right_ch);
	COUT_VAL_ADDR(vminherit, b, _minherit_ch);
	
	cout << "\n��һ���麯����:" << endl;
	COUT_VPTR(virtual_inherit, b);
	void **vptr = GET_VIRTUAL_TABLE(b);
	int vir_cnt = 3;
	for (int i = 0; i < vir_cnt; i++)
	{
		cout << "��" << i << "���麯��ִ�н��:\t\t\t\t";
		virtual_func func = (virtual_func)vptr[i];
		func();
		COUT_VIRTUAL_FUNC_ADDR(vminherit, i, func);
	}


	cout << "\n�ڶ����麯����:" << endl;
	long long offset = 16;
	int* vptr_snd_ab = (int*)((long long)(&b) + offset);		//�ڶ����麯����ľ��Ե�ַ
	void **vptr_snd = GET_VIRTUAL_TABLE(*vptr_snd_ab);
	cout << "����vminherit���麯�����ַ:" << setw(50) << "vminherit::vptr" << vptr_snd_ab << endl;
	vir_cnt = 2;
	for (int i = 0; i < vir_cnt; i++)
	{
		cout << "��" << i << "���麯��ִ�н��:\t\t\t\t";
		virtual_func func = (virtual_func)vptr_snd[i];
		func();
		COUT_VIRTUAL_FUNC_ADDR(vminherit, i, func);
	}

	cout << "��̳в������麯������ڴ�ģ�Ͳ��Խ���!" << endl;
}

void test_dimond_inherit()
{
	cout << "��ʼ�������麯�������μ̳�����ڴ�ģ�Ͳ���!" << endl;

	child b;
	cout.setf(ios::left);
	COUT_SIZE(child, b);
	COUT_ADDR(child, b);
	COUT_VAL_ADDR(child, b, father::grand::_grand_x);
	COUT_VAL_ADDR(child, b, father::grand::_grand_ch);
	COUT_VAL_ADDR(child, b, father::_father_ch);

	COUT_VAL_ADDR(child, b, mother::grand::_grand_x);
	COUT_VAL_ADDR(child, b, mother::grand::_grand_ch);
	COUT_VAL_ADDR(child, b, mother::_mother_ch);

	COUT_VAL_ADDR(child, b, _child_ch);

	cout << "�������麯�������μ̳�����ڴ�ģ�Ͳ��Խ���!" << endl;
	
}


void test_vdimond_inherit()
{
	cout << "��ʼ�����麯�������μ̳�����ڴ�ģ�Ͳ���!" << endl;

	vchild b;
	cout.setf(ios::left);
	COUT_SIZE(vchild, b);
	COUT_ADDR(vchild, b);
	COUT_VAL_ADDR(vchild, b, vfather::vgrand::_vgrand_x);
	COUT_VAL_ADDR(vchild, b, vfather::vgrand::_vgrand_ch);
	COUT_VAL_ADDR(vchild, b, vfather::_vfather_ch);

	COUT_VAL_ADDR(vchild, b, vmother::vgrand::_vgrand_x);
	COUT_VAL_ADDR(vchild, b, vmother::vgrand::_vgrand_ch);
	COUT_VAL_ADDR(vchild, b, vmother::_vmother_ch);

	COUT_VAL_ADDR(vchild, b, _vchild_ch);

	cout << "\n��һ���麯����:" << endl;
	long long offset = 16;
	int* pvptr = (int*)((long long)(&b) + offset);		//�ڶ����麯����ľ��Ե�ַ
	void **vptr = GET_VIRTUAL_TABLE(*pvptr);
	cout << "����vchild���麯�����ַ:" << setw(50) << "vchild::vptr" << vptr << endl;
	int vir_cnt = 7;
	for (int i = 0; i < vir_cnt; i++)
	{
		cout << "��" << i << "���麯��ִ�н��:\t\t\t\t";
		virtual_func func = (virtual_func)vptr[i];
		func();
		COUT_VIRTUAL_FUNC_ADDR(vchild, i, func);
	}


	cout << "\n�ڶ����麯����:" << endl;
	offset = 40;
	pvptr = (int*)((long long)(&b) + offset);		//�ڶ����麯����ľ��Ե�ַ
	vptr = GET_VIRTUAL_TABLE(*pvptr);
	cout << "����vchild���麯�����ַ:" << setw(50) << "vchild::vptr" << vptr << endl;
	vir_cnt = 7;
	for (int i = 0; i < vir_cnt; i++)
	{
		cout << "��" << i << "���麯��ִ�н��:\t\t\t\t";
		virtual_func func = (virtual_func)vptr[i];
		func();
		COUT_VIRTUAL_FUNC_ADDR(vchild, i, func);
	}
	cout << "�����麯�������μ̳�����ڴ�ģ�Ͳ��Խ���!" << endl;
}

void test_vdimond_vinherit()
{
	cout << "��ʼ�����麯�������μ̳�����ڴ�ģ�Ͳ���!" << endl;

	vchild b;
	cout.setf(ios::left);
	COUT_SIZE(vchild, b);
	COUT_ADDR(vchild, b);
	COUT_VAL_ADDR(vchild, b, vfather::vgrand::_vgrand_x);
	COUT_VAL_ADDR(vchild, b, vfather::vgrand::_vgrand_ch);
	COUT_VAL_ADDR(vchild, b, vfather::_vfather_ch);

	COUT_VAL_ADDR(vchild, b, vmother::vgrand::_vgrand_x);
	COUT_VAL_ADDR(vchild, b, vmother::vgrand::_vgrand_ch);
	COUT_VAL_ADDR(vchild, b, vmother::_vmother_ch);

	COUT_VAL_ADDR(vchild, b, _vchild_ch);

	cout << "\n��һ���麯����:" << endl;
	long long offset = 0;
	int* pvptr = (int*)((long long)(&b) + offset);		//�ڶ����麯����ľ��Ե�ַ
	void **vptr = GET_VIRTUAL_TABLE(*pvptr);
	cout << "����vchild���麯�����ַ:" << setw(50) << "vchild::vptr" << vptr << endl;
	int vir_cnt = 7;
	for (int i = 0; i < vir_cnt; i++)
	{
		cout << "��" << i << "���麯��ִ�н��:\t\t\t\t";
		virtual_func func = (virtual_func)vptr[i];
		func();
		COUT_VIRTUAL_FUNC_ADDR(vchild, i, func);
	}


	cout << "\n�ڶ����麯����:" << endl;
	offset = 24;
	pvptr = (int*)((long long)(&b) + offset);		//�ڶ����麯����ľ��Ե�ַ
	vptr = GET_VIRTUAL_TABLE(*pvptr);
	cout << "����vchild���麯�����ַ:" << setw(50) << "vchild::vptr" << vptr << endl;
	vir_cnt = 7;
	for (int i = 0; i < vir_cnt; i++)
	{
		cout << "��" << i << "���麯��ִ�н��:\t\t\t\t";
		virtual_func func = (virtual_func)vptr[i];
		func();
		COUT_VIRTUAL_FUNC_ADDR(vchild, i, func);
	}
	cout << "�����麯�������μ̳�����ڴ�ģ�Ͳ��Խ���!" << endl;
}