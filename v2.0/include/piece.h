#ifndef PIECE_H
#define PIECE_H

#include <string>
using std::string;

#define X 5
#define Y 5

typedef struct chapter{
	string name;
	bool status;
}chapter;

typedef struct piece{
	int lx, ly, rx, ry;
	int status;
}piece;

void initialChapter(chapter *a); //initial the chapters' information
void initialPiece(piece *hrd, int result); //initial the pieces' information

void initialChapter(chapter *a){
	a[0].name = "横刀立马"; a[0].status = true;
	a[1].name = "指挥若定"; a[1].status = false;
	a[2].name = "将拥曹营"; a[2].status = false;
	a[3].name = "齐头并进"; a[3].status = false;
	a[4].name = "兵分三路"; a[4].status = false;
	a[5].name = "屯兵东路"; a[5].status = false;
	a[6].name = "左右布兵"; a[6].status = false;
	a[7].name = "桃花园中"; a[7].status = false;
	a[8].name = "一路进军"; a[8].status = false;
	a[9].name = "一路顺风"; a[9].status = false;
	a[10].name = "四面楚歌"; a[10].status = false;
	a[11].name = "兵临曹营"; a[11].status = false;
}

//0: Zhang Fei
//1: Cao Cao
//2: Ma Cao
//3: Huang Zhong
//4: Guan Yu
//5: Zhao Yun
//6: Soldier 1
//7: Soldier 2
//8: Soldier 3
//9: Soldier 4
void initialPiece(piece *hrd, int result){
	int sizeofpiecex[10] = {1, 2, 1, 1, 2, 1, 1, 1, 1, 1};
	int sizeofpiecey[10] = {2, 2, 2, 2, 1, 2, 1, 1, 1, 1};
	
	int coordinatex[12][10] = {{0, 1, 3, 0, 1, 3, 0, 1, 2, 3},  //横刀立马
							   {0, 1, 3, 0, 1, 3, 0, 1, 2, 3},  //指挥若定
							   {0, 1, 3, 1, 0, 2, 0, 2, 3, 3},  //将拥曹营
							   {0, 1, 3, 0, 1, 3, 0, 1, 2, 3},  //齐头并进
							   {0, 1, 3, 0, 1, 3, 0, 1, 2, 3},  //兵分三路
							   {2, 0, 3, 0, 0, 1, 2, 2, 3, 3},  //屯兵东路
							   {0, 1, 1, 2, 1, 3, 0, 0, 3, 3},  //左右布兵
							   {0, 1, 3, 1, 1, 2, 0, 0, 3, 3},  //桃花园中
							   {0, 1, 0, 1, 1, 2, 3, 3, 3, 3},  //一路进军
							   {0, 1, 0, 2, 1, 3, 1, 1, 3, 3},  //一路顺风 
							   {0, 1, 3, 0, 1, 3, 0, 1, 2, 3},  //四面楚歌
							   {0, 1, 3, 1, 1, 2, 0, 0, 3, 3}}; //兵临曹营

	int coordinatey[12][10] = {{0, 0, 0, 2, 2, 2, 4, 3, 3, 4},  //横刀立马
							   {0, 0, 0, 3, 2, 3, 2, 3, 3, 2},  //指挥若定
							   {1, 0, 1, 2, 4, 2, 3, 4, 3, 4},  //将拥曹营
							   {0, 0, 0, 3, 3, 3, 2, 2, 2, 2},  //齐头并进
							   {1, 0, 1, 3, 2, 3, 0, 3, 3, 0},  //兵分三路
							   {0, 0, 0, 3, 2, 3, 2, 3, 2, 3},  //屯兵东路
							   {2, 0, 2, 2, 4, 2, 0, 1, 0, 1},  //左右布兵
							   {1, 0, 1, 2, 4, 2, 0, 3, 0, 3},  //桃花园中
							   {0, 0, 2, 2, 4, 2, 0, 1, 2, 3},  //一路进军
							   {0, 0, 2, 3, 2, 2, 3, 4, 0, 1},  //一路顺风
							   {0, 1, 0, 3, 3, 2, 2, 0, 0, 4},  //四面楚歌
							   {2, 0, 2, 3, 2, 3, 0, 1, 0, 1}}; //兵临曹营
	
	for(int i = 0; i < 10; i++){
		hrd[i].lx = X + 2 + 6 * coordinatex[result][i];
		hrd[i].ly = Y + 1 + 3 * coordinatey[result][i];
		hrd[i].rx = X + 2 + 6 * (coordinatex[result][i] + sizeofpiecex[i] - 1);
		hrd[i].ry = Y + 1 + 3 * (coordinatey[result][i] + sizeofpiecey[i] - 1);
		hrd[i].status = (i == 1)? 1 : 0;
	}
	return;
}

#endif
