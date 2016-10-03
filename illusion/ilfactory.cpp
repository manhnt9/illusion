#include "ilfactory.hpp"

namespace il {

ILFactory::ILFactory() {
    init();
}

void ILFactory::init() {

}

ILOperation* ILFactory::create(const int type) {
    ILOperation* op = nullptr;

    switch(type) {
//    case REQUEST: {
//        op = o;
//    } break;
    }

    return op;
}

QString ILFactory::getName(const int type) const {
    switch (type) {
//    case REQUEST:
//        return "RequestName";
    }
}

} // namespace il
