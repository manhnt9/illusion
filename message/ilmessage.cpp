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
    for(const auto& m : list) {
        if (m == name)
            return true;
    }

    return false;
}

ILMessage* create(const QString& name) {
    Q_ASSERT(name.length());

    if (name == "SampleRequest")
        return new SampleRequest();
    else
        return nullptr;
}

} // namespace message
} // namespace il
