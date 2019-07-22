#ifndef PRINT_H
#define PRINT_H 

#include <iostream>
#include <cstring>
#include <windows.h>
#include "../include/color.h"
#include "../include/piece.h"
using namespace std;

#define X 5
#define Y 5


void gotoxy(int x, int y) {
    COORD pos = {x,y};
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// Getting the standard output device handle
    SetConsoleCursorPosition(hOut, pos); //Windows & Position
}

//print a string for n times
void printTimes(string str, int n){
	for(int i = 0; i < n; i++){
		cout << str;
	}
	return;
}

//change the print color
void changeColor(int color){
	switch(color){
		case 0: cout << white; break;
		case 1: cout << blue; break;
		case 2: cout << red; break;
		default: break;
	}
	return;
}

void printMap(piece *hrd); //print the initial map

//color: 0 is unselected, 1 is selecting, 2 is selected
void printpiece(int x, int y, int index, int color); //print piece hrd[index]

void printZF(int x, int y); //print Zhang Fei
void printCC(int x, int y); //print Cao Cao
void printMC(int x, int y); //print Ma Cao
void printHZ(int x, int y); //print Huang Zhong
void printGY(int x, int y); //print Guan Yu
void printZY(int x, int y); //print Zhao Yun
void printXB(int x, int y); //print soldier

void erasepiece(int x, int y, int index); //erase piece hrd[index]

void erase12(int x, int y); //erase 1*2 peice
void erase22(int x, int y); //erase 2*2 peice
void erase21(int x, int y); //erase 2*1 peice
void erase11(int x, int y); //erase 1*1 peice

void printMap(piece *hrd){
	system("cls");
	system("title 华容道");
	system("mode con cols=60 lines=26");
	changeColor(0);
	gotoxy(X+11, Y-2);
	cout << "华容道";
	gotoxy(X+36, Y+4);
	cout << "W        ↑";
	gotoxy(X+34, Y+5);
	cout << "A S D    ←↓→";
	gotoxy(X+34, Y+7);
	cout << "space  锁定/解锁"; 
	gotoxy(X+36, Y+9);
	cout << "R    重新开始";
	gotoxy(X+36, Y+11);
	changeColor(2);
	cout << "■   锁定状态";
	gotoxy(X+36, Y+13);
	changeColor(1);
	cout << "■   选择状态";
	gotoxy(X+45, Y+19);
	changeColor(0);
	cout << "by Ender";
	gotoxy(X, Y);
	printTimes("■", 14);
	for(int i = 1; i <= 15; i++){
		gotoxy(X, Y+i);
		cout << "■";
		printTimes("  ", 12);
		cout << "■";
	}
	gotoxy(X, Y+16);
	printTimes("■", 4);
	printTimes("  ", 6);
	printTimes("■", 4);

	initialPiece(X, Y, hrd);
	
	for(int i = 0; i < 10; i++){
		printpiece(hrd[i].lx, hrd[i].ly, i, hrd[i].status);
	}
	
	return;
}

void printpiece(int x, int y, int index, int color){
	changeColor(color);
	switch(index){
		case 0: printZF(x, y); break;
		case 1: printCC(x, y); break;
		case 2: printMC(x, y); break;
		case 3: printHZ(x, y); break;
		case 4: printGY(x, y); break;
		case 5: printZY(x, y); break;
		case 6: case 7: case 8: case 9: printXB(x, y); break;
		default: break;
	}
	changeColor(0);
	return;
}

void printZF(int x, int y){
	gotoxy(x, y);
	cout << "┌───┐";
	gotoxy(x, y+1);
	cout << "│   │";
	gotoxy(x, y+2);
	cout << "│ 张│";
	gotoxy(x, y+3);
	cout << "│ 飞│";
	gotoxy(x, y+4);
	cout << "│   │";
	gotoxy(x, y+5);
	cout << "└───┘";
	return;
}

void printCC(int x, int y){
	gotoxy(x, y);
	cout << "┌─────────┐";
	gotoxy(x, y+1);
	cout << "│         │";
	gotoxy(x, y+2);
	cout << "│   曹操  │";
	gotoxy(x, y+3);
	cout << "│         │";
	gotoxy(x, y+4);
	cout << "│         │";
	gotoxy(x, y+5);
	cout << "└─────────┘";
	return;
}

void printMC(int x, int y){
	gotoxy(x, y);
	cout << "┌───┐";
	gotoxy(x, y+1);
	cout << "│   │";
	gotoxy(x, y+2);
	cout << "│ 马│";
	gotoxy(x, y+3);
	cout << "│ 超│";
	gotoxy(x, y+4);
	cout << "│   │";
	gotoxy(x, y+5);
	cout << "└───┘";
	return;
}

void printHZ(int x, int y){
	gotoxy(x, y);
	cout << "┌───┐";
	gotoxy(x, y+1);
	cout << "│   │";
	gotoxy(x, y+2);
	cout << "│ 黄│";
	gotoxy(x, y+3);
	cout << "│ 忠│";
	gotoxy(x, y+4);
	cout << "│   │";
	gotoxy(x, y+5);
	cout << "└───┘";
	return;
}

void printGY(int x, int y){
	gotoxy(x, y);
	cout << "┌─────────┐";
	gotoxy(x, y+1);
	cout << "│   关羽  │";
	gotoxy(x, y+2);
	cout << "└─────────┘";
	return;
}

void printZY(int x, int y){
	gotoxy(x, y);
	cout << "┌───┐";
	gotoxy(x, y+1);
	cout << "│   │";
	gotoxy(x, y+2);
	cout << "│ 赵│";
	gotoxy(x, y+3);
	cout << "│ 云│";
	gotoxy(x, y+4);
	cout << "│   │";
	gotoxy(x, y+5);
	cout << "└───┘";
	return;
}

void printXB(int x, int y){
	gotoxy(x, y);
	cout << "┌───┐";
	gotoxy(x, y+1);
	cout << "│ 兵│";
	gotoxy(x, y+2);
	cout << "└───┘";
	return;
}

void erasepiece(int x, int y, int index){
	switch(index){
		case 0: case 2: case 3: case 5: erase12(x, y); break;
		case 1: erase22(x, y); break;
		case 4: erase21(x, y); break;
		case 6: case 7: case 8: case 9: erase11(x, y); break;
		default: break;
	}
}

void erase12(int x, int y){
	for(int i = 0; i < 6; i++){
		gotoxy(x, y+i);
		printTimes(" ", 6);
	}
	return;
}
void erase22(int x, int y){
	for(int i = 0; i < 6; i++){
		gotoxy(x, y+i);
		printTimes(" ", 12);
	}
	return;
}
void erase21(int x, int y){
	for(int i = 0; i < 3; i++){
		gotoxy(x, y+i);
		printTimes(" ", 12);
	}
	return;
}
void erase11(int x, int y){
	for(int i = 0; i < 3; i++){
		gotoxy(x, y+i);
		printTimes(" ", 6);
	}
	return;
}

#endif
