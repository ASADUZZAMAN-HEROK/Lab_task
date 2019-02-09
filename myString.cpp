#include<iostream>
#include<stdlib.h>
#include"myString.h"

myString::myString()
{
	myString::size = 100;
	myString::str = (char*)malloc(sizeof(char)*size);
}
myString::myString(int _size)
{
	myString::size = _size;
	myString::str = (char*)malloc(sizeof(char)*size);
}
bool myString::setter(char _st[])
{
	for (int i = 0; _st[i] != 0; i++)
	{
	    myString::str[i]=_st[i];
		if (i >= myString::size)
			return false;
	}
	return true;
}
void myString::print_str()
{
	for (int i = 0; i < myString::size; i++)
		std::cout << myString::str[i];
	std::cout << '\n';
	return;
}
