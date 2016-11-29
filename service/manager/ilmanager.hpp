#ifndef ILMANAGER_HPP
#define ILMANAGER_HPP

#include <map>
#include <vector>
#include <memory>

namespace il {
namespace service {

class ILOperation;
class ILBenchmark;
typedef std::shared_ptr<ILOperation> ILOperationPtr;
typedef std::shared_ptr<ILBenchmark> ILBenchmarkPtr;
typedef std::map<std::uint64_t, ILOperationPtr> OpList;
typedef std::vector<ILBenchmarkPtr> BenchList;

class ILManager { 
public:
  ILManager();
  virtual ~ILManager();
  static ILManager* instance();

  std::uint64_t addOperation(ILOperationPtr op);
  ILOperationPtr getOperation(std::uint64_t id) const;
  void removeOperation(std::uint64_t id);

  void addBenchmark(ILBenchmarkPtr bench);
  void removeBenchmark(ILBenchmarkPtr bench);
  ILBenchmarkPtr getBenchmark(int index) const;
  ILBenchmarkPtr getBenchmark(const std::string& name) const;
  int benchmarkCount() const;

private:
  static ILManager* instance_;
  OpList opList_;
  std::uint64_t opId_;
  BenchList benchList_;
};

} // namespace service
} // namespace il

#include "ilmanager.ipp"

#endif // ILMANAGER_HPP
