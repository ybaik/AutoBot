#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QDialog(parent), 
	ui(new Ui::MainWindow)
{
	sys = new System("config.xml");
	ui->setupUi(this);
	
	if (sys->getGrabMethod() == api::Method::WindowHandle) 
	{
		ui->windowhandle->setChecked(true);
	}
	else 
	{
		ui->adb->setChecked(true);
	}
}

MainWindow::~MainWindow()
{
	delete ui;
	delete sys;
}

void MainWindow::start()
{
	sys->start();
}

void MainWindow::stop()
{
	sys->stop();
}
