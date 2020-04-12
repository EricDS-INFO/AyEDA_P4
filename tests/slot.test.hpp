#include "../include/catch/catch.h"
#include "../include/slot.hpp"
#include "../include/dni.hpp"
#include "../src/dni.cpp"


SCENARIO( "Slot object can be created as DNI keys", "[structure]" )
{
    GIVEN( "A slot object of size 2" )
    {
        int sz = 2;
        slot<dni> first_slot(sz);

        REQUIRE(first_slot.size() == 2);

        WHEN( "The slot isn't filled yet" )
        {
            THEN( "The method 'full' should return false" )
            {
                REQUIRE(first_slot.full() == false);
            }
        }
    }
}

