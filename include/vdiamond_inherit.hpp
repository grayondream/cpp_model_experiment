#pragma  once

class vgrand
{
public:
	virtual void vgrand_virtual_func1();
	virtual void vgrand_virtual_func2();
	virtual void vgrand_virtual_func3();
	virtual void vgrand_virtual_func4();
	virtual void vgrand_virtual_func5();
public:
	int _vgrand_x;
	char _vgrand_ch;
};

class vfather :  virtual public vgrand
{
public:
	virtual void vfather_virtual_func1();
	virtual void vfather_virtual_func2();
	virtual void vgrand_virtual_func1();
	virtual void vgrand_virtual_func3();
public:
	char _vfather_ch;
};

class vmother :  virtual public vgrand
{
public:
	virtual void vmother_virtual_func1();
	virtual void vmother_virtual_func2();
	virtual void vgrand_virtual_func2();
	virtual void vgrand_virtual_func3();
public:
	char _vmother_ch;
};

class vchild : public vmother, public vfather
{
public:
	void vchild_virtual_func();
	virtual void vgrand_virtual_func4();
	virtual void vfather_virtual_func1();
	virtual void vmother_virtual_func1();
	virtual void vgrand_virtual_func3();			//如果不对当前函数进行重写，则编译器并无知道运行时应该调用vmother::vgrand_virtual_func3还是vfather::vgrand_virtaul_func3
public:
	char _vchild_ch;
};