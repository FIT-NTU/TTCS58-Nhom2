
#include <winbgim.h> 

int main(int argc, char *argv[])
{
	// now, you can run project
	initwindow(300, 300);			// init window graphics
	setbkcolor(0);					// set background
   	cleardevice();
	setcolor(14);					// set text color
	toado(640,480);
	while(!kbhit()) delay(1);		// pause screen	
	return 0;
}
