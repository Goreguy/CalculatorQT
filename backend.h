#ifndef BACKEND_H
#define BACKEND_H

#include "calculator.h"
#include <functional>

enum DigitState
{
    FirstNumber=0,
    SecondNumber=1,
    Save=2

};

enum OperationState
{
    Plus,
    Minus,
    Multiply,
    Divide
};


class Backend: public Calculator
{
    Q_OBJECT
private:

    typedef double (Backend::*CalculateFunction)(double* stack);
    QMap  <OperationState, CalculateFunction> mapOperationCalculate;


    typedef void (Backend::*DigitDotFunction)(double* stack, QObject *);
    QMap  <State, DigitDotFunction> mapDigitDotCalculate;

    QMap  <QString, int > mapButtontext;
    QMap  <QString, OperationState > mapOperationButtontext;

    double stackNumber[2]={0,0};

    OperationState operation{Plus};

    QString empty = "";


public:

    Backend( QWidget* parent=0)
        : Calculator(parent)
    {

        mapButtontext["0"]=0;
        mapButtontext["1"]=1;
        mapButtontext["2"]=2;
        mapButtontext["3"]=3;
        mapButtontext["4"]=4;
        mapButtontext["5"]=5;
        mapButtontext["6"]=6;
        mapButtontext["7"]=7;
        mapButtontext["8"]=8;
        mapButtontext["9"]=9;
        mapOperationButtontext["+"]=Plus;
        mapOperationButtontext["-"]=Minus;
        mapOperationButtontext["*"]=Multiply;
        mapOperationButtontext["/"]=Divide;

        mapDigitDotCalculate[Digit]=&Backend::numberWrite;
        mapDigitDotCalculate[Dot]=&Backend::dotNumberWrite;

        mapOperationCalculate[Plus]=&Backend::plus;
        mapOperationCalculate[Minus]=&Backend::minus;
        mapOperationCalculate[Multiply]=&Backend::multiply;
        mapOperationCalculate[Divide]=&Backend::divide;

    }
    //функции состояний
    void cleanFunc(QObject *object, QString& text) override;//очистка
    void dotFunc(QObject *object, QString& text) override;//точка
    void operationFunc(QObject *object, QString& text) override;//операция
    void digitFunc(QObject *object, QString& text) override;//вставка числа
    void calculate(QObject *object, QString& text) override;//вычисление


    State getState(QObject* object);
    QString getName(QObject* object);

    void engine (QObject* object) ;//движок
    void numberWrite (double* stack, QObject *object);// ввести число
    void dotNumberWrite (double* stack, QObject *object);


    //операции
    double plus(double* stack);
    double minus(double* stack);
    double divide(double* stack);
    double multiply(double* stack);


public slots:
    void slotEngine(QObject* send);

};
#endif // BACKEND_H
