#include "ilcore.hpp"
#include <chrono>

namespace il {
namespace service {

ILCore* ILCore::instance_ = nullptr;

ILCore::ILCore() {

}

std::uint64_t ILCore::time() const {
 using namespace std::chrono;
 return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

ILCore::~ILCore() {

}

} // namespace service
} // namespace il

