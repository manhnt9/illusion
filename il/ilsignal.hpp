#ifndef ILSIGNAL_HPP
#define ILSIGNAL_HPP

#include <map>
#include <functional>

namespace il {

template <typename... Args>
class ILSignal {
public:
  ILSignal() : slotId_(0) { }
  ILSignal(const ILSignal& other) = delete;
  ILSignal& operator=(const ILSignal& other) = delete;

  void emit(Args... params) {
    for (const auto& it : slots_)
      it.second(params...);
  }
  
  auto connect(const std::function<void(Args...)>& slot) {
    slots_.insert({slotId_, slot});
    return slotId_++;
  }

  template <typename F, typename... A>
  auto connectMemFun(F&& memFun, A&& ... args) {
    slots_.insert({slotId_, std::bind(memFun, args...)});
    return slotId_++;
  }

  void disconnect(std::uint16_t slotId) {
    slots_.erase(slotId);
  }

  void disconnectAll() {
    slots_.clear();
    slotId_ = 0;
  }

private:
  std::map<std::uint16_t, std::function<void(Args...)>> slots_;
  std::uint16_t slotId_;
};

} // namespace il

#endif // ILSIGNAL_HPP
