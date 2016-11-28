#ifndef ILPRINT_HPP
#define ILPRINT_HPP

#include <iostream>
#include <glog/logging.h>

#ifdef NDEBUG
#define IL_PRINT (std::cerr << std::endl)
#else
#define IL_PRINT DLOG(INFO)
#endif

#endif // ILPRINT_HPP
