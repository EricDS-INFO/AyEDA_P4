#include "../include/catch/catch.h"
#include "../include/dni.hpp"
#include "../include/counter.hpp"


SCENARIO( "DNI is created as a random number of 8 digits" )
{
    GIVEN( "Two DNI Objects " )
    {
        dni dni_1;
        dni dni_2;
        THEN( "They should be different on most of cases" )
        {
            REQUIRE( dni_1.value() != dni_2.value() );
            REQUIRE( dni_1.length() >= 1);
            REQUIRE( dni_1.length() <= 8);
            REQUIRE( dni_2.length() >= 1);
            REQUIRE( dni_2.length() <= 8);
        }
        AND_THEN( "They should be printed correctly" ){
            std::cout << dni_1 << std::endl;
            std::cout << dni_2 << std::endl;
        }
    }
    AND_GIVEN( "Two DNI Objects with same seed" )
    {
        dni dni_1(1);
        dni dni_2(1);
        THEN( "They should be equal" )
        {
            REQUIRE( dni_1.value() == dni_2.value() );
            REQUIRE( dni_1.length() >= 1);
            REQUIRE( dni_1.length() <= 8);
            REQUIRE( dni_2.length() >= 1);
            REQUIRE( dni_2.length() <= 8);
        }
        AND_THEN( "They should be printed correctly" ){
            std::cout << dni_1 << std::endl;
            std::cout << dni_2 << std::endl;
        }
        WHEN("Compared a few times the objects, counter value changes")
        {
            THEN( "Counter value is increased" )
            {
            if ( dni_1 == dni_2 )
            if ( dni_1 != dni_2 )
            if ( dni_1 > dni_2 )
            if ( dni_1 < dni_2 )
            if ( dni_1 >= dni_2 )
            if ( dni_1 <= dni_2 )
         
                REQUIRE(dni_1.nth_compare() == 6);
                REQUIRE(dni_2.nth_compare() == 3);
            }
        }
    }
}



