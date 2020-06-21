#ifndef ADDEDITSPDRNODE_H
#define ADDEDITSPDRNODE_H

#include <QDialog>

namespace Ui {
class AddEditRWTalerNode;
}


class AddEditRWTalerNode : public QDialog
{
    Q_OBJECT

public:
    explicit AddEditRWTalerNode(QWidget *parent = 0);
    ~AddEditRWTalerNode();

protected:

private Q_SLOTS:
    void on_okButton_clicked();
    void on_cancelButton_clicked();

signals:

private:
    Ui::AddEditRWTalerNode *ui;
};

#endif // ADDEDITSPDRNODE_H
