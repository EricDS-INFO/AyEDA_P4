#pragma once

template<class KEY>
class exp_func
{   
    private:
        int slot_num_;
    public:

        exp_func(int slot_num = 0): 
        slot_num_(slot_num){}


        ~exp_func(){}
        virtual int operator() (const KEY& key_t, int val)=0;
};
