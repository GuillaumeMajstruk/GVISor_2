#include "error.h"

error::error(const ErrorType &e_type, const QString& e_title, const QString& e_des, const QString& e_num):
    m_type(e_type),
    m_title(e_title),
    m_des(e_des),
    m_num(e_num)
{
}

void    error::display()
{
    switch (this->m_type)
    {
    case ErrorType::Critical:
        QMessageBox::critical(NULL, this->m_title, QString("Error: " + this->m_des + " error #" + this->m_num));
        break;
    case ErrorType::Recoverable:
        QMessageBox::warning(NULL, this->m_title, QString("Attention: " + this->m_des));
        break;
    }
}
