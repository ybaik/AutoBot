#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QDialog>

#include <system.h>

#ifdef _DEBUG
#pragma comment(lib, "opencv_core2413d.lib")
#pragma comment(lib, "opencv_imgproc2413d.lib")
#pragma comment(lib, "opencv_highgui2413d.lib")
#else
#pragma comment(lib, "opencv_core2413.lib")
#pragma comment(lib, "opencv_imgproc2413.lib")
#pragma comment(lib, "opencv_highgui2413.lib")
#endif

namespace Ui {
class MainWindow;
}

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
	void start();
	void stop();

private:
    Ui::MainWindow *ui;
	System* sys;
};

#endif // MAINWINDOW_H
