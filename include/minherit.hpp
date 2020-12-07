#pragma once

class base_left
{
public:
	int _base_left_int;
	char _base_left_ch;
};

class base_right
{
public:
	int _base_right_int;
	char _base_right_ch;
};

class minherit: public base_right, public base_left
{
public:
	char _minherit_ch;
};