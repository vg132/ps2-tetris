#ifndef __52C7E44F10C2CBB56DDF2__DRAW__HPP__
#define __52C7E44F10C2CBB56DDF2__DRAW__HPP__

#include <Ito.h>
#include <stdio.h>

#include "field.hpp"
#include "text.hpp"
#include "game.hpp"

class CDraw
{
private:
	Ito::GifPipe m_Gif;
	CText m_Text;
	CGame *m_pGame;

	u32 m_ScreenWidth;
	u32 m_ScreenHeight;
	u32 m_ScreenX;
	u32 m_ScreenY;
	Ito::Texture m_Texture[10];

	void DrawField(CField *pField);
	void DrawInfo();
	void DrawTitle();
	void DrawGame();
	void DrawNext(u16 baseX, u16 baseY);
	void DrawBlock(int x, int y, u8 color,CField *pField);

	inline u8 LOWORD2(u16 i){return(i & 0xFF);};
	inline u8 HIWORD2(u16 i){return(i >> 8);};
public:
	CDraw();
	~CDraw(void);

	void SetGame(CGame *game){m_pGame=game;};
	void DrawScene();
};

#endif // __52C7E44F10C2CBB56DDF2__DRAW__HPP__
