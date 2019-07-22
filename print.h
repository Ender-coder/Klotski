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

void printMap(piece *hrd, int result, string name); //print the initial map

void printSelectionScreen(chapter *a); //print the selection screen
void printchapter(chapter *a, int index); //print chapter a[index]

void printWall(); //print the wall of the game

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

void printMap(piece *hrd, int result, string name){
	system("cls");
	printWall();
	
	gotoxy(X+21, Y-2);
	cout << name;

	initialPiece(hrd, result);
	for(int i = 0; i < 10; i++){
		printpiece(hrd[i].lx, hrd[i].ly, i, hrd[i].status);
	}
	
	return;
}

void printSelectionScreen(chapter *a){
	system("cls");
	changeColor(0);
	gotoxy(X+22, Y-4);
	cout << "华容道";
	
	initialChapter(a);
	for(int i = 0; i < 12; i++){
		printchapter(a, i);
	}
	
	gotoxy(X+20, Y+17);
	cout << "W        ↑";
	gotoxy(X+18, Y+18);
	cout << "A S D    ←↓→";
	gotoxy(X+18, Y+20);
	cout << "space   选择关卡"; 
	gotoxy(X+45, Y+21);
	cout << "by Ender";
	
	return;
}

void printchapter(chapter *a, int index){
	if(a[index].status == true) changeColor(2);
	else changeColor(0);
	gotoxy(X+11+index%2*16, Y+index/2*3-2);
	cout << "┌─────────┐";
	gotoxy(X+11+index%2*16, Y+index/2*3-1);
	cout << "│ " << a[index].name << "│";
	gotoxy(X+11+index%2*16, Y+index/2*3);
	cout << "└─────────┘";
	changeColor(0);
	return;
}

void printWall(){
	changeColor(0);
	gotoxy(X+22, Y-4);
	cout << "华容道";
	gotoxy(X+36, Y+3);
	cout << "W        ↑";
	gotoxy(X+34, Y+4);
	cout << "A S D    ←↓→";
	gotoxy(X+34, Y+6);
	cout << "space  锁定/解锁"; 
	gotoxy(X+36, Y+8);
	cout << "R    重新开始";
	gotoxy(X+36, Y+10);
	cout << "P   回到主界面"; 
	gotoxy(X+36, Y+12);
	changeColor(2);
	cout << "■   锁定状态";
	gotoxy(X+36, Y+14);
	changeColor(1);
	cout << "■   选择状态";
	gotoxy(X+45, Y+21);
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
