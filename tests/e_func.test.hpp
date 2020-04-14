#include "../include/catch/catch.h"
#include "../include/dni.hpp"
#include "../include/exp_func_lin.hpp"



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
