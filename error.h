#ifndef ERROR_H
#define ERROR_H

#   include "global_functions.h"

enum class ErrorType
{
    Recoverable,
    Critical
};

class error
{
public:
    error(const ErrorType& e_type, const QString &e_title, const QString& e_des, const QString &e_num);
    inline QString         getErrorType()  const { return m_title; }
    inline QString         getError()      const { return m_des; }
    inline QString         getErrorNum()   const { return m_num; }

public:
    void            display();

private:
    ErrorType       m_type;
    QString         m_title;
    QString         m_des;
    QString         m_num;
};

#endif // ERROR_H
