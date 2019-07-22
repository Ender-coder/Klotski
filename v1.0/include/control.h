#ifndef CONTROL_H
#define CONTROL_H

#include <conio.h>
#include "../include/print.h"
#include "../include/piece.h"

#define X 5
#define Y 5

bool click(piece *hrd); //contain with main.cpp
int clickcontrol(piece *hrd);
bool movejudge(piece index, piece i); //Judging whether or not to move

void space(piece *hrd); //Switch lock and unlock States
void up(piece *hrd); //Press 'up'
bool down(piece *hrd); //Press 'down'
void left(piece *hrd); //Press 'left'
void right(piece *hrd); //Press 'right'

bool click(piece *hrd){
	int result = 1;
	while(result != 10086){
		result = clickcontrol(hrd);
		if(result == 0) return false;
	}
	erasepiece(X+8, Y+10, 1);
	printpiece(X+8, Y+13, 1, 2);
	gotoxy(X+10, X+20);
	cout << "You win!" << endl;
	system("pause");
	return true;
}

int clickcontrol(piece *hrd){
	char ch;
	ch = getch();
	switch(ch){
		case 'w': up(hrd); break; //up
		case 's': if(down(hrd)) return 10086; break; //down
		case 'a': left(hrd); break; //left
		case 'd': right(hrd); break; //right
		case ' ': space(hrd); break; //switch
		case 'r': return 0; //restart
		default: break;
	}
	return 1;
}

void space(piece *hrd){
	int index;
	for(int i = 0; i < 10; i++){
		if(hrd[i].status == 1){
			index = i;
			hrd[i].status = 2;
			break;
		}
		else if(hrd[i].status == 2){
			index = i;
			hrd[i].status = 1;
			break;
		}
	}
	printpiece(hrd[index].lx, hrd[index].ly, index, hrd[index].status);
	return;
}

bool movejudge(piece index, piece i){
	if(index.rx < i.lx || index.lx > i.rx || index.ry < i.ly || index.ly > i.ry) return true;
	else return false;
}

void up(piece *hrd){
	int index;
	bool locked;
	for(int i = 0; i < 10; i++){
		if(hrd[i].status == 1 || hrd[i].status == 2){
			index = i;
			locked = (hrd[i].status == 2)? true : false;
			break;
		}
	}
	if(hrd[index].ly == Y + 1) return;
	
	if(locked){
		bool can = true;
		piece judge = hrd[index];
		judge.ly -= 3;
		for(int i = 0; i < 10; i++){
			if(index != i){
				if(!movejudge(judge, hrd[i])) can = false;
			}
		}
	
		if(can){
			erasepiece(hrd[index].lx, hrd[index].ly, index);
			hrd[index].ly -= 3;
			hrd[index].ry -= 3;
			printpiece(hrd[index].lx, hrd[index].ly, index, hrd[index].status);
		}
	}
	else{
		bool content[10];
		int num = 0;
		for(int i = 0; i < 10; i++){
			if(hrd[i].ry < hrd[index].ly)
				if((hrd[i].lx >= hrd[index].lx && hrd[i].lx <= hrd[index].rx) || (hrd[i].rx >= hrd[index].lx && hrd[i].rx <= hrd[index].rx)){
					content[i] = true;
					num++;
				}	
				else content[i] = false;
			else content[i] = false;
		}
		if(num == 0) return;
		else if(num == 1){
			for(int i = 0; i < 10; i++){
				if(content[i] == true){
					hrd[index].status = 0;
					printpiece(hrd[index].lx, hrd[index].ly, index, hrd[index].status);
					hrd[i].status = 1;
					printpiece(hrd[i].lx, hrd[i].ly, i, hrd[i].status);
					return;
				}
			}
		}
		else{
			int max = Y;
			for(int i = 0; i < 10; i++){
				if(content[i] == true)
					if(hrd[i].ry > max) max = hrd[i].ry; 
			}
			for(int i = 0; i < 10; i++){
				if(content[i] == true)
					if(hrd[i].ry == max){
						hrd[index].status = 0;
						printpiece(hrd[index].lx, hrd[index].ly, index, hrd[index].status);
						hrd[i].status = 1;
						printpiece(hrd[i].lx, hrd[i].ly, i, hrd[i].status);
						return;
					}
			}
		}
	}
	return;
}

bool down(piece *hrd){	
	int index;
	bool locked;
	for(int i = 0; i < 10; i++){
		if(hrd[i].status == 1 || hrd[i].status == 2){
			index = i;
			locked = (hrd[i].status == 2)? true : false;
			break;
		}
	}
	
	if(locked){
		if(hrd[1].lx == X + 8 && hrd[1].ly == Y + 10) return true; //Cao Cao escaped
		if(hrd[index].ry == Y + 13) return false;
		bool can = true;
		piece judge = hrd[index];
		judge.ry += 3;
		for(int i = 0; i < 10; i++){
			if(index != i){
				if(!movejudge(judge, hrd[i])) can = false;
			}
		}
	
		if(can){
			erasepiece(hrd[index].lx, hrd[index].ly, index);
			hrd[index].ly += 3;
			hrd[index].ry += 3;
			printpiece(hrd[index].lx, hrd[index].ly, index, hrd[index].status);
		}
	}
	else{
		if(hrd[index].ry == Y + 13) return false;
		bool content[10];
		int num = 0;
		for(int i = 0; i < 10; i++){
			if(hrd[i].ly > hrd[index].ry)
				if((hrd[i].lx >= hrd[index].lx && hrd[i].lx <= hrd[index].rx) || (hrd[i].rx >= hrd[index].lx && hrd[i].rx <= hrd[index].rx)){
					content[i] = true;
					num++;
				}	
				else content[i] = false;
			else content[i] = false;
		}
		if(num == 0) return false;
		else if(num == 1){
			for(int i = 0; i < 10; i++){
				if(content[i] == true){
					hrd[index].status = 0;
					printpiece(hrd[index].lx, hrd[index].ly, index, hrd[index].status);
					hrd[i].status = 1;
					printpiece(hrd[i].lx, hrd[i].ly, i, hrd[i].status);
					return false;
				}
			}
		}
		else{
			int min = Y + 15;
			for(int i = 0; i < 10; i++){
				if(content[i] == true)
					if(hrd[i].ly < min) min = hrd[i].ly; 
			}
			for(int i = 0; i < 10; i++){
				if(content[i] == true)
					if(hrd[i].ly == min){
						hrd[index].status = 0;
						printpiece(hrd[index].lx, hrd[index].ly, index, hrd[index].status);
						hrd[i].status = 1;
						printpiece(hrd[i].lx, hrd[i].ly, i, hrd[i].status);
						return false;
					}
			}
		}
	}
	return false;
}

void left(piece *hrd){
	int index;
	bool locked;
	for(int i = 0; i < 10; i++){
		if(hrd[i].status == 1 || hrd[i].status == 2){
			index = i;
			locked = (hrd[i].status == 2)? true : false;
			break;
		}
	}
	if(hrd[index].lx== X + 2) return;
	
	if(locked){
		bool can = true;
		piece judge = hrd[index];
		judge.lx -= 6;
		for(int i = 0; i < 10; i++){
			if(index != i){
				if(!movejudge(judge, hrd[i])) can = false;
			}
		}
	
		if(can){
			erasepiece(hrd[index].lx, hrd[index].ly, index);
			hrd[index].lx -= 6;
			hrd[index].rx -= 6;
			printpiece(hrd[index].lx, hrd[index].ly, index, hrd[index].status);
		}
	}
	else{
		bool content[10];
		int num = 0;
		for(int i = 0; i < 10; i++){
			if(hrd[i].rx < hrd[index].lx)
				if((hrd[i].ly >= hrd[index].ly && hrd[i].ly <= hrd[index].ry) || (hrd[i].ry >= hrd[index].ly && hrd[i].ry <= hrd[index].ry)){
					content[i] = true;
					num++;
				}	
				else content[i] = false;
			else content[i] = false;
		}
		if(num == 0) return;
		else if(num == 1){
			for(int i = 0; i < 10; i++){
				if(content[i] == true){
					hrd[index].status = 0;
					printpiece(hrd[index].lx, hrd[index].ly, index, hrd[index].status);
					hrd[i].status = 1;
					printpiece(hrd[i].lx, hrd[i].ly, i, hrd[i].status);
					return;
				}
			}
		}
		else{
			int max = X;
			for(int i = 0; i < 10; i++){
				if(content[i] == true)
					if(hrd[i].rx > max) max = hrd[i].rx; 
			}
			for(int i = 0; i < 10; i++){
				if(content[i] == true)
					if(hrd[i].rx == max){
						hrd[index].status = 0;
						printpiece(hrd[index].lx, hrd[index].ly, index, hrd[index].status);
						hrd[i].status = 1;
						printpiece(hrd[i].lx, hrd[i].ly, i, hrd[i].status);
						return;
					}
			}
		}
	}
	return;
}

void right(piece *hrd){
	int index;
	bool locked;
	for(int i = 0; i < 10; i++){
		if(hrd[i].status == 1 || hrd[i].status == 2){
			index = i;
			locked = (hrd[i].status == 2)? true : false;
			break;
		}
	}
	if(hrd[index].rx == X + 20) return;
	
	if(locked){
		bool can = true;
		piece judge = hrd[index];
		judge.rx += 6;
		for(int i = 0; i < 10; i++){
			if(index != i){
				if(!movejudge(judge, hrd[i])) can = false;
			}
		}
	
		if(can){
			erasepiece(hrd[index].lx, hrd[index].ly, index);
			hrd[index].lx += 6;
			hrd[index].rx += 6;
			printpiece(hrd[index].lx, hrd[index].ly, index, hrd[index].status);
		}
	}
	else{
		bool content[10];
		int num = 0;
		for(int i = 0; i < 10; i++){
			if(hrd[i].lx > hrd[index].rx)
				if((hrd[i].ly >= hrd[index].ly && hrd[i].ly <= hrd[index].ry) || (hrd[i].ry >= hrd[index].ly && hrd[i].ry <= hrd[index].ry)){
					content[i] = true;
					num++;
				}	
				else content[i] = false;
			else content[i] = false;
		}
		if(num == 0) return;
		else if(num == 1){
			for(int i = 0; i < 10; i++){
				if(content[i] == true){
					hrd[index].status = 0;
					printpiece(hrd[index].lx, hrd[index].ly, index, hrd[index].status);
					hrd[i].status = 1;
					printpiece(hrd[i].lx, hrd[i].ly, i, hrd[i].status);
					return;
				}
			}
		}
		else{
			int min = X + 25;
			for(int i = 0; i < 10; i++){
				if(content[i] == true)
					if(hrd[i].lx < min) min = hrd[i].lx;
			}
			for(int i = 0; i < 10; i++){
				if(content[i] == true)
					if(hrd[i].lx == min){
						hrd[index].status = 0;
						printpiece(hrd[index].lx, hrd[index].ly, index, hrd[index].status);
						hrd[i].status = 1;
						printpiece(hrd[i].lx, hrd[i].ly, i, hrd[i].status);
						return;
					}
			}
		}
	}
	return;
}

#endif
