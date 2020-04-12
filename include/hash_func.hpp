#pragma once

template<class KEY>
class hash_func
{
    virtual int operator() (const KEY& key_t)=0;
};