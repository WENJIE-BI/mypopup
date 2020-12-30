#ifndef MYRECTANGLE_H
#define MYRECTANGLE_H

#include <QWidget>

//class MyTriangle;


class Mypopup : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(double startx READ getStartX WRITE setStartX)		//rectangle
    Q_PROPERTY(double starty READ getStartY WRITE setStartY)		// triangle
    Q_PROPERTY(double width READ getWidth WRITE setWidth)			//rectangle
    Q_PROPERTY(double height READ getHeight WRITE setHeight)		//rectangle
    Q_PROPERTY(double triwidth READ getTriwidth WRITE setTriwidth)
    Q_PROPERTY(double triheight READ getTriheight WRITE setTriheight)
    double m_startx;

    double m_starty;

    double m_width;

    double m_height;

    double m_triwidth;

    double m_triheight;

public:
    explicit Mypopup(QWidget *parent = nullptr);
    explicit Mypopup(double startx, double starty, double width, double height,
                     double triwidth, double triheight, QWidget *parent = nullptr);

    double getStartX() const
    {
        return m_startx;
    }

    double getStartY() const
    {
        return m_starty;
    }

    double getWidth() const
    {
        return m_width;
    }

    double getHeight() const
    {
        return m_height;
    }

    double getTriwidth() const
    {
        return m_triwidth;
    }

    double getTriheight() const
    {
        return m_triheight;
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

    void setWidth(double width)
    {
        m_width = width;
    }

    void setHeight(double height)
    {
        m_height = height;
    }

    void setTriwidth(double triwidth)
    {
        m_triwidth = triwidth;
    }

    void setTriheight(double triheight)
    {
        m_triheight = triheight;
    }

signals:

protected:
    void paintEvent(QPaintEvent *event) override;

protected:
//    MyTriangle *mytri;
};

#endif // MYRECTANGLE_H
