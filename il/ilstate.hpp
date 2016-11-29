#ifndef ILSTATE_H
#define ILSTATE_H

namespace il {

enum class state {
  CREATED,
  RUNNING,
  TIMEOUT,
  FAILED,
  FINISHED
};

} // namespace il

#endif // ILSTATE_H

