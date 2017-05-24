//
// Created by Maria.Baburina on 5/24/2017.
//

struct Parent {
    Parent(const char *) {
    }
};

struct Child : Parent {
    using MyParent = Parent;
    using MyParent::MyParent;
};

void foo() {
    Child c("xxx");
}