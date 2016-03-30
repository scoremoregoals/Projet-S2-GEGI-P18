#include "Text.h"

Text::Text()
{
}

void Text::draw()
{
	setPlainText(_name + QString(" ") + QString::number(_value));
	setDefaultTextColor(Qt::white);
	setFont(QFont("times", 16));
}

void Text::set_value(float value)
{
	_value = value;
}

void Text::set_name(QString name)
{
	_name = name;
}