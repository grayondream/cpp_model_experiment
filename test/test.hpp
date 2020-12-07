#ifndef __TEST__HPP__
#define __TEST__HPP__

/*!
 * \brief �����ʽ����صĺ궨��
 *
 * \author ares
 * \date ʮ���� 2020
 * 
 */ 
#define STD_OUT cout<<setw(80)
#define OBJECT_TOS(class_name, val) setw(50)<<#class_name"::"#val
typedef void(*virtual_func)();

#define GET_VIRTUAL_TABLE(instance) (void**)(int*)*(int**)(&instance)
#define COUT_VPTR(class_name, instance) STD_OUT<<"����"#class_name"���麯�����ַ:"<<setw(50)<<#class_name"::vptr"<<(int*)(&instance)<<endl;
#define COUT_VIRTUAL_FUNC_ADDR(class_name, i, func) cout<<"����"#class_name"�ĵ�"<<i<<"���麯����ַ:\t\t"<<func<<endl;

#define COUT_SIZE(class_name, instance) STD_OUT<<"����"#class_name"��ʵ��"#instance"�Ĵ�СΪ:"<<sizeof(instance)<<endl;
#define COUT_ADDR(class_name, instance) STD_OUT<<"����"#class_name"��ʵ��"#instance"�ĵ�ַ:"<<&instance<<endl;
#define COUT_VAL_ADDR(class_name, instance, val) STD_OUT<<"����"#class_name"��ʵ��"#instance"�ĳ�Ա����"#val"�ĵ�ַ:"<<OBJECT_TOS(class_name, val)<<(void*)&(instance.val)<<endl;
#define COUT_STATIC_VAL_ADDR(class_name, val) STD_OUT<<"����"#class_name"�ľ�̬��Ա����"#val"�ĵ�ַ:"<<OBJECT_TOS(class_name, val)<<&(class_name::val)<<endl;
#define COUT_FUNC_ADDR(class_name, func) STD_OUT<<"����"#class_name"�ĳ�Ա����"#func"�ĵ�ַ:"<<OBJECT_TOS(class_name, func)<<&(class_name::func)<<endl;
#define COUT_STATIC_FUNC_ADDR(class_name, func) STD_OUT<<"����"#class_name"�ĳ�Ա����"#func"��ַ:"<<OBJECT_TOS(class_name, func)<<&(class_name::func)<<endl;
/*!
 * \brief ���Լ������ڴ�ģ��
 *
 * \author ares
 * \date ʮ���� 2020
 * 
 */ 
void test_simple_object();

/*!
 * \brief ���Լ򵥰����麯���Ķ�����ڴ�ģ��
 *
 * \author ares
 * \date ʮ���� 2020
 * 
 */ 
void test_simple_virtual_object();

/*!
 * \brief ���̳��ڴ�ģ�Ͳ���
 *
 * \author ares
 * \date ʮ���� 2020
 * 
 */ 
void test_single_dervied();

/*!
 * \brief ���̳��д����麯���ڴ�ģ�Ͳ���
 *
 * \author ares
 * \date ʮ���� 2020
 * 
 */ 
void test_single_virtual_dervied();

/*!
* \brief ��̳в������麯�����ڴ�ṹ
*
* \author ares
* \date ʮ���� 2020
*
*/
void test_mdervied();

/*!
* \brief ��̳д����麯�����ڴ�ṹ
*
* \author ares
* \date ʮ���� 2020
*
*/
void test_virtual_mdervied();

/*!
* \brief ���麯�������μ̳�
*
* \author ares
* \date ʮ���� 2020
*
*/
void test_dimond_inherit();


/*!
* \brief �����麯�������μ̳�
*
* \author ares
* \date ʮ���� 2020
*
*/
void test_vdimond_inherit();

/*!
* \brief �����麯����������̳�
*
* \author ares
* \date ʮ���� 2020
*
*/
void test_vdimond_vinherit();

#endif