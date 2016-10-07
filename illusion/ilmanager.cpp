#include "ilmanager.hpp"

namespace il {

ILManager* ILManager::instance_ = nullptr;

ILManager::ILManager()
    :   QObject(nullptr),
        opId_(0)
{

}

} // namespace il
