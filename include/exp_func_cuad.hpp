
#pragma once
#include "exp_func.hpp"

template<class KEY>
class exp_func_cuad: public exp_func<KEY>
{
    private:
        int slot_num_;
    public:

         exp_func_cuad(int slot_num = 0): 
            slot_num_(slot_num){}
        ~exp_func_cuad(){};

        int operator() (const KEY& key_t, int val);
};


template<class KEY>
int exp_func_cuad<KEY>::operator() (const KEY& key_t, int val)
{
    return val*val;
}