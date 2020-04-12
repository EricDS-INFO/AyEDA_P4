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
bool slot<KEY>::full(void)
{
    return keys_.empty();
}