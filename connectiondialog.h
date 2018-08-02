#ifndef CONNECTIONDIALOG_H
#define CONNECTIONDIALOG_H

#include "global_functions.h"
#include "mainwindow.h"
#include "error.h"
#include <QDialog>

namespace Ui {
class connectionDialog;
}

class  connectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit connectionDialog(QWidget *parent = 0);
    inline QString getOperatorName() const { return m_current_operator; }
    ~connectionDialog();

private:
    Ui::connectionDialog    *ui;
    QString                 m_user_mat;
    QString                 m_current_operator;

private slots:
    void    on_ok_button_clicked();
signals:
    void    autenticationSuccess();
};

#endif // CONNECTIONDIALOG_H
