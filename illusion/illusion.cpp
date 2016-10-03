#include "illusion.hpp"

namespace il {

Illusion* Illusion::instance_ = nullptr;

Illusion::Illusion(QObject* parent)
    :   QObject(parent),
        work_(nullptr)
{

}

Illusion::~Illusion() {

}

} // namespace il
