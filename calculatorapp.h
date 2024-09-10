#ifndef CALCULATORAPP_H
#define CALCULATORAPP_H
#include "frontend.h"
#include "backend.h"
#include "calculator.h"

class CalculatorApp: public QWidget {
    Q_OBJECT
private:
    Frontend *frontend; // Объект фронтенда
    Backend *engine;     // Объект энджина

public:
    CalculatorApp(QWidget *parent = nullptr) : QWidget(parent)
    {

        frontend = new Frontend(this);
        engine = new Backend(this);

        connect(frontend, &Calculator::signalEngine, engine, &Backend::slotEngine);


    }

    ~CalculatorApp()
    {
        delete frontend;
        delete engine;
    }
};

#endif // CALCULATORAPP_H
