#include "calculatorapp.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    CalculatorApp calculator;

    calculator.show();

    return a.exec();
}
