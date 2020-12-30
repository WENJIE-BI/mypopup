#include "mypopup.h"
#include "mytriangle.h"
#include "config.h"

#include <QPushButton>
#include <QPainter>
#include <QtMath>
#include <QLabel>
#include <QHBoxLayout>
#include <QGraphicsDropShadowEffect>
#include <QDebug>

#define BORDER_RADIUS 10       //窗口边角弧度

Mypopup::Mypopup(QWidget *parent) : QWidget(parent),
    m_startx(0)
{
}

Mypopup::Mypopup(double startx, double starty, double width,
                 double height, double triwidth, double triheight, QWidget *parent):
    m_startx(startx), m_starty(starty), m_width(width), m_height(height),
    m_triwidth(triwidth), m_triheight(triheight)
{
    setGeometry(m_startx, m_starty, m_width, m_triheight + m_height);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    //设置阴影边框
    auto shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setOffset(0,0);
    shadowEffect->setColor(Qt::gray);
//    shadowEffect->setColor(SHADOW_COLOR);
    shadowEffect->setBlurRadius(BORDER_RADIUS);
    this->setGraphicsEffect(shadowEffect);
    this->setMouseTracking(true);

    QVBoxLayout *verticalLayout = new QVBoxLayout(this);
#if 0
    MyTriangle *mytri = new MyTriangle(this);
    setGeometry(m_startx, m_starty, m_width, m_triheight + m_height);
    mytri->setStartX(m_width/2 - m_triwidth/2);
    mytri->setStartY(m_starty);
    mytri->setTriangleWidth(m_triwidth);
    mytri->setTriangleHeight(m_triheight);
    verticalLayout->addWidget(mytri);
#elif 0
    QWidget *widget = new QWidget(this);
    widget->setGeometry(0, 0, m_width, m_triheight);
    widget->setStyleSheet("background-color:green;");
    MyTriangle *mytri = new MyTriangle(widget);
//    mytri->setGeometry(0, 0, m_triwidth, m_triheight);
    mytri->setStyleSheet("background-color:blue;");
//    mytri->setStartX(m_width/2 - m_triwidth/2);
    mytri->setStartX(0);
    mytri->setStartY(0);
    mytri->setTriangleWidth(m_triwidth);
    mytri->setTriangleHeight(m_triheight);
    verticalLayout->addWidget(mytri);
#else
    MyTriangle *mytri = new MyTriangle(this);
//    mytri->setStyleSheet("background-color:blue;");
    mytri->setStartX(m_width/2 - SHADOW_WIDTH - m_triwidth);
    mytri->setStartY(0);
    mytri->setTriangleWidth(m_triwidth);
    mytri->setTriangleHeight(m_triheight);
    verticalLayout->addWidget(mytri);
#endif
    QLabel *storelocation_label = new QLabel(tr("save location"), this);
//    storelocation_label->setStyleSheet("background-color:gray;");
    verticalLayout->addWidget(storelocation_label);

    QPushButton *storelocation_button = new QPushButton(this);
//    QIcon btn_icon;
//    btn_icon.addFile("images/add.png");
//    storelocation_button->setIcon(btn_icon);
//    storelocation_button->setIconSize(QSize(storelocation_button->width(), storelocation_button->height()));
    verticalLayout->addWidget(storelocation_button);

    QLabel *video_codec = new QLabel(tr("video codec"), this);
//    video_codec->setStyleSheet("background-color:blue;");
    verticalLayout->addWidget(video_codec);

    QPushButton *video_codec_button = new QPushButton(this);
    verticalLayout->addWidget(video_codec_button);

    QLabel *audio_byterate = new QLabel(tr("audio byterate"), this);
//    audio_byterate->setStyleSheet("background-color:blue;");
    verticalLayout->addWidget(audio_byterate);

    QPushButton *audio_byterate_button = new QPushButton(this);
    verticalLayout->addWidget(audio_byterate_button);

    QLabel *video_frate = new QLabel(tr("video frate"), this);
//    video_frate->setStyleSheet("background-color:blue;");
    verticalLayout->addWidget(video_frate);

    QPushButton *video_frate_button = new QPushButton(this);
    verticalLayout->addWidget(video_frate_button);

    QLabel *video_res = new QLabel(tr("video res"), this);
//    video_res->setStyleSheet("background-color:blue;");
    verticalLayout->addWidget(video_res);

    QPushButton *video_res_button = new QPushButton(this);
    verticalLayout->addWidget(video_res_button);

    setContentsMargins(SHADOW_WIDTH,SHADOW_WIDTH,SHADOW_WIDTH,SHADOW_WIDTH);
}

void Mypopup::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.setPen(Qt::NoPen);
    QPainterPath drawPath;
    drawPath.addRoundRect(QRect(SHADOW_WIDTH, SHADOW_WIDTH*3 + m_triheight,
                                width() - SHADOW_WIDTH *2, height() -SHADOW_WIDTH *2),
                         BORDER_RADIUS,BORDER_RADIUS);
    painter.setBrush(SHADOW_COLOR);
    painter.drawPath(drawPath);

}
