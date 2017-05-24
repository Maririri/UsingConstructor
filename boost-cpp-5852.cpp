//
// Created by Maria.Baburina on 5/24/2017.
//

struct Base {
    Base();
    Base(int);
};

struct Optional : Base {
    typedef Base _Base;
    using _Base::_Base;
};

Optional foo() {
    return 1;
}

#include <boost/optional.hpp>

void test123(const boost::optional<int> &x) {
    test123(42); // HERE
}
//From CPP-3256:

#include <experimental/optional>

std::experimental::optional<int> foo(const bool really) {
    if (really) {
        return 1; // here!
    } else {
        return std::experimental::nullopt; // here!
    }
}