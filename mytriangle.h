#ifndef MYTRIANGLE_H
#define MYTRIANGLE_H

#include <QWidget>

class MyTriangle : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(double startx READ getStartX WRITE setStartX)
    Q_PROPERTY(double starty READ getStartY WRITE setStartY)
    Q_PROPERTY(double triangleHeight READ getTriangleHeight WRITE setTriangleHeight)
    Q_PROPERTY(double triangleWidth READ getTriangleWidth WRITE setTriangleWidth)
    double m_startx;

    double m_starty;

    double m_triangleHeight;

    double m_triangleWidth;

public:
    explicit MyTriangle(QWidget *parent = nullptr);

    double getStartX() const
    {
        return m_startx;
    }

    double getStartY() const
    {
        return m_starty;
    }

    double getTriangleHeight() const
    {
        return m_triangleHeight;
    }

    double getTriangleWidth() const
    {
        return m_triangleWidth;
    }

public slots:
    void setStartX(double startx)
    {
        m_startx = startx;
    }

    void setStartY(double starty)
    {
        m_starty = starty;
    }

    void setTriangleHeight(double triangleHeight)
    {
        m_triangleHeight = triangleHeight;
    }

    void setTriangleWidth(double triangleWidth)
    {
        m_triangleWidth = triangleWidth;
    }

signals:


protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // MYTRIANGLE_H
