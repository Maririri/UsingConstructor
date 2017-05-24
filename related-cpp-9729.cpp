//
// Created by Maria.Baburina on 5/24/2017.
//

template<typename T>
class Base0 {};

template<typename T>
class Sub0 : public Base0 <T>
{
public:
    using Base0<T>::Base0;   // Can't resolve struct member 'Base'
};
//The code compiles as expected.
//
//Here is another example, corresponding to the real-world case where I have seen this error:

template<typename T>
class Base
{
public:
    Base(int i) : i(i) {}
private:
    int i;
};

template<typename T>
class Sub : public Base <T>
{
public:
    using Base<T>::Base;
};

class Specific : public Sub<bool>
{
public:
    using Sub<bool>::Sub;     // Can't resolve struct member 'Sub'
};