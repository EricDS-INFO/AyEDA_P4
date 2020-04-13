#pragma once

#include <iostream>
#include <cstdlib>
#include "counter.hpp"

class dni
{
private:
    int             value_;
    int             length_;
    static counter  stat_c_;
public:

    

    dni();
    dni(int seed);
    ~dni();

    inline int value() { return value_; }
    inline int nth_compare(); 
    inline void set_none(void){ value_ = -1;}
    inline int length() { return length_; }

    friend std::ostream& operator<< (std::ostream& os, dni& dni_t);
    bool operator== (dni& r_value);
    bool operator!= (dni& r_value);
    bool operator> (dni& r_value);
    bool operator< (dni& r_value);
    bool operator>= (dni& r_value);
    bool operator<= (dni& r_value);
    
    //operator unsigned long();
};
