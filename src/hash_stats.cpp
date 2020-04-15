#include <iostream>
#include "../include/hash_func_add.hpp"
#include "../include/exp_func_doub.hpp"
#include "../include/dni.hpp"


int main(void)
{

    dni try_this;
    exp_func<dni>* my_explorer;
    hash_func<dni>* my_hasher;
    my_hasher = new hash_func_add<dni>(1000);
    my_explorer = new exp_func_doub<dni>(1000);
        
    std::cout << (*my_hasher)(try_this) << std::endl; 
    return 0; 
}