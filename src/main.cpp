#include <QtWidgets/QApplication>

#include <UI/MainWindow.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	MainWindow* window = new MainWindow();
	window->setWindowTitle("AutoBot");
	window->show();

	return a.exec();
}