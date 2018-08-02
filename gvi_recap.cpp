#include "gvi_recap.h"
#include "ui_gvi_recap.h"

gvi_recap::gvi_recap(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gvi_recap)
{
    ui->setupUi(this);
    setWindowTitle("Récapitulatif de la GVI avant validation");
    connect(ui->modify_informations_PB, &QPushButton::clicked, this, &gvi_recap::close);
    connect(ui->validate_informations_PB, &QPushButton::clicked, this, &gvi_recap::askingExport);
}

gvi_recap::~gvi_recap()
{
    delete ui;
}

void    gvi_recap::askingExport()
{
    emit exportRequired();
}
