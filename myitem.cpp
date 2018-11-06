#include "myitem.h"
#include <QPixmap>
#include <QtDebug>
#include "handler.h"
#include <QCursor>
myItem::myItem()
{
    this->setPixmap(QPixmap(":/mouse/Background.png").scaled(100,100));
    this->start=false;
    this->mouse=false;
    this->setCursor(QCursor(QPixmap(":/mouse/hammer1.png").scaled(50,50)));

}

void myItem::setPic(QString path)
{

    this->setPixmap(QPixmap(path).scaled(100,100));

}

void myItem::setMouse(bool mouse)
{
    this->mouse =mouse;
}

bool myItem::isMouse()
{
    return  this->mouse;
}

void myItem::setStart(bool start)
{
    this->start =start;
}

bool myItem::isStart()
{
    return this->start;
}

void myItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(QPixmap(":/mouse/Hammer2.png").scaled(50,50)));
    if(this->isStart())
    {
        handler * hand = handler::getInstance();
        if(this->isMouse())
        {
            hand->addScore();
            qDebug()<<"打到老鼠";
            this->setPic(":/mouse/bearMouse.png");
            this->mouse =false;
        }
        else {
            qDebug()<<"不是老鼠";
        }
    }

}

void myItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(QPixmap(":/mouse/hammer1.png").scaled(50,50)));



}


