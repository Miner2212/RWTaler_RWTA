#ifndef SPDRNODECONFIGDIALOG_H
#define SPDRNODECONFIGDIALOG_H

#include <QDialog>

namespace Ui {
    class RWTalerNodeConfigDialog;
}

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

/** Dialog showing transaction details. */
class RWTalerNodeConfigDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RWTalerNodeConfigDialog(QWidget *parent = 0, QString nodeAddress = "123.456.789.123:28666", QString privkey="MASTERNODEPRIVKEY");
    ~RWTalerNodeConfigDialog();

private:
    Ui::RWTalerNodeConfigDialog *ui;
};

#endif // SPDRNODECONFIGDIALOG_H
