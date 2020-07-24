#include <QApplication>
#include <QWidget>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QPushButton>
#include<QDebug>
#include "qwidgetdemo.h"

void layoutDemo0(void);
void layoutDemo1(void);
void layoutDemo2(void);




void layoutDemo2(void)
{
    QWidget *demoWidgetMain = new QWidget();
    demoWidgetMain->resize(150,400);

    QWidget *demoWidget1 = new QWidgetDemo();
    QWidget *demoWidget2 = new QWidgetDemo();
    QWidget *demoWidget3 = new QWidgetDemo();

    //创建垂直箱式布局
    QVBoxLayout *layout = new QVBoxLayout();

    layout->addWidget(demoWidget1);
    layout->addWidget(demoWidget2);
    layout->addWidget(demoWidget3);

    demoWidgetMain->setLayout(layout);
    demoWidgetMain->show();
}

void layoutDemo1(void)
{

    QWidget *winMain = new QWidget();
    //设计界面尺寸
    winMain->resize(800,480);



    QPushButton *btnReplay = new QPushButton("Replay");
    QPushButton *btnLogin = new QPushButton("Login");
    QPushButton *btnConfig = new QPushButton("Config");

#if 0
    //按钮参数打印
    qDebug()<<btnReplay->sizeHint();
    qDebug()<<btnReplay->size();
    qDebug()<<btnReplay->minimumSizeHint();
    qDebug()<<btnReplay->minimumSize();

    btnReplay->setMinimumSize(50,50);
    btnReplay->setMaximumSize(100,100);
    btnLogin->setMinimumSize(50,50);
    btnLogin->setMaximumSize(100,100);
    btnConfig->setMinimumSize(50,50);
    btnConfig->setMaximumSize(100,100);
#endif

    //配置策略参数
    //btnReplay->setProperty(QSizePolicy::Policy::Preferred, QSizePolicy::Maximum, QSizePolicy::Minimum);
    btnReplay->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    btnLogin->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    btnConfig->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);




    //创建箱式layout
    QHBoxLayout *layoutMain = new QHBoxLayout();


    //布局器添加按钮
    layoutMain->addWidget(btnReplay);
    layoutMain->addWidget(btnLogin);
    layoutMain->addWidget(btnConfig);

    //拉伸因子
    layoutMain->setStretchFactor(btnReplay,2);
    //layoutMain->setStretch(1,2);
    layoutMain->setStretchFactor(btnLogin,2);
    layoutMain->setStretchFactor(btnConfig,2);
    layoutMain->insertStretch(3,1);
    layoutMain->insertStretch(2,1);
    layoutMain->insertStretch(1,1);
    layoutMain->insertStretch(0,3);

    //创建垂直箱式布局
    QVBoxLayout *layout = new QVBoxLayout();


    //嵌套，配置拉伸因子并插入
    layout->addLayout(layoutMain);
    layout->setStretchFactor(layoutMain,1);
    layout->insertStretch(1,3);
    layout->insertStretch(0,1);


    winMain->setLayout(layout);




    winMain->show();
}

void layoutDemo0(void)
{

    //创建界面
    QWidget *winMain = new QWidget();

    //设计界面尺寸
    winMain->resize(800,480);

    //创建箱式layout
    QHBoxLayout *hlayoutMain = new QHBoxLayout();

    //布局器添加按钮
    hlayoutMain->addWidget(new QPushButton("Replay"));
    hlayoutMain->addWidget(new QPushButton("Login"));
    hlayoutMain->addWidget(new QPushButton("Config"));

    QVBoxLayout *vlayoutMain = new QVBoxLayout();
     vlayoutMain->addWidget(new QPushButton("Replay"));
      vlayoutMain->addWidget(new QPushButton("Login"));
       vlayoutMain->addWidget(new QPushButton("Config"));

    QVBoxLayout *layoutMain = new QVBoxLayout();
    layoutMain->addLayout(hlayoutMain);
    layoutMain->addLayout(vlayoutMain);


    //把布局器应用到窗口

    winMain->setLayout(layoutMain);




    winMain->show();
}
