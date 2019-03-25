#include "game.hpp"

CGame::CGame(void)
{
	m_pPlayer=NULL;
}

CGame::~CGame(void)
{
	if(m_pPlayer!=NULL)
		delete m_pPlayer;
	m_pPlayer=NULL;
}
