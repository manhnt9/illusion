#ifndef ILMESSAGE_HPP
#define ILMESSAGE_HPP

class QString;
class QStringList;

namespace google {
namespace protobuf {
    class MessageLite;
}
}

namespace il {

typedef google::protobuf::MessageLite ILMessage;

namespace message {

void                        init();
ILMessage*                  create(const QString& name);
extern QStringList          list;

} // namespace message
} // namespace il

#endif // ILMESSAGE_HPP
