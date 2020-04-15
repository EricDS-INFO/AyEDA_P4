#pragma once
#include "hash_func.hpp"

template<class KEY>
class hash_func_add: public hash_func<KEY>
{
    private:
        int n_slots_;
    public:
        hash_func_add(int n_slots = 0):
        n_slots_(n_slots){}
        
        ~hash_func_add();
        
        int operator() (const KEY& key_t);
        int last_p();
};

template <class KEY>
int hash_func_add<KEY>::operator() (const KEY& key_t)
{
    int d = 0;
    int y;
    int x = key_t.value() ;

    while (x > 0)
    {
        y = x % 8 ;
        d = d + y;
        x = x / 8;  
    }
    last_p();
    return (d % last_p());
}



template <class KEY>
int hash_func_add<KEY>::last_p()
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