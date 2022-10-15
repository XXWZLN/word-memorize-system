#include "c2e.h"
#include "ui_c2e.h"

c2e::c2e(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::c2e)
{
    ui->setupUi(this);
}

c2e::~c2e()
{
    delete ui;
}
