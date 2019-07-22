#include <iostream>
#include <windows.h>
#include "../include/color.h"
#include "../include/print.h"
#include "../include/control.h"

using namespace std;
int main(){
	piece hrd[10];
	restart:
	printMap(hrd);
	if(!click(hrd)) goto restart;
	return 0;
}
