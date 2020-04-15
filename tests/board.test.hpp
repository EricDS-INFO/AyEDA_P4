#include "../include/catch/catch.h"
#include "../include/dni.hpp"
#include "../include/table.hpp"

SCENARIO( "Testing the creation of a hash table", "[structure]" )
{
    GIVEN( "A table with a certain size " )
    {
        int table_sz = 5, slot_sz = 2, h_fun_t = 1, e_fun_t = 1;
        table<dni> first_table(table_sz, slot_sz, h_fun_t, e_fun_t);

        CHECK(table_sz > 0);
        CHECK(slot_sz >= 1);
        CHECK(h_fun_t >= 1); CHECK(h_fun_t <= 3);
        CHECK(h_fun_t >= 1); CHECK(h_fun_t <= 4);
        WHEN( "Asked for size" )
        {
            THEN( "Should provide the correct value" )
            {
                REQUIRE(first_table.size() == table_sz );
            }
        }
        AND_WHEN( "Asked for the slots size" )
        {

            THEN( "Should provide the correct value" )
            {
                REQUIRE(first_table.slot_size() == slot_sz);
            }
        }

        AND_WHEN( "Asked for the hash function" )
        {

            THEN( "Should provide the correct name" )
            {
                REQUIRE(first_table.hasher() == "Module");
            }
        }

        AND_WHEN( "Asked for the exploration function" )
        {

            THEN( "Should provide the correct value" )
            {
                REQUIRE(first_table.explorer() == "Linear");
            }
        }
    }
}