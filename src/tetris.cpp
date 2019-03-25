#include "tetris.hpp"

using namespace Ito;

CTetris::CTetris(void)
{
}

CTetris::~CTetris(void)
{
}

void CTetris::Start()
{
	u32 frmctr=0;

	Pad pad;
	pad.Open(0,0);
	printf("Waiting for pad 1\n");
	while(pad.GetState() != PAD_STATE_STABLE);
	printf("Pad 1 is ready\n");

	CPlayer *m_pPlayer=new CPlayer(&pad);
	m_pPlayer->Reset();
	m_Game.AddPlayer(m_pPlayer);
	m_Game.SetStatus(CGame::STATUS_MAIN_MENU);
	m_Draw.SetGame(&m_Game);
	while(true)
	{
		m_Control.Handle(&m_Game,frmctr);
		if(m_Game.GetStatus()==CGame::STATUS_RUNNING)
		{
			if((m_pPlayer->GetField()->GetStatus()==CField::STATUS_NORMAL)&&
				((m_pPlayer->GetLastMove()+m_pPlayer->GetMoveSize())<frmctr))
			{
				if(m_pPlayer->GetField()->Move(CField::MOVE_DOWN)==false)
				{
					u8 rows=m_pPlayer->GetField()->CheckFullRow();
					if(rows==0)
					{
						m_pPlayer->GetField()->NewBlock();
						m_pPlayer->GetField()->ClearPos();
						if(!m_pPlayer->GetField()->CanMove(CField::MOVE_DOWN))
						{
							m_pPlayer->GetField()->Put();
							m_Game.SetStatus(CGame::STATUS_GAME_OVER);
						}
						m_pPlayer->GetField()->Put();
					}
					else
					{
						switch(rows)
						{
						case 1:
							m_pPlayer->AddPoints(100*((m_pPlayer->GetLevel()/10)+1));
							break;
						case 2:
							m_pPlayer->AddPoints(300*((m_pPlayer->GetLevel()/10)+1));
							break;
						case 3:
							m_pPlayer->AddPoints(1200*((m_pPlayer->GetLevel()/10)+1));
							break;
						case 4:
							m_pPlayer->AddPoints(5100*((m_pPlayer->GetLevel()/10)+1));
							break;
						}
						m_pPlayer->SetRows(rows);
						if(m_pPlayer->GetLines(4)>=((m_pPlayer->GetLevel()+1)*10))
							m_pPlayer->SetLevel(m_pPlayer->GetLevel()+1);
					}
				}
				m_pPlayer->SetLastMove(frmctr);
			}
		}
		m_Draw.DrawScene();
		frmctr++;
	}
}
