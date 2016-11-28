#ifndef ILSERVICE_HPP
#define ILSERVICE_HPP

#define IL_HAS_SERVICE_ILCORE
#define IL_HAS_SERVICE_ILMANAGER

#define IL_GET_SERVICE(name) IL_GET_SERVICE_##name

namespace il {
namespace service {

} // namespace service
} // namespace il

#include "core/ilcore.hpp"

#ifdef IL_HAS_SERVICE_ILCORE
#define IL_GET_SERVICE_ILCORE il::service::ILCore::instance()
#else
#define IL_GET_SERVICE_ILCORE static_assert(0, "Service ILCore is not registered")
#endif


#include "manager/ilmanager.hpp"

#ifdef IL_HAS_SERVICE_ILMANAGER
#define IL_GET_SERVICE_ILMANAGER il::service::ILManager::instance()
#else
#define IL_GET_SERVICE_ILMANAGER static_assert(0, "Service ILManager is not registered")
#endif

#endif // ILSERVICE_HPP

