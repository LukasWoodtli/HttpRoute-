#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include "../src/endpoint.h"

TEST_CASE("Endpoint Test")
{
    SECTION("Split Sections")
    {
        Endpoint e("/test/path/to/split");
        const std::vector<std::string> expected{"test", "path", "to", "split"};
        REQUIRE(expected == e.sections());
    }
    
    SECTION("Split Sections and Fragment")
    {
        Endpoint e("/test/path/to/split#here");
        const std::vector<std::string> expectedSections{"test", "path", "to", "split"};
        REQUIRE(expectedSections == e.sections());
        std::string expectedFragment("here");
        REQUIRE(expectedFragment == e.fragment());
    }
}
