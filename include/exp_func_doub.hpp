#pragma once
#include "exp_func.hpp"
#include "hash_func.hpp"

template<class KEY>
class exp_func_doub: public exp_func<KEY>
{
    private:
        int         slot_num_;
        hash_func<KEY>*  h_function_;
    
    public:
        exp_func_doub(hash_func<KEY>* h_function, int slot_num = 0): 
        slot_num_(slot_num),
        h_function_(h_function){};
        
        ~exp_func_doub(){};
    int operator() (const KEY& key_t, int val);
};

template<class KEY>
int exp_func_doub<KEY>::operator() (const KEY& key_t, int val)
{
    return 0;
}
