#include "service/ilservice.hpp"
#include <iostream>

int main() {
  IL_GET_SERVICE(ILCORE);
  IL_GET_SERVICE(ILCONFIGURATION);

  return 0;
}

