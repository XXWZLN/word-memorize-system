#include "memory.h"
#include "ui_memory.h"

memory::memory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::memory)
{
    ui->setupUi(this);
}

memory::~memory()
{
    delete ui;
}

void memory::memorize_tool_init(QString account)
{
    sign_in_account = account;
    ui->me_num->setSuffix("个");
    ui->me_num->setSingleStep(10);
    ui->me_num->setValue(30);
    ui->me_num->setMinimum(10);
}

void memory::on_back_clicked()
{
    this->close();
    wordslibrary *Wordslibrary = new wordslibrary();
    Wordslibrary->sqlInit(sign_in_account);
    Wordslibrary->show();
}



void memory::on_pushButton_5_clicked()
{
    this->close();
    qDebug() << ui->me_num->value();
    e2c *E2C = new e2c();
    E2C->e2cInit(sign_in_account, ui->me_num->value());
    E2C->show();
}
