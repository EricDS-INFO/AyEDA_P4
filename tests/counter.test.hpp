#include "../include/catch/catch.h"
#include "../include/counter.hpp"


SCENARIO( "Counter object is created and works as desired", "[structure]" )
{
    GIVEN( "A counter object" )
    {
        counter ctr1;
        WHEN( "It's value is increased by 1" )
        {
            ctr1.increase();
            THEN ( "The value changes to 1" )
            {
                REQUIRE(ctr1.value() == 1);
            }
        }

        AND_WHEN( "It's value is increased by 3" )
        {
            ctr1.increase();
            ctr1.increase();
            ctr1.increase();
            THEN ( "The value changes to 1" )
            {
                REQUIRE(ctr1.value() == 3);
            }
            AND_THEN( "decreased, the value is restored" )
            {
                ctr1.decrease();
                ctr1.decrease();
                ctr1.decrease();
                REQUIRE(ctr1.value() == 0);
            }
            AND_THEN( "decreased by 1 unit more, value is foxed to 0" )
            {
                ctr1.decrease();
                ctr1.decrease();
                ctr1.decrease();
                ctr1.decrease();
                REQUIRE(ctr1.value() == 0);
                
            }
        }
        AND_WHEN( "It's value is increased and restored" )
        {

            ctr1.increase();
            ctr1.increase();
            ctr1.increase();
            ctr1.reset();
            THEN( "Value is 0 as started" )
            {
                REQUIRE(ctr1.value() == 0);
                
            }
        }
    }
}
