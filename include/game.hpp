#ifndef __F5C1993B6B7D91E1B6D2B9__GAME__HPP__
#define __F5C1993B6B7D91E1B6D2B9__GAME__HPP__

#include <Ito.h>
#include "player.hpp"

class CGame
{
private:
	CPlayer *m_pPlayer;
	u8 m_Status;
public:
	static const u8 STATUS_MAIN_MENU=10;
	static const u8 STATUS_RUNNING=11;
	static const u8 STATUS_PAUSED=12;
	static const u8 STATUS_GAME_OVER=13;

	CGame(void);
	~CGame(void);

	void AddPlayer(CPlayer *player){m_pPlayer=player;};
	CPlayer* GetPlayer(){return(m_pPlayer);};

	void SetStatus(u8 status){m_Status=status;};
	u8 GetStatus(){return(m_Status);};
};

#endif // __F5C1993B6B7D91E1B6D2B9__GAME__HPP__
