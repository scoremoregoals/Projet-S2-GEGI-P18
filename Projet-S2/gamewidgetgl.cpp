#include "gamewidgetgl.h"

using namespace std;

GamePainter::GamePainter()
{
    // http://www.informit.com/articles/article.aspx?p=1405557&seqNum=2
    // At the end, we call createGradient() to set up the QRadialGradient used to fill the background,
    //and createGLObject() to create the OpenGL cube object. By doing all of this in the constructor,
    //we obtain snappier results later on, when we need to redraw the scene.

    std::cout << "GameWidgetGL Constructor" << std::endl;

    init();
}

GamePainter::~GamePainter()
{
}

void GamePainter::paint(QPainter *painter, QPaintEvent *event)
{
    painter->fillRect(event->rect(), background);
    painter->translate(100, 100);
    painter->setPen(textPen);
    painter->setFont(textFont);
    painter->drawText(QRect(-50, -50, 100, 100), Qt::AlignCenter, "Ingenium Natus");
}

// Initialize everything to be ready to draw
void GamePainter::init()
{

    std::cout << "Init" << std::endl;

    //Set a background color with a gradient
    gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
    gradient.setCenter(0.45, 0.50);
    gradient.setFocalPoint(0.40, 0.45);
    gradient.setColorAt(0.0, QColor(105, 146, 182));
    gradient.setColorAt(0.4, QColor(81, 113, 150));
    gradient.setColorAt(0.8, QColor(16, 56, 121));

    // Set font
    textFont.setPixelSize(50);

    std::cout << "gradient setup done" << endl;
    QPainter *p;
    drawBackground(p);
    std::cout << "background setup done" << endl;
}


// Draw Background
void GamePainter::drawBackground(QPainter *p)
{
   background = QBrush(QColor(64, 32, 64));
}


Widget::Widget(GamePainter *helper, QWidget *parent) : QWidget(parent), helper(helper)
 {
     elapsed = 0;
     setFixedSize(200, 200);
 }

void Widget::animate()
 {
     update();
 }

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    helper->paint(&painter, event);
    painter.end();
}
