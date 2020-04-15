#pragma once
#include "hash_func.hpp"

template<class KEY>
class hash_func_mod: public hash_func<KEY>
{
    private:
        int n_slots_;
    public:
        hash_func_mod(int n_slots = 0):n_slots_(n_slots){}
        ~hash_func_mod();
        int operator() (const KEY& key_t);

        int last_p();
};


template<class KEY>
int hash_func_mod<KEY>::operator() (const KEY& key_t)
{
    
    return key_t.value() % last_p();
}


template <class KEY>
int hash_func_mod<KEY>::last_p()
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