#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QPushButton>
#include <QtWidgets>
#include <QString>
#include <QQueue>
#include <QMap>


enum State
{
    Digit,
    Operation,
    Equal,
    Clean,
    Dot,
    Default
};

class Calculator: public QWidget
{
    Q_OBJECT

protected:
    typedef void (Calculator::*Function)(QObject*, QString& );
    static QMap<QObject*, void (Calculator::*)(QObject*, QString&)> mapButtonFunc;

    static QMap  <QObject*, State> mapButtonState;
    static double mainResult;


public:

    //окно
    Calculator(QWidget* wind = 0  )
        :QWidget (wind)
    {

    }

    virtual void dotFunc (QObject *object, QString& text)=0;
    virtual void digitFunc (QObject *object, QString& text)=0;
    virtual void operationFunc (QObject *object, QString& text)=0;
    virtual void calculate (QObject *object, QString& text)=0;
    virtual void cleanFunc (QObject *object, QString& text)=0;



public slots:
    void slotButtonClicked();

signals:
    void signalEngine(QObject* send);
    void signalShowlabel(QObject *object, double &result);

};









#endif // CALCULATOR_H
