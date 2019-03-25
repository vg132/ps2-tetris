#ifndef __8D963B339D73936532618C__FIELD__HPP__
#define __8D963B339D73936532618C__FIELD__HPP__

#include <stdlib.h>
#include <stdio.h>
#include <timer.h>
#include <Ito.h>

class CField
{
private:
	static const u8 WIDTH=10;
	static const u8 HEIGHT=24;
	static const u8 VISIBLE_HEIGHT=20;
	u16 iBlock[4][4];
	u16 iNextBlock[4][4];

  u16 iField[WIDTH][HEIGHT];

	int iAngle, iBlockType, iX, iY, iNext, iStatus, iFlashCounter, iResets, iNextColor, iColor, iStartHeight;
	
	u16 Randnum(u16 limit);
	void ClearBlock(u16 block[][4]);
	void RemoveFullRow(u8 row);
	void SetRemoveFullRow(u8 row);
	inline u8 LOWORD(u16 i){return(i & 0xFF);};
	inline u8 HIWORD(u16 i){return(i >> 8);};
	inline u16 MAKELONG(u8 low, u8 hi){return((low & 0xFF) | ((hi & 0xFF) << 8));};

public:
	static const u8 BLOCK_COLOR_DARKPINK=1;
	static const u8 BLOCK_COLOR_BROWN=2;
	static const u8 BLOCK_COLOR_PINK=3;
	static const u8 BLOCK_COLOR_YELLOW=4;
	static const u8 BLOCK_COLOR_RED=5;
	static const u8 BLOCK_COLOR_GREEN=6;
	static const u8 BLOCK_COLOR_BLUE=7;
	static const u8 BLOCK_COLOR_GRAY=8;
	static const u8 BLOCK_COLOR_NONE=9;

	static const u8 BLOCK_SHAPE_L=20;
	static const u8 BLOCK_SHAPE_RL=21;
	static const u8 BLOCK_SHAPE_Z=22;
	static const u8 BLOCK_SHAPE_RZ=23;
	static const u8 BLOCK_SHAPE_I=24;
	static const u8 BLOCK_SHAPE_T=25;
	static const u8 BLOCK_SHAPE_O=26;

	static const u8 MOVE_DOWN=60;
	static const u8 MOVE_UP=61;
	static const u8 MOVE_LEFT=62;
	static const u8 MOVE_RIGHT=63;
	static const u8 ROTATE_LEFT=64;
	static const u8 ROTATE_RIGHT=65;

	static const u8 STATUS_REMOVE_LINE=87;
	static const u8 STATUS_NORMAL=88;

	static const u8 BLOCK_REMOVE=160;
	static const u8 BLOCK_SOLID=161;

	void Flip();
	void Reset();
	void SetStartHeight(u8 height);
	u8 GetStartHeight(){return(iStartHeight);};
	void SetFlashCounter(u8 flash){iFlashCounter=flash;};
	u8 GetFlashCounter(){return(iFlashCounter);};
	void ResetFlashCounter();
	void SetStatus(u8 status){iStatus=status;};
	u8 GetStatus(){return(iStatus);};
	void Put();
	void ClearPos();
	bool CanMove(u8 direction);
	u16 GetBlock(u8 x, u8 y){return(iField[x][y]);};
	u16 GetNextBlock(u8 x, u8 y){return(iNextBlock[x][y]);};
	bool Move(u8 direction);
	void Rotate(u8 direction);
	u8 GetWidth(){return(WIDTH);};
	u8 GetHeight(){return(HEIGHT);};
	u8 GetVisibleHeight(){return(VISIBLE_HEIGHT);};
	void NewBlock();
	void NewBlock(u16 block[][4], u8 type, bool next);

	bool AddSolidBlocks(u8 nr);
	u8 RemoveSolidBlocks(u8 nr);

	u8 CheckFullRow(void);

	CField(void);
	~CField(void);
};

#endif // __8D963B339D73936532618C__FIELD__HPP__
