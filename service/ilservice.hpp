#ifndef ILSERVICE_HPP
#define ILSERVICE_HPP

#define IL_HAS_SERVICE_ILMANAGER

namespace il {
namespace service {

} // namespace service
} // namespace il

#include <ilmanager/ilmanager.hpp>
#define IL_GET_SERVICE(name) IL_GET_SERVICE_##name

#ifdef IL_HAS_SERVICE_ILMANAGER
#define IL_GET_SERVICE_ILMANAGER il::service::ILManager::instance()
#else
#define static_assert(0, "Service ILManager is not registered")
#endif

#endif // ILSERVICE_HPP
