#include "iloperation_dummy.hpp"
#include <catch.hpp>
#include <il/operation/iloperation.hpp>
#include <il/ilstate.hpp>
#include <thread>
#include <chrono>

using namespace il;
using namespace std::chrono_literals;

class ILOperationTestFixture {
public:
  ILOperationTestFixture() { operation_ = std::make_unique<ILOperationDummy>(); }

protected:
  std::unique_ptr<ILOperation> operation_;
};

TEST_CASE_METHOD(ILOperationTestFixture, "Create ILOperation", "[create_ilop]") {
  REQUIRE(operation_->state() == ilstate::CREATED);
}

TEST_CASE_METHOD(ILOperationTestFixture, "Run ILOperation", "[run_ilop]") {
  operation_->run();
  REQUIRE(operation_->isRunning() == true);
  REQUIRE(operation_->state() == ilstate::RUNNING);
}

TEST_CASE_METHOD(ILOperationTestFixture, "Abort ILOperation", "[abort_ilop]") {
  operation_->run();
  operation_->abort();
  REQUIRE(operation_->isRunning() == false);
  REQUIRE(operation_->state() == ilstate::STOPPED);
}

TEST_CASE_METHOD(ILOperationTestFixture, "ILOperation timer", "[ilop_timer]") {
  operation_->run();
  std::this_thread::sleep_for(100ms);
  operation_->abort();

  // allow less than 6ms difference
  REQUIRE(operation_->duration() == Approx(100).epsilon(0.01));
}

