#pragma  once

class grand
{
public:
	int _grand_x;
	char _grand_ch;
};

class father : public grand
{
public:
	char _father_ch;
};

class mother : public grand
{
public:
	char _mother_ch;
};

class child : virtual public mother, virtual public father
{
public:
	char _child_ch;
};