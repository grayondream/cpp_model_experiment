#ifndef __TEST__HPP__
#define __TEST__HPP__

/*!
 * \brief 输出格式化相关的宏定义
 *
 * \author ares
 * \date 十二月 2020
 * 
 */ 
#define STD_OUT cout<<setw(80)
#define OBJECT_TOS(class_name, val) setw(50)<<#class_name"::"#val
typedef void(*virtual_func)();

#define GET_VIRTUAL_TABLE(instance) (void**)(int*)*(int**)(&instance)
#define COUT_VPTR(class_name, instance) STD_OUT<<"对象"#class_name"的虚函数表地址:"<<setw(50)<<#class_name"::vptr"<<(int*)(&instance)<<endl;
#define COUT_VIRTUAL_FUNC_ADDR(class_name, i, func) cout<<"对象"#class_name"的第"<<i<<"个虚函数地址:\t\t"<<func<<endl;

#define COUT_SIZE(class_name, instance) STD_OUT<<"对象"#class_name"的实例"#instance"的大小为:"<<sizeof(instance)<<endl;
#define COUT_ADDR(class_name, instance) STD_OUT<<"对象"#class_name"的实例"#instance"的地址:"<<&instance<<endl;
#define COUT_VAL_ADDR(class_name, instance, val) STD_OUT<<"对象"#class_name"的实例"#instance"的成员变量"#val"的地址:"<<OBJECT_TOS(class_name, val)<<(void*)&(instance.val)<<endl;
#define COUT_STATIC_VAL_ADDR(class_name, val) STD_OUT<<"对象"#class_name"的静态成员变量"#val"的地址:"<<OBJECT_TOS(class_name, val)<<&(class_name::val)<<endl;
#define COUT_FUNC_ADDR(class_name, func) STD_OUT<<"对象"#class_name"的成员函数"#func"的地址:"<<OBJECT_TOS(class_name, func)<<&(class_name::func)<<endl;
#define COUT_STATIC_FUNC_ADDR(class_name, func) STD_OUT<<"对象"#class_name"的成员函数"#func"地址:"<<OBJECT_TOS(class_name, func)<<&(class_name::func)<<endl;
/*!
 * \brief 测试简单类别的内存模型
 *
 * \author ares
 * \date 十二月 2020
 * 
 */ 
void test_simple_object();

/*!
 * \brief 测试简单包含虚函数的对象的内存模型
 *
 * \author ares
 * \date 十二月 2020
 * 
 */ 
void test_simple_virtual_object();

/*!
 * \brief 单继承内存模型测试
 *
 * \author ares
 * \date 十二月 2020
 * 
 */ 
void test_single_dervied();

/*!
 * \brief 单继承中存在虚函数内存模型测试
 *
 * \author ares
 * \date 十二月 2020
 * 
 */ 
void test_single_virtual_dervied();

/*!
* \brief 多继承不存在虚函数的内存结构
*
* \author ares
* \date 十二月 2020
*
*/
void test_mdervied();

/*!
* \brief 多继承存在虚函数的内存结构
*
* \author ares
* \date 十二月 2020
*
*/
void test_virtual_mdervied();

/*!
* \brief 无虚函数的菱形继承
*
* \author ares
* \date 十二月 2020
*
*/
void test_dimond_inherit();


/*!
* \brief 包含虚函数的菱形继承
*
* \author ares
* \date 十二月 2020
*
*/
void test_vdimond_inherit();

/*!
* \brief 包含虚函数的菱形虚继承
*
* \author ares
* \date 十二月 2020
*
*/
void test_vdimond_vinherit();

#endif