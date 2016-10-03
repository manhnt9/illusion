#ifndef BENCHMARKSUITE_H
#define BENCHMARKSUITE_H

#include "illusion.hpp"
#include "ilstate.hpp"
#include "iltype.hpp"
#include <QObject>

namespace il {

class ILOperation;
typedef std::vector<ILOperation*> OpList;

class ILSuite : public QObject
{
    Q_OBJECT

public:
    struct                  Config;

                            ILSuite(QObject*, const Type t);
                            ~ILSuite();

    void                    init();
    void                    run();

    std::string             name() const;
    Type                    type() const;
    Config*                 config() const;
    State                   state() const;

    int                     completedCount() const;
    int                     failedCount() const;

signals:
    void                    stateUpdated();
    void                    done();

public slots:
    void                    operationFinished(qint32 id);
    int                     getProgress() const;

private:
    Type                    type_;
    Config*                 config_;
    State                   state_;

    OpList                  opList_;
    quint32                 completedCount_;
    quint32                 failedCount_;
};

} // namespace il

#include "ilsuite.ipp"

#endif // BENCHMARKSUITE_H
