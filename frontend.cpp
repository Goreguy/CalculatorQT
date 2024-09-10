#include "frontend.h"

static State pastState{Default};
static Dotted dotState {Nondot};
static ZeroState zeroState {Zero};

//дисплей
void Frontend::createLabel()
{
    label = new QLabel(this);
    label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    label->setAlignment(Qt::AlignBottom | Qt::AlignRight);
    QFont font("Arial", 15, QFont::Bold); // создаем новый шрифт
    label->setFont(font);
    label->setText("\n0");
}

QGridLayout *Frontend::createLayout()
{
    QGridLayout *layer = new QGridLayout;

    layer->setSpacing(15);
    layer->addWidget(label, 0, 0, 1, 4);
    return layer;
}

//слой кнопок
void Frontend::createButtonnet(QGridLayout *layer)
{
    QChar const numbers[10]={ '7','8','9','4','5','6','1','2','3','0'};
    QChar const operations[4]={ '+','-','/','*'};

    layer->addWidget(createButton("C", &Calculator::cleanFunc,Clean), 1, 3);
    layer->addWidget(createButton(".", &Calculator::dotFunc, Dot), 5, 1);
    layer->addWidget(createButton("=", &Calculator::calculate, Equal), 5, 2);

    for (int i = 0; i < 10; ++i)
    {
        layer->addWidget(createButton(numbers[i], &Calculator::digitFunc, Digit), i / 3 + 2, i % 3);
    }

    for (int i = 0; i < 4; ++i)
    {
        layer->addWidget(createButton(operations[i], &Calculator::operationFunc, Operation), i + 2, 3);
    }

}

//создание кнопки
QPushButton *Frontend::createButton(const QString &str, void (Calculator::*function)(QObject*, QString&), State state)
{
    QPushButton *pushb = new QPushButton(this);
    pushb->setObjectName(str);
    pushb->setText(str);
    pushb->setMinimumSize(30, 30);
    pushb->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(pushb, &QPushButton::clicked, this, &Calculator::slotButtonClicked);
    mapButtonFunc.insert(pushb, function);
    mapButtonState.insert(pushb, state);
    return pushb;
}

void Frontend::showInterface()
{
    createLabel();
    QGridLayout *layout = createLayout();
    createButtonnet(layout);

    setLayout(layout);
    resize(250, 350);
}

//показать текст

void Frontend::showOnLabel(QObject *object, double &result)
{
    QString objName = object->objectName();

    (this->*mapButtonFunc[object])(object, objName);
    label->setText(currentText+ "\n" + QString::number(result));

}


void Frontend::dotFunc (QObject *object, QString& text)
{

    if (dotState==Havedot) return;
    if (pastState==Digit)
    {
        currentText +=text;
        pastState=Dot;
        dotState=Havedot;
    }

    zeroState=Zero;

}

void Frontend::nullDel (QString& text)
{
    text.chop(1);
}

void Frontend::null (QString& text)
{

    if(pastState==Default) zeroState=NoZero;
}

void Frontend::digitFunc (QObject *object, QString& text)
{
    if (text=="0")
    {
        (this->*mapNullState[zeroState])(text);
    }
    currentText +=text;
    pastState=Digit;

}

void Frontend::operationFunc (QObject *object, QString& text)
{

    if(pastState==Default) currentText.chop(1);  // Удаляем последний символ
    if(pastState==Dot) currentText.chop(1);

    if (currentText=="")
    {
        currentText="0";
    }
    currentText +=text;

    dotState=Nondot;
    pastState=Default;
    zeroState=Zero;

}

void Frontend::calculate (QObject *object, QString& text)
{

    return;
}

void Frontend::cleanFunc (QObject *object, QString& text)
{
    currentText="";
    pastState=Default;
    dotState=Nondot;
}



