#include <stdio.h>
#include <conio.h>
#include "system.h"

#ifdef _DEBUG
#pragma comment(lib, "opencv_core2413d.lib")
#pragma comment(lib, "opencv_imgproc2413d.lib")
#pragma comment(lib, "opencv_highgui2413d.lib")
#else
#pragma comment(lib, "opencv_core2413.lib")
#pragma comment(lib, "opencv_imgproc2413.lib")
#pragma comment(lib, "opencv_highgui2413.lib")
#endif

void main()
{
	System sys("config.xml");

	while (1)
	{
		char key = _getch();
		if (key == '1')
		{
			printf("1\n");
			sys.start();
		}
		else if (key == '2')
		{
			printf("2\n");
			sys.stop();
		}
		else if (key == '3')
		{
			printf("3\n");
			break;
		}
	}

	printf("test ended\n");
}