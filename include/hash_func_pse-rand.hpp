#pragma once
#include "hash_func.hpp"
#include <cstdlib>

template<class KEY>
class hash_func_pseRand: public hash_func<KEY>
{
    private:
        int n_slots_;
    public:
        hash_func_pseRand(int n_slots = 0):
        n_slots_(n_slots){}
        ~hash_func_pseRand();
        int operator() (const KEY& key_t);
        int last_p();

};

template<class KEY>
int hash_func_pseRand<KEY>::operator() (const KEY& key_t)
{
    srand(key_t.value());
    return rand() % last_p();
}


template <class KEY>
int hash_func_pseRand<KEY>::last_p()
{
    int tester, count, prime;
    
    
    for (int i = 0; i <= n_slots_; i++)
    {
        tester = 1;
        count = 2;
        while(count <= i /2 && tester)
        {
            if( i % count == 0)
                tester = 0;
            count++;
        }
        if (tester)
            prime = i;
    }
    return prime;
}