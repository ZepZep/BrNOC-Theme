#ifndef CONTROLFORM_H
#define CONTROLFORM_H

#include <QWidget>
#include <QTableView>
#include <QCloseEvent>

#include <QQmlApplicationEngine>
#include <QQmlComponent>

#include <QDate>
#include <QTime>
#include <QDebug>

#include "timetablemodel.h"

namespace Ui {
class ControlForm;
}

class ControlForm : public QWidget
{
    Q_OBJECT

public:
    explicit ControlForm(QWidget *parent = 0);
    ~ControlForm();

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::ControlForm *ui;

    QQmlApplicationEngine *qmlEngine;
    QQmlComponent *qmlMainComp;
    QObject *qmlMain;

    TimetableModel *timetableModel;

private slots:
    void tableClicked(QModelIndex index);
//    void timerEvent(QTimerEvent *e);


    void on_pBBreak_clicked();
};

#endif // CONTROLFORM_H
