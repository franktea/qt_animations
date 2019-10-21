#include "rectitem.h"

RectItem::RectItem()
{
    // set start rotation
    angel = qrand() % 360;
    setRotation(angel);

    // set start speed
    speed = 5;

    // random set position
    int x = 0;
    int y = 0;
    if(qrand() % 2)
    {
        x = qrand() % 140;
        y = qrand() % 140;
    }
    else
    {
        x = qrand() % -140;
        y = qrand() % -140;
    }

    setPos(mapToParent(x, y));
}

QRectF RectItem::boundingRect() const
{
    return QRect(0, 0, 20, 20);
}

void RectItem::paint(QPainter *painter, const QStyleOptionGraphicsItem* /*option*/, QWidget* /*widget*/)
{
    QRectF rect = boundingRect();
    QBrush brush(Qt::gray);

    // basic collision detection
    if(scene()->collidingItems(this).isEmpty())
    {
        //no collision
        brush.setColor(Qt::green);
    }
    else
    {
        brush.setColor(Qt::red);

        // set new position
        DoCollision();
    }

    painter->drawRect(rect);
    painter->fillRect(rect, brush);
}

void RectItem::advance(int phase)
{
    if(!phase) return;
    setPos(mapToParent(0, -speed));
}

void RectItem::DoCollision()
{
    // change direction
    if(qrand() % 2)
    {
        setRotation(rotation() + 180 + qrand() % 10);
    }
    else
    {
        setRotation(rotation() + 180 + qrand() % -10);
    }

    // see if the new position is in bounds
    QPointF point = mapToParent(-boundingRect().width(), -boundingRect().width() - 2);

    if(!scene()->sceneRect().contains(point))
    {
        // move it back in bounds
        //point = mapToParent(0, 0);
    }
    else
    {
        setPos(point);
    }
}
