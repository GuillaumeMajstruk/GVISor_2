#ifndef ENGINE_H
#define ENGINE_H

#include "../global_functions.h"

struct Range
{
    Range(QString lval, QString rval):
        low_value(lval),
        high_value(rval) {}
    QString low_value;
    QString high_value;
};

struct Engine_SN_Range
{
    Engine_SN_Range() { e_ranges = new QVector<Range*>(); }
    QVector<Range*>     *e_ranges;
    QString             e_type;
};

enum class engineType
{
    GE90,
    GE90_1,
    CFM56_5A,
    CFM56_5B,
    CFM56_5C,
    GP7200,
    CF6_80_E1,
    CF6_80_C2,
    Error
};



class Engine
{
public:
    Engine(const QString &engineSN_input);

    void        setEngineSN(const QString &engineSN);
    void        setEngineType();

    QString     getEngineSN() const { return engine_sn; }
    QString     getEngineTypeStr() const { return engine_type_str; }
    engineType  getEngineType() const { return engine_type; }
    static QVector<Engine_SN_Range>     all_engine_sn;

private:
    QString     engine_sn;
    engineType  engine_type;
    QString     engine_type_str;
};

#endif // ENGINE_H
