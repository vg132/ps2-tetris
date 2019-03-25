#ifndef __1E7722BF1777FEC45193E8__CONTROL__HPP__
#define __1E7722BF1777FEC45193E8__CONTROL__HPP__

#include "player.hpp"
#include "game.hpp"

class CControl
{
public:
	CControl(void);
	~CControl(void);

	void Handle(CGame *game, u32 frmctr);
};

#endif // __1E7722BF1777FEC45193E8__CONTROL__HPP__
