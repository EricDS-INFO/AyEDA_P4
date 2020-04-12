#pragma once

template<class KEY>
class exp_func
{
    virtual int operator() (const KEY& key_t)=0;
};