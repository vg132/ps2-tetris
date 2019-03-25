#ifndef __9120A7394A2A33B667D4D__TETRIS__HPP__
#define __9120A7394A2A33B667D4D__TETRIS__HPP__

#include <Ito.h>

#include "draw.hpp"
#include "player.hpp"
#include "control.hpp"
#include "game.hpp"

class CTetris
{
private:
	Ito::Pad *pad;
	CControl m_Control;
	CGame m_Game;
	CDraw m_Draw;
public:
	CTetris(void);
	~CTetris(void);

	void Start();
};
#endif // __9120A7394A2A33B667D4D__TETRIS__HPP__
