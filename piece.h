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
	a[0].name = "�ᵶ����"; a[0].status = true;
	a[1].name = "ָ������"; a[1].status = false;
	a[2].name = "��ӵ��Ӫ"; a[2].status = false;
	a[3].name = "��ͷ����"; a[3].status = false;
	a[4].name = "������·"; a[4].status = false;
	a[5].name = "�ͱ���·"; a[5].status = false;
	a[6].name = "���Ҳ���"; a[6].status = false;
	a[7].name = "�һ�԰��"; a[7].status = false;
	a[8].name = "һ·����"; a[8].status = false;
	a[9].name = "һ·˳��"; a[9].status = false;
	a[10].name = "�������"; a[10].status = false;
	a[11].name = "���ٲ�Ӫ"; a[11].status = false;
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
	
	int coordinatex[12][10] = {{0, 1, 3, 0, 1, 3, 0, 1, 2, 3},  //�ᵶ����
							   {0, 1, 3, 0, 1, 3, 0, 1, 2, 3},  //ָ������
							   {0, 1, 3, 1, 0, 2, 0, 2, 3, 3},  //��ӵ��Ӫ
							   {0, 1, 3, 0, 1, 3, 0, 1, 2, 3},  //��ͷ����
							   {0, 1, 3, 0, 1, 3, 0, 1, 2, 3},  //������·
							   {2, 0, 3, 0, 0, 1, 2, 2, 3, 3},  //�ͱ���·
							   {0, 1, 1, 2, 1, 3, 0, 0, 3, 3},  //���Ҳ���
							   {0, 1, 3, 1, 1, 2, 0, 0, 3, 3},  //�һ�԰��
							   {0, 1, 0, 1, 1, 2, 3, 3, 3, 3},  //һ·����
							   {0, 1, 0, 2, 1, 3, 1, 1, 3, 3},  //һ·˳�� 
							   {0, 1, 3, 0, 1, 3, 0, 1, 2, 3},  //�������
							   {0, 1, 3, 1, 1, 2, 0, 0, 3, 3}}; //���ٲ�Ӫ

	int coordinatey[12][10] = {{0, 0, 0, 2, 2, 2, 4, 3, 3, 4},  //�ᵶ����
							   {0, 0, 0, 3, 2, 3, 2, 3, 3, 2},  //ָ������
							   {1, 0, 1, 2, 4, 2, 3, 4, 3, 4},  //��ӵ��Ӫ
							   {0, 0, 0, 3, 3, 3, 2, 2, 2, 2},  //��ͷ����
							   {1, 0, 1, 3, 2, 3, 0, 3, 3, 0},  //������·
							   {0, 0, 0, 3, 2, 3, 2, 3, 2, 3},  //�ͱ���·
							   {2, 0, 2, 2, 4, 2, 0, 1, 0, 1},  //���Ҳ���
							   {1, 0, 1, 2, 4, 2, 0, 3, 0, 3},  //�һ�԰��
							   {0, 0, 2, 2, 4, 2, 0, 1, 2, 3},  //һ·����
							   {0, 0, 2, 3, 2, 2, 3, 4, 0, 1},  //һ·˳��
							   {0, 1, 0, 3, 3, 2, 2, 0, 0, 4},  //�������
							   {2, 0, 2, 3, 2, 3, 0, 1, 0, 1}}; //���ٲ�Ӫ
	
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
