#ifndef MYSCENE_H
#define MYSCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <myitem.h>
#include <QTimer>

class myScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit myScene(QObject *parent = nullptr);

signals:

public slots:
    void showMouse();
    void startGame();
    void pauseGame();
    void stopGame();
private:
    myItem *Item[16];
    myItem *Items[4][4];
    QTimer *pTimer;
};

#endif // MYSCENE_H
