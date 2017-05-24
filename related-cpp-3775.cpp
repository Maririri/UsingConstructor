//
// Created by Maria.Baburina on 5/24/2017.
//

#include <stdexcept>

class my_exception : public std::runtime_error {
public:
    // Editor complains about this, but shouldn't:
    using runtime_error::runtime_error;

    // This is recognized fine:
    // using std::runtime_error::runtime_error;
};