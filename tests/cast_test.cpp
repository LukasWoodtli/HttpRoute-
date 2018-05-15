#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include <vector>
#include <memory>

#include "../src/cast.h"

TEST_CASE("Cast")
{
	SECTION("Cast int")
	{
		const auto castInt = MAKE_TYPE_CASTABLE(int);
		
		SECTION("Cast int (successful)")
		{
			const std::string valueStr = "42";
			REQUIRE(castInt->cast(valueStr));
		}

		SECTION("Cast int (un-successful)")
		{
			const std::string valueStr = "ab";
			REQUIRE_FALSE(castInt->cast(valueStr));
		}
	}
		//std::vector<std::unique_ptr<castable>> casts;
	//casts.emplace_back(MAKE_TYPE_CASTABLE(int));
}
