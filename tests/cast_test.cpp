#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include <vector>
#include <memory>

#include "../src/cast.h"

TEST_CASE("Cast")
{
	SECTION("Cast int")
	{
		REGISTER_CASTABLE_TYPE(int);
		const std::string typeStr = "int";

		SECTION("Cast int (successful)")
		{
			const std::string valueStr = "42";
			REQUIRE(castable::isTypeCastable(typeStr, valueStr));
		}
		SECTION("Cast int (un-successful)")
		{
			const std::string valueStr = "ab";
			REQUIRE_FALSE(castable::isTypeCastable(typeStr, valueStr));
		}
	}
}
