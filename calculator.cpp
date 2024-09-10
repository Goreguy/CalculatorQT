#include "calculator.h"

QMap<QObject*, void (Calculator::*)(QObject*, QString&)> Calculator::mapButtonFunc;

QMap  <QObject*, State> Calculator::mapButtonState;

double Calculator::mainResult{0};
