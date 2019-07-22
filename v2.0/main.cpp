#include <iostream>
#include <windows.h>
#include "../include/color.h"
#include "../include/print.h"
#include "../include/control.h"

using namespace std;
int main(){
	
	system("cls");
	system("title »ªÈÝµÀ");
	system("mode con cols=60 lines=28");
	
	chapter a[12];
	piece hrd[10];
	
	reselect:
	printSelectionScreen(a);
	int result = choosecontrol(a);
	
	restart:
	printMap(hrd, result, a[result].name);
	
	if(click(hrd)) goto reselect;
	else goto restart;
	return 0;
}
