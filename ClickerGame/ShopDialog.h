#ifndef SHOPDIALOG_H
#define SHOPDIALOG_H

#include "ShopMenu1.h"
#include "MainData.h"

#include <QDialog>


namespace Ui
{
    class ShopDialog;
}

class ShopDialog : public QDialog
{
    Q_OBJECT

  public:
    explicit ShopDialog(MainData *mainData, QWidget *parent = 0);
    ~ShopDialog();

  private slots:
    void on_closeButton_clicked();
    void onBuyed();

  private:
    Ui::ShopDialog *ui;

    ShopMenu1 *shopMenu1 = Q_NULLPTR;

    MainData *mainData = Q_NULLPTR;

    // QWidget interface
  protected:
    virtual void closeEvent(QCloseEvent *event) override;
};

#endif  // SHOPDIALOG_H
