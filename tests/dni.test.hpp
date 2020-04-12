#include "../include/catch/catch.h"

#include "../include/dni.hpp"
#include "../src/dni.cpp"



SCENARIO( "DNI is created as a random number of 8 digits" )
{
    GIVEN( "Two DNI Objects " )
    {
        dni dni_1;
        dni dni_2;
        THEN("They should be different on most of cases"){
            REQUIRE( dni_1.length() >= 1 && dni_1.length() <= 8);
            REQUIRE( dni_1.value() != dni_2.value());
        }
    }

}


