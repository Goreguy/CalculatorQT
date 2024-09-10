#include "calculator.h"
#include "frontend.h"
#include "backend.h"

void Calculator::slotButtonClicked()
{
    QObject *object = sender();
    emit signalEngine(object);
    emit signalShowlabel(object, mainResult);

}


void Backend::slotEngine(QObject* sender)
{
    engine(sender);
}

void Frontend::slotShowlabel(QObject *object, double &result)
{
    showOnLabel (object,result);
}

