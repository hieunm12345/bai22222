#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmessagebox.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_ThucHien_clicked()
{
    int nam = ui->lineEdit_Nam->text().toInt();
    int thang = ui->lineEdit_Thang->text().toInt();
    int ngay;

    switch(thang)
    {
    case 1:
        ngay = 31;
    case 3:
        ngay = 31;
    case 4:
        ngay = 30;
    case 5:
        ngay = 31;
    case 6:
        ngay = 30;
    case 7:
        ngay = 31;
    case 8:
        ngay = 31;
    case 9:
        ngay = 30;
    case 10:
        ngay = 31;
    case 11:
        ngay = 30;
    case 12:
        ngay = 31;
    }

    if(thang == 2)
    {
        if (nam % 400 == 0)
        {
            ngay = 29;
        }
        else if (nam % 4 == 0 && nam % 100 != 0)
        {
            ngay = 29;
        }
        else
        {
            ngay = 28;
        }
    }

    QString str_ngay = ("Nam " + QString::number(nam) + " thang "
            + QString::number(thang) + " co " + QString::number(ngay) + " ngay");
    ui->lineEdit_ngay->setText(str_ngay);
}

void MainWindow::on_pushButton_TiepTuc_clicked()
{
    ui->lineEdit_Nam->setText("");
    ui->lineEdit_Thang->setText("");
    ui->lineEdit_ngay->setText("");
}

void MainWindow::on_pushButton_Thoat_clicked()
{
    QMessageBox a;
            a.setWindowTitle("Close");
            a.setText("Ban co muon close khong?");
            a.setInformativeText("Nhan Yes de close");
            a.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            a.setDefaultButton(QMessageBox::No);
            a.setIcon(QMessageBox::Warning);
            int ketQua = a.exec();
            switch (ketQua) {
                case QMessageBox::Yes:
                close();
                break;
            case QMessageBox::No:
                break;
            }
}
