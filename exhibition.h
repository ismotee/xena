#ifndef EXHIBITION_H
#define EXHIBITION_H

#include <vector>
#include  <QDate>
#include <QTime>

class day {

    QDate date;
    QTime openTime;
    QTime closeTime;
    std::vector<QTime> visitors;

public:
    day(QDate, QTime opens, QTime closes);
    void addVisitor(QTime);
    std::vector<QTime> getVisitors() {return visitors;}
    int getVisitorsSum() {return visitors.size();}
    QDate getDate () {return date;}
    QTime getOpenTime() {return openTime;}
    QTime getCloseTime() {return closeTime;}
};


class exhibition
{
private:
    QString artistName;
    QString exhibitionName;
    QDate openingDate;
    QDate closingDate;
    std::vector<day> days;

public:
    exhibition(QString artist,QString exhibition,QDate from, QDate to);

    std::vector<int> getVisitorsChart () {std::vector<int> result; for(int i = 0; i < days.size();i++) result.push_back(days[i].getVisitorsSum()); return result;}
    std::vector<QTime> getVisitorsByDate (QDate date) {
        for(int i =0;i < days.size(); i++ )
            if(date == days[i].getDate())
                return days[i].getVisitors();
        std::vector<QTime> kk;
        return kk;
    }

};

#endif // EXHIBITION_H
