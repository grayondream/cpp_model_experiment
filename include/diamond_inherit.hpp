#pragma  once

class grand
{
public:
	int _grand_x;
	char _grand_ch;
};

class father : virtual public grand
{
public:
	char _father_ch;
};

class mother : virtual public grand
{
public:
	char _mother_ch;
};

class child :  public mother,  public father
{
public:
	char _child_ch;
};