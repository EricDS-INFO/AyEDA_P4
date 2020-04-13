#pragma once
#include "slot.hpp"
#include "hash_func.hpp"
#include "exp_func.hpp"

template<class KEY>
class table
{
private:
    slot<KEY>** slots_;

    exp_func<KEY>*   exploring_;
    hash_func<KEY>*   hashing_;

    int sz_;

public:
    table(int tb_sz, int sl_sz, int t_hash, int t_expl);
    ~table();


};



template<class KEY>
table<KEY>::table(int tb_sz, int sl_sz, int t_hash, int t_expl)
{
    sz_ = tb_sz;
    slots_ = new  slot<KEY> *[sz_];
    for(int i = 0; i < sz_; i++)
    {
        slots_[i] = new slot<KEY>(sl_sz);
    }

    switch(t_hash)
    {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            break;
    }
    switch(t_expl)
    {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:
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