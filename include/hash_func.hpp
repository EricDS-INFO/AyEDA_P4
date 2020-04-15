#pragma once

template<class KEY>
class hash_func
{
    private:
        int n_slots_;
    
    public:
        hash_func(int n_slots = 0):
            n_slots_(n_slots){}
        ~hash_func(){}
        virtual int operator() ( KEY& key_t)=0;
        
        //obtener el primo más cercano al número de celdas
};



