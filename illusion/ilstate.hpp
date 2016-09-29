#ifndef ILSTATE_H
#define ILSTATE_H

namespace il {

enum State {
    CREATED,
    INIT,
    RUNNING,
    DONE,
    CANCELED,
    ERROR
};

} // namespace il

#endif // ILSTATE_H
