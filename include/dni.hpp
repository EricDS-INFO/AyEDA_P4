#pragma once

#include <iostream>
#include <cstdlib>


class dni
{
private:
    int value_;
    int length_;
public:
    dni();
    dni(int seed);
    ~dni();

    inline int value() { return value_; }
    inline int length() { return length_; }

    friend std::ostream& operator<< (std::ostream& os, dni dni_t);
    //dni operator== (dni r_value);
    //operator unsigned long();
};
