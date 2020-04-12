#pragma once
#include "hash_func.hpp"
#include "exp_func.hpp"


template <class KEY>
class slot
{
    private:
        std::vector<KEY>    keys_;
        exp_func<KEY>*      exploration_;
        hash_func<KEY>*     hashing_;

    public:
        slot(int size);
        ~slot();
        int inline size(void) { return keys_.size(); }
        int elements(void);
        bool full(void);
        
        
        void insert(KEY& key_t);

};

template<class KEY>
slot<KEY>::slot(int size)
{
    keys_.resize(size);
}

template<class KEY>
slot<KEY>::~slot()
{

    while(!keys_.empty())
    {
        keys_.pop_back();    
    }

    keys_.resize(0);
}


template<class KEY>
int slot<KEY>::elements(void)
{
    int n_elms = 0;
    for (int i = 0; i < size(); i++)
    {
        if (keys_[i] != NULL)
            n_elms ++;
    }

    return n_elms;
}

template<class KEY>
bool slot<KEY>::full(void)
{
    return keys_.empty();
}