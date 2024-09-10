#ifndef FRONTEND_H
#define FRONTEND_H

#include "calculator.h"


enum Dotted
{
    Havedot,
    Nondot
};

enum ZeroState
{
    NoZero,
    Zero
};



class Frontend: public Calculator
{
    Q_OBJECT
private:
    QLabel* label;//дисплей

    typedef void (Frontend::*CalcFunc)(QString& );
    QMap <ZeroState, CalcFunc> mapNullState;

    QString currentText {""};

    Calculator* calc;



public:

    Frontend( QWidget* parent=0)
        : Calculator(parent)
    {

        connect(this, &Calculator::signalShowlabel, this, &Frontend::slotShowlabel);
        showInterface();

        mapNullState[NoZero]=&Frontend::nullDel;
        mapNullState[Zero]=&Frontend::null;


    }

    void createLabel();//дисплей

    void showInterface();//интерфейс

    void showOnLabel (QObject *object,double &result);


    QGridLayout* createLayout();
    void createButtonnet(QGridLayout* layout);

    QPushButton* createButton(const QString& str,void (Calculator::*function)(QObject*, QString& ), State state);

    void cleanFunc(QObject *object, QString& text) override;//очистка
    void dotFunc(QObject *object, QString& text) override;//точка
    void operationFunc(QObject *object, QString& text) override;//операция
    void digitFunc(QObject *object, QString& text) override;//вставка числа
    void calculate(QObject *object, QString& text) override;//вычисление

    void nullDel (QString& text);
    void null (QString& text);





public slots:
    void slotShowlabel(QObject *object, double &result);


};


#endif // FRONTEND_H
