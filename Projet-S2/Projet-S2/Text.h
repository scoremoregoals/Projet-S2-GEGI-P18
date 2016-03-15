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
	void set_name(char * name);

	int get_value() { return _value; }
	char* get_name() { return _name; }
private:
	char* _name;
	int _value;
};

#endif // TEXT_H