#include "nodeeditor.h"
#include "./ui_nodeeditor.h"

NodeEditor::NodeEditor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NodeEditor)
{
    ui->setupUi(this);
}

NodeEditor::~NodeEditor()
{
    delete ui;
}

