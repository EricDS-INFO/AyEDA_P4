#define CATCH_CONFIG_MAIN
#include "../include/catch/catch.h"



int add(int x, int y){ return x + y; }
TEST_CASE("add function does work")
{
    int a=0,b=0;
    REQUIRE(add(a,b) == 0);
    SECTION( "Function adds correctly" )
    {
        a=1;
        b=3;
        REQUIRE(add(a,b) ==4);
    }
}