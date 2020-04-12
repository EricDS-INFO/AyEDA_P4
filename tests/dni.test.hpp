#include "../include/catch/catch.h"

#include "../include/dni.hpp"
#include "../src/dni.cpp"



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
    }
    AND_GIVEN( "A vector of 1000 DNI's" )
    {
        std::vector<dni> dni_v;
        for (int i = 0; i < 1000; i++)
        {
            dni aux;
            dni_v.push_back(aux);
        }

        THEN( "They sould be all different" ){
            for (int i = 0; i < dni_v.size(); i++ )
            {
                for (int j = 0; j < dni_v.size(); j++ )
                {
                    if (i != j)
                    {
                        REQUIRE(dni_v[i].value() !=
                                dni_v[j].value());
                
                    }
                }
            }
        }
        AND_THEN (" They sould all be printed "){
            for (int i = 0; i < dni_v.size(); i++ )
            {
            //    std::cout << dni_v[i] << "\n";
            }
        }
    }
}



