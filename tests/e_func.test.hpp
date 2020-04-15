#include "../include/catch/catch.h"
#include "../include/dni.hpp"
#include "../include/hash_func_add.hpp"
#include "../include/exp_func_lin.hpp"
#include "../include/exp_func_cuad.hpp"
#include "../include/exp_func_doub.hpp"
#include "../include/exp_func_rehash.hpp"



SCENARIO( "Linear exploration function can be used" )
{
    GIVEN("An object of class exploration function that can be turned into a linear version")
    {
        dni try_this;
        exp_func<dni>* my_explorer;
        my_explorer = new exp_func_lin<dni>(2);
        WHEN("Used the operator () in the slot = x")
        {
            int slot = 3;
            THEN("Must provide the position x")
            {
                REQUIRE((*my_explorer)(try_this, slot) == slot);
            }
            AND_THEN("Operator '%' can be used ")
            {
                REQUIRE(typeid((*my_explorer)(try_this, slot) % try_this.value()) == typeid(int) );
            }
        }
    }
}

SCENARIO( "Cuadratic exploration function can be used" )
{
    GIVEN("An object of class exploration function that can be turned into a cuadratic version")
    {
        dni try_this;
        exp_func<dni>* my_explorer;
        my_explorer = new exp_func_cuad<dni>(2);
        WHEN("Used the operator () in the slot = x")
        {
            int slot = 3;
            THEN("Must provide the position x")
            {
                REQUIRE((*my_explorer)(try_this, slot) == (slot*slot));
            }
        }
    }
}


SCENARIO( "Doubly exploration function can be used" )
{
    GIVEN("An object of class exploration function that can be turned into a doubly version")
    {
        dni try_this;
        exp_func<dni>* my_explorer;
        hash_func<dni>* my_hasher;
        my_hasher = new hash_func_add<dni>(1000);
        my_explorer = new exp_func_doub<dni>(1000);
        
        WHEN("Used the operator () in the slot = x")
        {
            int slot = 3;
            THEN("Must provide the position x")
            {
                   REQUIRE( (*my_explorer)(try_this, slot) == ((*my_hasher)(try_this) * slot));
            }
        }
    }
}


SCENARIO( "re-hashing exploration function can be used" )
{
    GIVEN("An object of class exploration function that can be turned into a re-hahsing one")
    {
        int slots = 1000;
        exp_func<dni>* my_explorer;
        my_explorer = new exp_func_rehash<dni>(1000);
        
        WHEN("Used the operator () in the slot = x")
        {
            int slot = 3;
            THEN("Must provide different positions for different keys")
            {
                dni key_1;
                dni key_2;
        
                CHECK( (*my_explorer)(key_1, slot) != (*my_explorer)(key_2, slot) );
            }
            AND_THEN("Must provide equal positions for the same key")
            {
                dni key_1;
                dni key_2;
        
                CHECK( (*my_explorer)(key_1, slot) == (*my_explorer)(key_1, slot) );
            }
        }
    }
}