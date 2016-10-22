#include "timetablemodel.h"

TimetableModel::TimetableModel(QObject *qml, QObject *parent)
    : QAbstractTableModel(parent)
{
    qmlMain = qml;
//    connect(this, SIGNAL(setNextLectureText(QString)), qmlMain, SLOT(setNextText(QString)));
}

bool TimetableModel::loadCSV(QString path)
{
    QDateTime::fromString("", "");
    QDateTime cur = QDateTime::currentDateTime();
    lectStart <<cur.addSecs(-1500) <<cur.addSecs(-200) <<cur.addSecs(1500);
    lectEnd <<cur.addSecs(-700) <<cur.addSecs(1000) <<cur.addSecs(2000);
    lectureNames <<"Prvni prednaska na kterou nikkdy nezapomeneme, ani kdyby vyhorelo cele slunce" <<"Jak se vari dort." <<"Dalsi prednaska";
    lectors <<"Poradatele" <<"Petr Zelina" <<"Jiny Autor";
}

int TimetableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return lectureNames.length();
    // FIXME: Implement me!
}

int TimetableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return 4;
    // FIXME: Implement me!
}

QVariant TimetableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    int row = index.row();

    if(role == Qt::DisplayRole)
    {
        QString out;
        switch (index.column()) {
        case 0:
            out = lectStart.at(row).toString("hh:mm");
            break;
        case 1:
            out = lectEnd.at(row).toString("hh:mm");
            break;
        case 2:
            out = lectureNames.at(row);
            break;
        case 3:
            out = lectors.at(row);
            break;
        default:
            out = "pes";
            break;
        }
        return QVariant(out);
    }
    else if(role == Qt::BackgroundRole)
    {
        QDateTime cur = QDateTime::currentDateTime();

        if(lectStart[row] <= cur and lectEnd[row] >= cur)
        {
            return QBrush(QColor(0, 120, 0));
        }
    }
    else if(role == Qt::SizeHintRole)
    {
        int w = 50;
        if(index.column() == 2) w = 200;
        if(index.column() == 3) w = 100;
        int len = (int)(lectStart[row]).secsTo(lectEnd[row]);
        //qDebug() <<"sizeHimt " <<len;
        int h = std::max(len/20, 27);

        return QSize(w, h);
    }
    return QVariant();
}

void TimetableModel::ClickedOnIndex(QModelIndex index)
{
    QVariant returnedValue;
    QVariant msg = lectureNames[index.row()];
    QMetaObject::invokeMethod(qmlMain, "setNextText",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, msg));
}

