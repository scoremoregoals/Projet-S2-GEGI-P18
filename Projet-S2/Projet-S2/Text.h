#ifndef TEXT_H
#define TEXT_H

#include <QGraphicsTextItem>
#include <QFont>

class Text : public QGraphicsTextItem
{
public:
	Text();

	void draw();

	void set_value(int value);
	void set_name(QString name);

	int get_value() { return _value; }
	QString get_name() { return _name; }
private:
	QString _name;
	int _value;
};

#endif // TEXT_H