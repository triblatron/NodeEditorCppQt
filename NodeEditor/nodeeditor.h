#ifndef NODEEDITOR_H
#define NODEEDITOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class NodeEditor; }
QT_END_NAMESPACE

class NodeEditor : public QMainWindow
{
    Q_OBJECT

public:
    NodeEditor(QWidget *parent = nullptr);
    ~NodeEditor();

private:
    Ui::NodeEditor *ui;
};
#endif // NODEEDITOR_H
