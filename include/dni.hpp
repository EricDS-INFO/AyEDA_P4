#pragma once

#include <iostream>
#include <cstdlib>

class counter;
class dni
{
    private:
        int             value_;
        int             length_;
        static counter  cntr_;
    
    public: 
        dni();
        dni(int seed);
        ~dni();

        inline int value() { return value_; }
        static int nth_compare(); 
        inline void set_none(void){ value_ = -1;}
        inline int length() { return length_; }

        friend std::ostream& operator<< (std::ostream& os, dni& dni_t);
        bool operator== (dni& r_value);
        bool operator!= (dni& r_value);
        bool operator> (dni& r_value);
        bool operator< (dni& r_value);
        bool operator>= (dni& r_value);
        bool operator<= (dni& r_value);

        static void reset_c(void);

        //operator unsigned long();
    private:
        void inc(void);
};
