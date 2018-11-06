#include "myscene.h"

myScene::myScene(QObject *parent) : QGraphicsScene(parent)
{
    for(int i=0;i<16;i++)
    {
    this->Item[i]=new myItem;
      this->Item[i]->setPos(i/4*this->Item[i]->boundingRect().width(),
                            i%4*this->Item[i]->boundingRect().height());
    this->addItem(this->Item[i]);
    }
    this->pTimer=new QTimer;
    connect(this->pTimer,SIGNAL(timeout()),this,SLOT(showMouse()));
   // this->pTimer->start(2000);//启动定时器
}
void myScene::showMouse()
{
    //3个随机数
    int count =rand()%3+1;
    //刷新16张照片
    for(int i = 0;i<16;i++)
    {
        this->Item[i]->setPic(":/mouse/Background.png");
        this->Item[i]->setMouse(false);
    }
    //生成随机三张老鼠
    for(int i =0;i<count;i++)
    {
        int index =rand()%16;
        this->Item[index]->setPic(":/mouse/mouse.png");
        this->Item[index]->setMouse(true);
    }
}

void myScene::startGame()
{

    for(int i =0;i<16;i++)
    {
        this->Item[i]->setStart(true);
    }
    this->pTimer->start(800);

}

void myScene::pauseGame()
{

    for(int i =0;i<16;i++)
    {
        this->Item[i]->setStart(false);
    }
    this->pTimer->stop();

}

void myScene::stopGame()
{
    this->pTimer->stop();
    for(int i = 0;i<16;i++)
    {
        this->Item[i]->setPic(":/mouse/Background.png");
        this->Item[i]->setMouse(false);
    }

}
