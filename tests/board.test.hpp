#include "../include/catch/catch.h"
#include "../include/dni.hpp"
#include "../include/table.hpp"

SCENARIO( "Testing the creation of a hash table", "[structure]" )
{
    GIVEN( "A table with a certain size " )
    {
        int table_sz = 5, slot_sz = 2, h_fun_t = 1, e_fun_t = 1;
        table<dni> first_table(table_sz, slot_sz, h_fun_t, e_fun_t);
        
    }
}