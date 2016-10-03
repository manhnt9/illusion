#ifndef ILFACTORY_H
#define ILFACTORY_H

#include <QString>

namespace il {

class ILOperation;

class ILFactory
{
public:
                            ILFactory();

    static ILFactory*       instance();

    void                    init();
    ILOperation*            create(const int);
    QString                 getName(const int) const;

private:
    static ILFactory*       instance_;
};

} // namespace il

#include "ilfactory.ipp"

#endif // ILFACTORY_H
