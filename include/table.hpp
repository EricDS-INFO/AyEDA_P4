#pragma once

#include<typeinfo>
#include<cxxabi.h>


#include "slot.hpp"
// Hash functions
#include "hash_func_add.hpp"
#include "hash_func_mod.hpp"
#include "hash_func_pse-rand.hpp"
// Explore functions
#include "exp_func_cuad.hpp"
#include "exp_func_doub.hpp"
#include "exp_func_lin.hpp"
#include "exp_func_rehash.hpp"



template<class KEY>
class table
{
private:
    slot<KEY>** slots_;

    exp_func<KEY>*   explorer_;
    hash_func<KEY>*   hasher_;

    int sz_, slt_sz_;

public:
    table(int tb_sz, int sl_sz, int t_hash, int t_expl);
    ~table();

    // Getters
    int size() { return sz_; }
    int slot_size() { return slt_sz_; }
    std::string hasher() const; 
    std::string explorer() const; 

    bool search(KEY key_o);

    bool insert(KEY key_o);
};



template<class KEY>
table<KEY>::table(int tb_sz, int slt_sz, int t_hash, int t_expl)
{
    sz_ = tb_sz;
    slt_sz_ = slt_sz;
    slots_ = new  slot<KEY> *[sz_];
    for(int i = 0; i < sz_; i++)
    {
        slots_[i] = new slot<KEY>(slt_sz_);
    }

    switch(t_hash)
    {
        case 1:
            hasher_ = new hash_func_mod<KEY>(sz_);
            break;
        case 2:
            hasher_ = new hash_func_add<KEY>(sz_);
            break;
        case 3:
            hasher_ = new hash_func_pseRand<KEY>(sz_);
            break;
        default:
            hasher_ = new hash_func_mod<KEY>(sz_);
            break;
    }
    switch(t_expl)
    {
        case 1:
            explorer_ = new exp_func_lin<KEY>(sz_);
            break;
        case 2:
            explorer_ = new exp_func_cuad<KEY>(sz_);
            break;
        case 3:
            explorer_ = new exp_func_doub<KEY>(sz_);
            break;

        case 4:
            explorer_ = new exp_func_rehash<KEY>(sz_);
            break;

        default:
            explorer_ = new exp_func_lin<KEY>(sz_);
            break;
    }
}

template<class KEY>
table<KEY>::~table()
{
    for(int i = 0; i < sz_; i++)
    {
        delete slots_[i];
    }
    delete slots_;
    sz_ = 0;
}
template <class KEY>
std::string table<KEY>::hasher() const 
{   
    std::string current = typeid(*hasher_).name();
    std::string mod_case =  typeid(hash_func_mod<KEY>).name();
    std::string add_case =  typeid(hash_func_add<KEY>).name();
    std::string pr_case =  typeid(hash_func_pseRand<KEY>).name();

    return (current == mod_case ? "Module" : 
           (current == add_case ? "Add" : "PseudoRandom" ) );
} 

template <class KEY>
std::string table<KEY>::explorer() const 
{
    
    std::string current  =  typeid(*explorer_).name();
    std::string cuad_case =  typeid(exp_func_cuad<KEY>).name();
    std::string doub_case =  typeid(exp_func_doub<KEY>).name();
    std::string lin_case  =  typeid(exp_func_lin<KEY>).name();
    std::string rh_case  =  typeid(exp_func_rehash<KEY>).name();

    return (current == lin_case ? "Linear" : 
           (current == cuad_case ? "Cuadratic" : 
           (current == doub_case ? "Double":
            "Rehash") ) );

} 


template<class KEY>
bool table<KEY>::search(KEY key_o)
{
    return slots_[(*hasher_)(key_o)]->sec_search(key_o);
}
template<class KEY>
bool table<KEY>::insert(KEY key_o)
{

    return slots_[(*hasher_)(key_o)]->insert(key_o);
}