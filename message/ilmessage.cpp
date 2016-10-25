#include "ilmessage.hpp"
#include <ilmessage/message.pb.h>
#include <QStringList>

namespace il {
namespace message {

QStringList list;

void init() {
    list.push_back("SampleRequest");
}

bool exists(const QString& name) {
    Q_ASSERT(name.length());

    for(const auto& m : list) {
        if (m == name)
            return true;
    }

    return false;
}

ILMessagePtr create(const QString& name) {
    Q_ASSERT(name.length());

    if (name == "SampleRequest")
        return std::make_shared<SampleRequest>();
    else
        return nullptr;
}

} // namespace message
} // namespace il
