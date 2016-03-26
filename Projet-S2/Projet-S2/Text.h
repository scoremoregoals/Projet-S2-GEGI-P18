#ifndef TEXT_H
#define TEXT_H

#include <QGraphicsTextItem>
#include <QFont>

class Text : public QGraphicsTextItem
{
public:
	Text();

	void draw();

	void set_value(float value);
	void set_name(QString name);

	int get_value() { return _value; }
	QString get_name() { return _name; }
private:
	QString _name;
	float _value;
};

#endif // TEXT_H