/*!
 * \brief ��ͨ���ֻ࣬������̬�������Ǿ�̬��������̬��Ա�����ͷǾ�̬��Ա�������������char������Ϊ�˲鿴�ڴ����
 *
 * \author grayondream
 * \date ʮ���� 2020
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

