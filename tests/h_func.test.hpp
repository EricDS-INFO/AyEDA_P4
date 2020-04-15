#include "../include/catch/catch.h"
#include "../include/dni.hpp"
#include "../include/hash_func_mod.hpp"
#include "../include/hash_func_add.hpp"
#include "../include/hash_func_pse-rand.hpp"



SCENARIO( "hash funtion can be used and turned into a Module type " )
{
    GIVEN( "A hash function" )
    {
        int slots = 997;

        dni key_1;
        dni key_2;

        std::cout << key_1.value() << "   " << key_2.value() << "\n";
        hash_func<dni>* my_hasher;
        my_hasher = new hash_func_mod<dni>(slots);
        WHEN( "Turned into a module hasher with 997 slots" )
        {
            THEN( "must provide the module between the key and slots size" )
            {
                REQUIRE((*my_hasher)(key_1) == (key_1.value() % slots));
                REQUIRE((*my_hasher)(key_2) == (key_2.value() % slots));
                  CHECK((*my_hasher)(key_2) != (*my_hasher)(key_1));
            }
        }

    }

}

SCENARIO( "hash funtion can be used and turned into an Add type " )
{
    GIVEN( "A hash function" )
    {
        
        int slots = 1000;
        hash_func<dni>* my_hasher;
        my_hasher = new hash_func_add<dni>(slots);
        WHEN( "Turned into a adder hasher with 997 slots" )
        {
             THEN( "Must provide a different position for two keys" )
             {
                 dni key_1;
                 dni key_2;
                 CHECK((*my_hasher)(key_1) != (*my_hasher)(key_2));
             }
        }

    }

}

SCENARIO( "hash funtion can be used and turned into a pseudo-random type " )
{
    GIVEN( "A hash function" )
    {
        int slots = 4; 
        hash_func<dni>* my_hasher;
        my_hasher = new hash_func_pseRand<dni>(slots);
        WHEN( "Turned into a ")
        {
        }

    }

}