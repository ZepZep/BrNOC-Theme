#ifndef TIMETABLEMODEL_H
#define TIMETABLEMODEL_H

#include <QAbstractTableModel>
#include <QStringList>
#include <QDateTime>
#include <QBrush>
#include <QFont>

#include <QDebug>

class TimetableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit TimetableModel(QObject *qml, QObject *parent = 0);

    bool loadCSV(QString path);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    QList<QDateTime> lectStart;
    QList<QDateTime> lectEnd;
    QStringList lectureNames;
    QStringList lectors;

    QObject *qmlMain;

public slots:
    void ClickedOnIndex(QModelIndex index);

signals:
//    void setNextLectureText(QString text);

};

#endif // TIMETABLEMODEL_H
