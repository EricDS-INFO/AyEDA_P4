#include "../include/counter.hpp"
    int counter::value()
    {
        return val_;
    }
    void counter::increase()
    {
        val_++;
    }
    void counter::decrease()
    {
        if (val_ > 0)
            val_--;
    }
    void counter::reset()
    {
        val_ = 0;
    }