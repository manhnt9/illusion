#include <catch.hpp>
#include "service/ilservice.hpp"

TEST_CASE("Get ILCore service test", "[get_ilcore_service]") {
  REQUIRE(IL_GET_SERVICE(ILCORE) != nullptr);
}

TEST_CASE("Get ILConfiguration service test", "[get_ilconfiguration_service]") {
  REQUIRE(IL_GET_SERVICE(ILCONFIGURATION) != nullptr);
}

