#pragma once
#include "../include/hash_func.hpp"
#include <vector>
#include <stdio.h>


template<class KEY>
class hash_func_add_2: public hash_func<KEY>
{
    private:
        int n_slots_;
    public:
        hash_func_add_2(int n_slots = 0):
        n_slots_(n_slots){}
        
        ~hash_func_add_2();
        
        int operator() (const KEY& key_t);
        // Ultimo numero primo
        int last_p();
};

template <class KEY>
int hash_func_add_2<KEY>::operator() (const KEY& key_t)
{
    std::vector<int> numbers;
    int value = key_t.value();
    int result = 0;
    while (value)
    {
        int aux = value % 100;
        numbers.push_back(aux);
        value /= 100;
    }
    
    for (int i = numbers.size() - 1; i >= 0; i-=2)
    {
        result += numbers[i];
    }
    
// --------

    return (result % last_p());
}



template <class KEY>
int hash_func_add_2<KEY>::last_p()
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