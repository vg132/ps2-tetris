#include "draw.hpp"

extern "C"
{
	extern u8 logo[];
	extern u32 size_logo;
	extern u8 mback[];
	extern u32 size_mback;
	extern u8 block1[];
	extern u16 size_block1;
	extern u8 block2[];
	extern u16 size_block2;
	extern u8 block3[];
	extern u16 size_block3;
	extern u8 block4[];
	extern u16 size_block4;
	extern u8 block5[];
	extern u16 size_block5;
	extern u8 block6[];
	extern u16 size_block6;
	extern u8 block7[];
	extern u16 size_block7;
	extern u8 block8[];
	extern u16 size_block8;
}

CDraw::CDraw()
{
	m_pGame=NULL;
	m_ScreenWidth=640;
	m_ScreenHeight=224;
	m_ScreenX=155;
	m_ScreenY=70;
	if(Ito::Gs::GetVideoMode()==VMODE_PAL)
		m_ScreenHeight=256;
	Ito::Gs::Reset();
	m_Gif.SetupEnv(RGBA16, m_ScreenWidth, m_ScreenHeight, 2, VMODE_AUTO, FRAME, ENABLE, m_ScreenX, m_ScreenY);
	m_Gif.PrimShading(PRIM_GOURAUD);

	m_Gif.AlphaBlending(0);

	m_Gif.LoadImageBuffer(m_Texture[0],logo);
	m_Gif.LoadImageBuffer(m_Texture[1],block1);
	m_Gif.LoadImageBuffer(m_Texture[2],block2);
	m_Gif.LoadImageBuffer(m_Texture[3],block3);
	m_Gif.LoadImageBuffer(m_Texture[4],block4);
	m_Gif.LoadImageBuffer(m_Texture[5],block5);
	m_Gif.LoadImageBuffer(m_Texture[6],block6);
	m_Gif.LoadImageBuffer(m_Texture[7],block7);
	m_Gif.LoadImageBuffer(m_Texture[8],block8);
	m_Gif.LoadImageBuffer(m_Texture[9],mback);
}

CDraw::~CDraw(void)
{
}

void CDraw::DrawScene()
{
	if(m_pGame==NULL)
		return;
	m_Gif.SetNextDrawbuffer();	
	m_Gif.ClearScreen();

	if(m_pGame->GetStatus()==CGame::STATUS_MAIN_MENU)
		DrawTitle();
	else
		DrawGame();

	m_Gif.Send();
}

void CDraw::DrawGame()
{
	u16 x,y;
	CField *pField=m_pGame->GetPlayer()->GetField();
	m_Gif.TextureSprite(m_Texture[9],0,0,0,m_ScreenWidth,m_ScreenHeight);

	m_Gif.PrimAlphaBlend(true);
	x=(m_ScreenWidth/2)-((pField->GetWidth()*15)/2);
	y=(m_ScreenHeight/2)-((pField->GetVisibleHeight()*7)/2);
	m_Gif.Sprite(RGBA(0,0,0,64),x,y,x+(pField->GetWidth()*15),y+(pField->GetVisibleHeight()*7));
	
	x+=(pField->GetWidth()*15)+30;
	m_Gif.Sprite(RGBA(0,0,0,64),x,y,x+150,y+(pField->GetVisibleHeight()*7));

	m_Gif.PrimAlphaBlend(false);

	DrawInfo();

	if(m_pGame->GetStatus()==CGame::STATUS_RUNNING)
		DrawField(pField);
	else if(m_pGame->GetStatus()==CGame::STATUS_PAUSED)
		m_Text.PrintText("Paused",m_ScreenWidth/2,m_ScreenHeight/2-20,RGB(255,255,255),&m_Gif,CText::LARGE_FONT,CText::ALIGN_CENTER);
	else if(m_pGame->GetStatus()==CGame::STATUS_GAME_OVER)
		m_Text.PrintText("Game Over",m_ScreenWidth/2,m_ScreenHeight/2-20,RGB(255,255,255),&m_Gif,CText::LARGE_FONT,CText::ALIGN_CENTER);
}

void CDraw::DrawField(CField *pField)
{
	u16 x(0),y(0);
	u16 type(CField::BLOCK_COLOR_NONE);
	u16 diff=(pField->GetHeight()-pField->GetVisibleHeight());

	for(y=diff;y<pField->GetHeight();y++)
	{
		for(x=0;x<pField->GetWidth();x++)
		{
			type=pField->GetBlock(x,y);
			if((LOWORD2(type)!=CField::BLOCK_COLOR_NONE)&&(HIWORD2(type)!=CField::BLOCK_REMOVE))
			{
				DrawBlock(x,y-diff,LOWORD2(type),pField);
			}
			else if((pField->GetStatus()==CField::STATUS_REMOVE_LINE)&&(HIWORD2(type)==CField::BLOCK_REMOVE))
			{
				if(pField->GetFlashCounter()>10)
					DrawBlock(x,y-diff,(LOWORD2(type)),pField);
			}
		}
	}
	if(pField->GetStatus()==CField::STATUS_REMOVE_LINE)
	{
		pField->SetFlashCounter(pField->GetFlashCounter()+1);
		if(pField->GetFlashCounter()>=20)
			pField->ResetFlashCounter();
	}
}

void CDraw::DrawBlock(int x, int y, u8 color,CField *pField)
{
	x=(x*15)+(m_ScreenWidth/2)-((pField->GetWidth()*15)/2);
	y=(y*7)+(m_ScreenHeight/2)-((pField->GetVisibleHeight()*7)/2);
	m_Gif.TextureSprite(m_Texture[color],0,x,y,x+15,y+7);
}

void CDraw::DrawInfo()
{
	u16 x,y;
	char buffer[10];
	CField *pField=m_pGame->GetPlayer()->GetField();
	x=(m_ScreenWidth/2)+((pField->GetWidth()*15)/2)+30;
	y=(m_ScreenHeight/2)-((pField->GetVisibleHeight()*7)/2);
	
	m_Text.PrintText("Points",x+10,y+10,RGB(255,255,255),&m_Gif,CText::SMALL_FONT,CText::ALIGN_LEFT);
	sprintf(buffer,"%d",m_pGame->GetPlayer()->GetPoints());
	m_Text.PrintText(buffer,x+10,y+18,RGB(255,255,255),&m_Gif,CText::SMALL_FONT,CText::ALIGN_LEFT);

	m_Text.PrintText("Level",x+10,y+30,RGB(255,255,255),&m_Gif,CText::SMALL_FONT,CText::ALIGN_LEFT);
	sprintf(buffer,"%d",m_pGame->GetPlayer()->GetLevel()+1);
	m_Text.PrintText(buffer,x+10,y+38,RGB(255,255,255),&m_Gif,CText::SMALL_FONT,CText::ALIGN_LEFT);

	m_Text.PrintText("Lines",x+10,y+50,RGB(255,255,255),&m_Gif,CText::SMALL_FONT,CText::ALIGN_LEFT);
	sprintf(buffer,"%d",m_pGame->GetPlayer()->GetLines(4));
	m_Text.PrintText(buffer,x+10,y+58,RGB(255,255,255),&m_Gif,CText::SMALL_FONT,CText::ALIGN_LEFT);

	if(m_pGame->GetPlayer()->GetShowNext())
	{
		m_Text.PrintText("Next",x+10,y+70,RGB(255,255,255),&m_Gif,CText::SMALL_FONT,CText::ALIGN_LEFT);
		DrawNext(x+10,y+85);
	}
}

void CDraw::DrawNext(u16 baseX, u16 baseY)
{
	u16 type(0);
	for(u8 y=0;y<4;y++)
	{
		for(u8 x=0;x<4;x++)
		{
			type=m_pGame->GetPlayer()->GetField()->GetNextBlock(x,y);
			if(type!=CField::BLOCK_COLOR_NONE)
				m_Gif.TextureSprite(m_Texture[type],0,(x*15)+baseX,(y*7)+baseY,(x*15)+baseX+15,(y*7)+baseY+7);
		}
	}
}

void CDraw::DrawTitle()
{
	m_Gif.TextureSprite(m_Texture[0],0,0,0,m_ScreenWidth,m_ScreenHeight);
	m_Text.PrintText("Press Start to play Tetris!",m_ScreenWidth/2,m_ScreenHeight/2+30,RGB(255,255,255),&m_Gif,CText::LARGE_FONT,CText::ALIGN_CENTER);
}
