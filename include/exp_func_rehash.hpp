#pragma once
#include <cstdlib>
#include "exp_func.hpp"
#include "hash_func.hpp"
#include "hash_func_add.hpp"
#include "hash_func_mod.hpp"
#include "hash_func_pse-rand.hpp"


template<class KEY>
class exp_func_rehash: public exp_func<KEY>
{
    private:
        int             slot_num_;
        hash_func<KEY>  *h_function_3,*h_function_2, *h_function_1;
        
    public:
        exp_func_rehash(int slot_num = 0);

        ~exp_func_rehash(){};
    
    int operator() (const KEY& key_t, int val);
};

template <class KEY>
exp_func_rehash<KEY>::exp_func_rehash(int slot_num ):
slot_num_(slot_num)
{ 
    h_function_1 = new hash_func_add<KEY>(slot_num_); 
    h_function_2 = new hash_func_mod<KEY>(slot_num_); 
    h_function_3 = new hash_func_pseRand<KEY>(slot_num_); 
    
}

template<class KEY>
int exp_func_rehash<KEY>::operator() (const KEY& key_t, int val)
{
    srand(key_t.value());
    int result = 0;
    if(val > 0){

        for (int i = 1; i <= val; i++)
        {
            result = rand() % slot_num_;
        }
    }
    
    return result;
    
}
