#include "backend.h"

static DigitState digitState{FirstNumber};
static State pastState {Default};
static double dot{1};

State Backend::getState(QObject *object)
{
    return mapButtonState.value(object);
}

QString Backend::getName(QObject *object)
{
    return (object)->objectName();
}


void Backend::dotFunc(QObject *object, QString& text )
{

    if (pastState==Default) return;
    pastState = getState(object);

}

void Backend::operationFunc(QObject *object, QString& text)
{

    if(pastState==Operation)
    {
        operation = mapOperationButtontext[getName(object)];
        return;
    }

    pastState =Operation;
    dot=1;

    if(stackNumber[SecondNumber]!=0)
    {
        calculate(object,empty);
    }
    operation = mapOperationButtontext[getName(object)];

    if(digitState==FirstNumber)
    {
        digitState=SecondNumber;
    }

}

void Backend::digitFunc(QObject *object, QString& text)
{

    if(pastState==Default) pastState =Digit;
    if(pastState==Operation) pastState =Digit;

    (this->*mapDigitDotCalculate[pastState])(stackNumber,object);

}

void Backend::numberWrite (double* stack, QObject *object)
{
    if (stack[digitState]==0)
    {
        stack[digitState]=mapButtontext[getName(object)];
        dot=10;
        return;
    }
    stack[digitState] = stack[digitState] * 10 + mapButtontext[getName(object)];

}

void Backend::dotNumberWrite (double* stack, QObject *object)
{
    stack[digitState] += (mapButtontext[getName(object)]/dot);
    dot*=10;
}


void Backend::cleanFunc(QObject *object, QString& text)
{
    stackNumber[0]=0;
    stackNumber[1]=0;
    mainResult=0;
    dot=1;
    digitState = FirstNumber;
    pastState =Default;

    calculate(object,empty);
}


void Backend::calculate(QObject *object, QString& text)
{

    if (getState(object) == Equal)
    {
        mainResult = (this->*mapOperationCalculate[operation])(stackNumber);
        return;
    }

    mainResult = (this->*mapOperationCalculate[operation])(stackNumber);
    stackNumber[FirstNumber] = mainResult;
    stackNumber[SecondNumber]=0;

}

double Backend::plus(double* stack)
{

    double c = stack[FirstNumber] + stack[SecondNumber];
    digitState = FirstNumber;
    return c;

}

double Backend::minus(double* stack)
{
    double c = stack[FirstNumber] - stack[SecondNumber];
    digitState = FirstNumber;
    return c;
}

double Backend::divide(double* stack)
{
    double c{};
    if (stack[SecondNumber]==0) return c;
    c = stack[FirstNumber] / stack[SecondNumber];
    digitState = FirstNumber;
    return c;
}

double Backend::multiply(double* stack)
{
    double c = stack[FirstNumber] * stack[SecondNumber];
    digitState = FirstNumber;
    return c;
}

void Backend::engine(QObject *object)
{
    (this->*mapButtonFunc[object])(object,empty);

}
