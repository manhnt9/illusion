#ifndef ILSTATE_H
#define ILSTATE_H

namespace il {

enum class ilstate {
  CREATED,
  RUNNING,
  TIMEOUT,
  FAILED,
  STOPPED 
};

} // namespace il

#endif // ILSTATE_H

