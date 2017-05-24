struct A {
    A(int value) {}
};

using A_alias = A;

struct B : A {
    using A::A;
};

struct C : A_alias { // base class 'A' doesn't have a default constructor
    using A_alias::A_alias; // can't resolve struct member 'A_alias'
};

struct D : A { // base class 'A' doesn't have a default constructor
    using base = A;
    using base::base; // can't resolve struct member 'base'
};

struct Base {
    Base(int i) {}
    Base() {}
};

typedef Base Typedef;

struct Derived : Base {
    using Typedef::Typedef;
};

struct Class1 {
    typedef int myType;
};

struct Class2: private Class1 {
    using Class1::myType;
};

Class2::myType var;

struct AS {
    AS(int) {}
};

template <class T = AS>
struct BS : public T {
    using T::T;
};

int main() {
    BS<> bs(1);

    Derived a1;
    Derived b1(1);

    B b{0};
    C c{1};
    return 0;
}