#include "mytriangle.h"

#include "config.h"

#include <QPushButton>
#include <QPainter>
#include <QtMath>
#include <QLabel>
#include <QHBoxLayout>
#include <QDebug>

MyTriangle::MyTriangle(QWidget *parent) : QWidget(parent),
    m_startx(0), m_starty(0), m_triangleHeight(0), m_triangleWidth(0)
{
}

void MyTriangle::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(Qt::NoPen);

//    painter.setBrush(QColor(Qt::blue));
//    painter.drawRect(0,0,this->width(),this->height());

    QPolygon trianglePolygen;
    trianglePolygen << QPoint(m_startx, m_starty + m_triangleHeight);
    trianglePolygen << QPoint(m_startx + m_triangleWidth/2,  m_starty);
    trianglePolygen << QPoint(m_startx + m_triangleWidth, m_starty + m_triangleHeight);
    QPainterPath drawPath;
    drawPath.addPolygon(trianglePolygen);

    painter.setBrush(SHADOW_COLOR);
    painter.drawPath(drawPath);

}
