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
}

void memory::on_back_clicked()
{
    this->close();
    wordslibrary *Wordslibrary = new wordslibrary();
    Wordslibrary->sqlInit(sign_in_account);
    Wordslibrary->show();
}
