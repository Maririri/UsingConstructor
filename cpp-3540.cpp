//
// Created by Maria.Baburina on 5/24/2017.
//

#include <thread>

//typedef std::vector<int> StdClass;
//typedef std::list<int> StdClass;
typedef std::thread StdClass;
class Derived : public StdClass {
public:
    using StdClass::StdClass; // <--- hint here saying "Can't resolve struct member 'StdClass'".
};

int main() {
    return 0;
}

