#include "../include/catch/catch.h"
#include "../include/dni.hpp"
#include "../include/table.hpp"

SCENARIO( "Testing the creation of a hash table", "[structure]" )
{
    GIVEN( "A table with a certain size " )
    {
        int table_sz = 1000, slot_sz = 2, h_fun_t = 1, e_fun_t = 1;
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
        AND_WHEN( "Searched a key element wich doesn't exist " )
        {
            dni test_key;
            THEN( "The result must be false " )
            {
                REQUIRE(first_table.search(test_key) == false);
            }
        }
        AND_WHEN( "Searched a single key element that was inserted " )
        {
            dni test_key;
            THEN( "The result must be true " )
            {
                CHECK(first_table.insert(test_key) == true);
                REQUIRE(first_table.search(test_key) == true);
            }
            AND_THEN ("The hash table slot isn't full")
            {
                REQUIRE(first_table.at(test_key)->full() == false);
            }
        }

        AND_WHEN( "Inserted 2 equal elements" )
        {
            first_table.clean();
            dni key_1;

            CHECK(first_table.insert(key_1) == true);
            THEN( "The search must be true the first time and the full state must be false" )
            {
                // Just a sigle element can be added
                REQUIRE(first_table.insert(key_1) == false);
                REQUIRE(first_table.search(key_1) == true);
                REQUIRE(first_table.at(key_1)->full() == false);
            }
        }
        AND_WHEN( "Inserted 3 different elements" )
        {
            first_table.clean();
            dni key_1;
            dni key_2;
            dni key_3;

            CHECK(first_table.insert(key_1) == true);
            CHECK(first_table.insert(key_2) == true);
            THEN( "The search must be true all the times due to hashing" )
            {
                // Just a sigle element can be added
                REQUIRE(first_table.insert(key_3) == true);
                REQUIRE(first_table.search(key_1) == true);
                REQUIRE(first_table.search(key_2) == true);
                REQUIRE(first_table.search(key_3) == true);
                REQUIRE(first_table.at(key_1)->full() == false);
                REQUIRE(first_table.at(key_2)->full() == false);
                REQUIRE(first_table.at(key_3)->full() == false);
            }
        }
    }
}

SCENARIO( "Testing one slot hash table", "[structure]" )
{
    GIVEN( "A table with 1 slot " )
    {
        int table_sz = 1, slot_sz = 2, h_fun_t = 1, e_fun_t = 1;
        table<dni> third_table(table_sz, slot_sz, h_fun_t, e_fun_t);

        CHECK(table_sz > 0);
        CHECK(slot_sz >= 1);
        CHECK(h_fun_t >= 1); CHECK(h_fun_t <= 3);
        CHECK(h_fun_t >= 1); CHECK(h_fun_t <= 4);
        
        WHEN( "Inserted 3 different elements" )
        {
            third_table.clean();
            dni key_1;
            dni key_2;
            dni key_3;

            CHECK(third_table.insert(key_1) == true);
            CHECK(third_table.insert(key_2) == true);
            THEN( "The third element fails at insertion" )
            {
                REQUIRE(third_table.insert(key_3) == false);
            }
        }
    }
}


SCENARIO( "Testing advance hash table", "[structure]" )
{
    GIVEN( "A table with 3 slots but 1 cell per slot" )
    {
        int stable_sz = 7, slot_sz = 1, h_fun_t = 1, e_fun_t = 4;
        table<dni> forth_table(stable_sz, slot_sz, h_fun_t, e_fun_t);

        CHECK(stable_sz > 0);
        CHECK(slot_sz >= 1);
        CHECK(h_fun_t >= 1); CHECK(h_fun_t <= 3);
        CHECK(h_fun_t >= 1); CHECK(h_fun_t <= 4);
        
        WHEN( "Inserted 3 different elements | high colision probability" )
        {
            forth_table.clean();
            
            dni key_1;
            dni key_2;
            dni key_3;
            dni key_4;
            dni key_5;
            dni key_6;
            dni key_7;
            dni key_8;
            dni key_9;
 

             
            
            THEN( "The third element wins at insertion" )
            {

            std::cout << "this k1: " << key_1.value() % stable_sz << "\n";
               CHECK(forth_table.insert(key_1) == true);

            std::cout << "this k2: " << key_2.value() % stable_sz << "\n";
               CHECK(forth_table.insert(key_2) == true);     

            std::cout << "this k3: " << key_3.value() % stable_sz << "\n";
               CHECK(forth_table.insert(key_3) == true);

            std::cout << "this k4: " << key_4.value() % stable_sz << "\n";
               CHECK(forth_table.insert(key_4) == true);
            
            std::cout << "this k5: " << key_5.value() % stable_sz << "\n";
               CHECK(forth_table.insert(key_5) == true);     
            
            std::cout << "this k6: " << key_6.value() % stable_sz << "\n";
               CHECK(forth_table.insert(key_6) == true);
            
            std::cout << "this k7: " << key_7.value() % stable_sz << "\n";
            
               CHECK(forth_table.insert(key_7) == true);
            }
        }
    }
}