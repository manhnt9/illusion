#include "ilmanager.hpp"

namespace il {

ILManager* ILManager::instance_ = nullptr;

ILManager::ILManager(QObject *parent)
    :   QObject(parent),
        opId_(0)
{

}

} // namespace il
