#ifndef TEXT_H
#define TEXT_H

#include <QGraphicsTextItem>
#include <QFont>

class Text : public QGraphicsTextItem
{
public:
	/**
	 * @brief      Constructor
	 */
	Text();

	/**
	 * @brief      Draw a text from a set name
	 */
	void draw();

	/**
	 * @brief      Set the text value (float)
	 *
	 * @param[in]  value  Value to show
	 */
	void set_value(float value);

	/**
	 * @brief      Set name of the new text
	 *
	 * @param[in]  name  Name of the string
	 */
	void set_name(QString name);

	//getters
	int get_value() { return _value; }
	QString get_name() { return _name; }
private:
	QString _name;
	float _value;
};

#endif // TEXT_H