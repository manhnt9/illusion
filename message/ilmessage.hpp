#ifndef ILMESSAGE_HPP
#define ILMESSAGE_HPP

class QString;
class QStringList;

namespace google {
namespace protobuf {
    class Message;
}
}

namespace il {

typedef google::protobuf::Message ILMessage;

namespace message {

void                        init();
ILMessage*                  create(const QString& name);
bool                        exists(const QString& name);
extern QStringList          list;

} // namespace message
} // namespace il

#endif // ILMESSAGE_HPP
