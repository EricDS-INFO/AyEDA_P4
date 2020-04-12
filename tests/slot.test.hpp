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
        AND_WHEN( "One element is inserted" )
        {
            dni dni_1;
            first_slot.insert(dni_1);

            THEN ( "number of elements increase by 1 but still not full" )
            {
                REQUIRE(first_slot.elements() == 1);
                REQUIRE(first_slot.full() == false);
            }
        }
        AND_WHEN( "The slot is filled" )
        {
            dni dni_1;
            dni dni_2;
            first_slot.insert(dni_1);
            first_slot.insert(dni_2);

            THEN ( "number of elements increase but still not full" )
            {
                REQUIRE(first_slot.elements() == 2);
                REQUIRE(first_slot.full() == true);
            }
            AND_THEN ("A key can be searched in the slot")
            {
                dni dni_3;
                REQUIRE(first_slot.sec_search(dni_1));
                REQUIRE(first_slot.bin_search(dni_2));
                REQUIRE(!first_slot.bin_search(dni_3));
            }
        }
    }
}

