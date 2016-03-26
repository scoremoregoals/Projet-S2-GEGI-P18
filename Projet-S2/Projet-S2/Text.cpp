#include "Text.h"

Text::Text()
{
}

void Text::draw()
{
	setPlainText(_name + QString(" ") + QString::number(_value));
	setDefaultTextColor(Qt::black);
	setFont(QFont("times", 16));
}

void Text::set_value(int value)
{
	_value = value;
}

void Text::set_name(QString name)
{
	_name = name;
}