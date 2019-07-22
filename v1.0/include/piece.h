#ifndef PIECE_H
#define PIECE_H

typedef struct piece{
	int lx, ly, rx, ry;
	int status;
}piece;

void initialPiece(int x, int y, piece *hrd); //initial the pieces' information

void initialPiece(int x, int y, piece *hrd){
	hrd[0].lx = x+2; hrd[0].ly = y+1; hrd[0].rx = x+2; hrd[0].ry = y+4; hrd[0].status = 0; //Zhang Fei
	hrd[1].lx = x+8; hrd[1].ly = y+1; hrd[1].rx = x+14; hrd[1].ry = y+4; hrd[1].status = 1;  //Cao Cao
	hrd[2].lx = x+20; hrd[2].ly = y+1; hrd[2].rx = x+20; hrd[2].ry = y+4; hrd[2].status = 0; //Ma Cao
	hrd[3].lx = x+2; hrd[3].ly = y+7; hrd[3].rx = x+2; hrd[3].ry = y+10; hrd[3].status = 0; //Huang Zhong
	hrd[4].lx = x+8; hrd[4].ly = y+7; hrd[4].rx = x+14; hrd[4].ry = y+7; hrd[4].status = 0; //Guan Yu
	hrd[5].lx = x+20; hrd[5].ly = y+7; hrd[5].rx = x+20; hrd[5].ry = y+10; hrd[5].status = 0; //Zhao Yun
	hrd[6].lx = x+2; hrd[6].ly = y+13; hrd[6].rx = x+2; hrd[6].ry = y+13; hrd[6].status = 0; //Soldier 1
	hrd[7].lx = x+8; hrd[7].ly = y+10; hrd[7].rx = x+8; hrd[7].ry = y+10; hrd[7].status = 0; //Soldier 2
	hrd[8].lx = x+14; hrd[8].ly = y+10; hrd[8].rx = x+14; hrd[8].ry = y+10; hrd[8].status = 0; //Soldier 3
	hrd[9].lx = x+20; hrd[9].ly = y+13; hrd[9].rx = x+20; hrd[9].ry = y+13; hrd[9].status = 0; //Soldier 4
	return;
}

#endif
