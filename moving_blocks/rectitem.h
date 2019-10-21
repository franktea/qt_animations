#ifndef RECTITEM_H
#define RECTITEM_H

#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>

class RectItem : public QGraphicsItem
{
public:
    RectItem();

    // QGraphicsItem interface
public:
    virtual QRectF boundingRect() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

protected:
    virtual void advance(int phase) override;
private:
    qreal angel;
    qreal speed;
    void DoCollision();
};

#endif // RECTITEM_H
