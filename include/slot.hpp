#pragma once
#include "hash_func.hpp"
#include "exp_func.hpp"
#include <bits/stdc++.h>

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
        
        KEY& operator[](int pos) { return keys_[pos]; }
        
        bool insert(KEY& key_t);
        bool sec_search(KEY key_t);
        bool bin_search(KEY key_t);

        void clean();

   template <class T> 
   friend std::ostream& operator<<  (std::ostream& os, slot<T>& slot);   
};

template<class KEY>
slot<KEY>::slot(int size)
{
    keys_.resize(size);
    for (int i  = 0; i < keys_.size(); i++)
    {
        keys_[i].value(-1);
    } 
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
        if(keys_[i].value() != -1)
            n_elms ++;

    }
    
    return n_elms;
}

template<class KEY>
bool slot<KEY>::full(void)
{
    return elements() == size();
}

template<class KEY>
bool slot<KEY>::insert(KEY& key_t)
{
    for (int i = 0; i < size(); i++)
    {
        if (keys_[i].value() == -1)
        {
            keys_[i] = key_t;
            return true;
        }
    }
    return false;
}


template<class KEY>
bool slot<KEY>::sec_search(KEY key_t)
{
    for (int i = 0; i < size(); i++)
    {
        if (keys_[i] == key_t)
            return true;
    }
    return false;
}

template<class KEY>
bool slot<KEY>::bin_search(KEY key_t)
{
    std::sort(keys_.begin(), keys_.end());

    int start = 0;
    int end = size();
    int position = start;

    while (start < end)
    {
        position = (start + end) / 2;
        if (keys_[position] == key_t)
        {
            return true;
        }
        else
        {
            if (keys_[ position ] < key_t)
                start = position + 1;
            else
                end = position - 1;
        }
    }
    if ( keys_[start] == key_t )
        return true;
    return false;
}

template<class KEY>
void slot<KEY>::clean()
{
    for (int i = 0; i < size(); i++)
    {
        keys_[i].value(-1);
    }
    
}


template<class KEY>
std::ostream& operator<< (std::ostream& os, slot<KEY>& slot)
{
    os << "\n__________________\n";
    for (int i = 0; i < slot.size(); i++)
    {
        os << slot[i] << "\n";
    }
    os << "__________________\n";
    return os;
}