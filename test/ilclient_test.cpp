#include <catch.hpp>
#include <il/ilclient.hpp>
#include <il/ilstate.hpp>
#include "iloperation_dummy.hpp"

class ILClientTestFixture {
public:
  ILClientTestFixture() { }

protected:
  il::ILClient client_;
  
private:
};

TEST_CASE_METHOD(ILClientTestFixture, "Create ILClient", "[create_ilclient]") {
  REQUIRE(client_.state() == il::ilstate::CREATED);
  REQUIRE(client_.isRunning() == false); 
  REQUIRE(client_.operation() == nullptr);
} 

TEST_CASE_METHOD(ILClientTestFixture, "Set up ILClient", "[setup_ilclient]") {
  auto op = std::unique_ptr<il::ILOperation>(new ILOperationDummy());
  client_.setOperation(op);
  REQUIRE(client_.operation() != nullptr);
}

TEST_CASE_METHOD(ILClientTestFixture, "Start ILClient", "[start_ilclient]") {
  SECTION("Client doesn't have any operation") {
    client_.start();
    REQUIRE(client_.isRunning() == false);
  }
  
  SECTION("Client has an operation") {
    auto op = std::unique_ptr<il::ILOperation>(new ILOperationDummy());
    client_.setOperation(op);
    client_.start();
    REQUIRE(client_.isRunning() == true);
  }
}

TEST_CASE_METHOD(ILClientTestFixture, "Stop ILClient", "[stop_ilclient]") {
  auto op = std::unique_ptr<il::ILOperation>(new ILOperationDummy());
  client_.setOperation(op);

  SECTION("Client hasn't started") {
    client_.stop();
    REQUIRE(client_.isRunning() == false);
    REQUIRE(client_.state() == il::ilstate::STOPPED);
  }
  
  SECTION("Client has started") {
    client_.start();
    client_.stop();
    REQUIRE(client_.isRunning() == false);
    REQUIRE(client_.state() == il::ilstate::STOPPED);
  }
}

