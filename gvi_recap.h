#ifndef GVI_RECAP_H
#define GVI_RECAP_H

#include <QWidget>
#include "global_functions.h"

namespace Ui {
class gvi_recap;
}

class gvi_recap : public QWidget
{
    Q_OBJECT

public:
    explicit gvi_recap(QWidget *parent = 0);
    ~gvi_recap();

private:
    Ui::gvi_recap *ui;

public slots:
    void    askingExport();
signals:
    void    exportRequired();
};

#endif // GVI_RECAP_H
