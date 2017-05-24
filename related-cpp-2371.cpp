//
// Created by Maria.Baburina on 5/24/2017.
//

using using_char_t = char;
typedef char typedef_char_t;

int main() {
    // ok
    char* p1 = new char[10];
    //  Can't resolve constructor 'using_char_t'
    using_char_t* p2 = new using_char_t[10];
    // ok
    typedef_char_t* p3 = new typedef_char_t[10];

    return 0;
}

// and its dup

#include <iostream>
#include <bits/unique_ptr.h>

typedef uint8_t old_t;
using new_t = uint8_t;

int main2()
{
    // clion parses everthing fine here
    {
        std::unique_ptr<old_t[]>   exam_ptrA { new old_t[100'000] };
        std::unique_ptr<uint8_t[]> exam_ptrC { new uint8_t[100'000] };
        std::unique_ptr<float[]>   exam_ptrB { new float[100'000] };
    }

    // clion parsing error : can't resolve constructor
    {
        std::unique_ptr<new_t[]> exam_ptrA{new new_t[100'000]};
        const new_t exam_ptrB[]{new new_t[100'000]};
    }

    return 0;
}