#ifndef ILHTTPOPERATION_IPP
#define ILHTTPOPERATION_IPP

namespace il {

inline void ILHttpOperation::reset() {
    http_ = std::make_shared<HttpManager>();
}

} // namespace il

#endif // ILHTTPOPERATION_IPP
