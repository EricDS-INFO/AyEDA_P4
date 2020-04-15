#pragma once
#include "exp_func.hpp"
#include "hash_func_add.hpp"
#include "hash_func_mod.hpp"
#include "hash_func_pse-rand.hpp"


template<class KEY>
class exp_func_doub: public exp_func<KEY>
{
    private:
        int         slot_num_;
        hash_func<KEY>*  h_function_;
    
    public:
        exp_func_doub(int slot_num = 0):
        slot_num_(slot_num)
        { h_function_ = new hash_func_add<KEY>(slot_num_); }
        
        ~exp_func_doub(){};
    int operator() (const KEY& key_t, int val);
};



template<class KEY>
int exp_func_doub<KEY>::operator() (const KEY& key_t, int val)
{
    return val * (*h_function_)(key_t);
}
