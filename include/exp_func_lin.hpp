#pragma once
#include "exp_func.hpp"

template<class KEY>
class exp_func_lin: public exp_func<KEY>
{
    private:
        int slot_num_;
    public:

         exp_func_lin(int slot_num = 0): 
            slot_num_(slot_num){}

        ~exp_func_lin(){};

        int operator() (const KEY& key_t, int val);
};


template<class KEY>
int exp_func_lin<KEY>::operator() (const KEY& key_t, int val)
{
    return val;
}