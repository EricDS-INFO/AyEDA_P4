#pragma once

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

    int size() { return sz_; }
    int slot_size() { return slt_sz_; }
    std::string hasher() const { return "Add"; } 
    std::string explorer() const { return "Lin"; } 

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
            hasher_ = new hash_func_mod<KEY>();
            break;
        case 2:
            hasher_ = new hash_func_add<KEY>();
            break;
        case 3:
            hasher_ = new hash_func_pseRand<KEY>();
            break;
        default:
            hasher_ = new hash_func_mod<KEY>();
            break;
    }
    switch(t_expl)
    {
        case 1:
            explorer_ = new exp_func_lin<KEY>();
            break;
        case 2:
            explorer_ = new exp_func_cuad<KEY>();
            break;
        case 3:
            explorer_ = new exp_func_doub<KEY>();
            break;

        case 4:
            explorer_ = new exp_func_rehash<KEY>();
            break;

        default:
            explorer_ = new exp_func_lin<KEY>();
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