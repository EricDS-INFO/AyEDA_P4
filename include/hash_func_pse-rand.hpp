#pragma once
#include "hash_func.hpp"

template<class KEY>
class hash_func_pseRand: public hash_func<KEY>
{
    private:
        int n_slots_;
    public:
        hash_func_pseRand(int n_slots = 0):
        n_slots_(n_slots){}
        ~hash_func_pseRand();
        int operator() ( KEY& key_t);
};

template<class KEY>
int hash_func_pseRand<KEY>::operator() ( KEY& key_t)
{
    return 0;
}