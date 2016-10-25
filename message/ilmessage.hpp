#ifndef ILMESSAGE_HPP
#define ILMESSAGE_HPP

#include <memory>

class QString;
class QStringList;

namespace google {
namespace protobuf {
    class Message;
}
}

namespace il {

typedef google::protobuf::Message ILMessage;
typedef std::shared_ptr<ILMessage> ILMessagePtr;

namespace message {

void                        init();
ILMessagePtr                create(const QString& name);
bool                        exists(const QString& name);
extern QStringList          list;

} // namespace message
} // namespace il

#endif // ILMESSAGE_HPP
