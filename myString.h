#ifndef MYSTRING_H
#define MYSTRING_H
#include<iostream>

class myString
{
private:
    int size;
    char *str;
public:
    bool setter(char _st[]);
    myString();
    myString(int _size);
    void print_str();


};

#endif // MYSTRING_H
