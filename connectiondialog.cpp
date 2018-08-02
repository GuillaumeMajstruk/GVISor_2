#include "connectiondialog.h"
#include "ui_connectiondialog.h"

using namespace QXlsx;

connectionDialog::connectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::connectionDialog)
{
    ui->setupUi(this);
    connect(this, &connectionDialog::autenticationSuccess, this, &connectionDialog::accept);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &connectionDialog::reject);
    this->setWindowFlag(Qt::FramelessWindowHint);
}

connectionDialog::~connectionDialog()
{
    delete ui;
}

void connectionDialog::on_ok_button_clicked()
{
    if (ui->matricule_LE->text().isEmpty())
    {
        error(ErrorType::Recoverable, USER_EMPTY_ERRTITLE, USER_EMPTY_ERRDES, RECOVERABLE_ERRNUM).display();
        return ;
    }

    QString current_input_mat = ui->matricule_LE->text();
    QString current_mat;

    Document operatorsDoc(":/database/Ressources/excel_files/operators.xlsx");
    if (!operatorsDoc.selectSheet("operators"))
    {
        error err(ErrorType::Critical, LOADUSERS_INIT_ERRTITLE, LOADUSERS_INIT_ERRDES, LOADUSERS_INIT_ERRNUM);
        err.display();
        exit(err.getErrorNum().toInt());
    }
    for (int current_row = 1; current_row <= operatorsDoc.currentWorksheet()->dimension().lastRow(); current_row++)
    {
        if ((current_mat = operatorsDoc.read(current_row, 1).toString()) == current_input_mat)
        {
            m_current_operator = operatorsDoc.read(current_row, 2).toString();
            m_current_operator[0] = m_current_operator[0].toUpper();
            QMessageBox::information(NULL, "Bienvenue !", "Bienvenue " + (const QString)m_current_operator + " !");
            emit autenticationSuccess();
            return ;
        }
    }
    error(ErrorType::Recoverable, USER_NOT_FOUND_ERRTITLE, USER_NOT_FOUND_ERRDES, RECOVERABLE_ERRNUM).display();
    return ;
}
