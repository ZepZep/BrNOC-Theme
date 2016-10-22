#include "controlform.h"
#include "ui_controlform.h"

ControlForm::ControlForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ControlForm)
{
    ui->setupUi(this);

    qmlEngine = new QQmlApplicationEngine(this);
    //qmlEngine->load(QUrl(QStringLiteral("comp/main.qml")));
    qmlMainComp = new QQmlComponent(qmlEngine, QUrl::fromLocalFile("comp/main.qml"));
    qmlMain = qmlMainComp->create();

    qmlMain->setProperty("visible", false);

    timetableModel = new TimetableModel(qmlMain, this);
    timetableModel->loadCSV("");
    ui->tableView->setModel(timetableModel);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();

    connect(ui->tableView, SIGNAL(clicked(QModelIndex)),this, SLOT(tableClicked(QModelIndex)));
}

ControlForm::~ControlForm()
{
    delete ui;
}

void ControlForm::closeEvent(QCloseEvent *event)
{
    delete qmlMain;
    event->accept();
}

void ControlForm::tableClicked(QModelIndex index)
{
    timetableModel->ClickedOnIndex(index);
}

void ControlForm::on_pBBreak_clicked()
{
//    ui->tableView->resizeColumnsToContents();
//    ui->tableView->resizeRowsToContents();
    bool visible = qmlMain->property("visible").toBool();
    qmlMain->setProperty("visible", !visible);
}

/*
nastavovani textu po kliknuti
custom text
starts in
logy
*/
