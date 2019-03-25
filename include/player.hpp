#ifndef __C5BEE1B54433737EFF42__PLAYER__HPP__
#define __C5BEE1B54433737EFF42__PLAYER__HPP__

#include <Ito.h>

#include "field.hpp"
#include "ps2control.hpp"

class CPlayer
{
private:
	//PS2
	CPS2Control *m_pControl;

	//Dreamcast
	int m_iPoints, m_iLevel;
	bool m_bShowNext, m_bPaused;
	CField *m_pField;
	unsigned long int moveSize, m_lLastMove;
	int m_iLines[4];
public:
	CPlayer(Ito::Pad *pad);
  ~CPlayer();
	void SetPaused(bool pause){m_bPaused=pause;};
	bool GetPaused(){return(m_bPaused);};

	void Reset();
	void DeleteField();
	void SetRows(int rows);
	void SetLevel(int level);
	void SetField(CField* field);

	CPS2Control* GetControl(){return(m_pControl);};

	int GetLevel(){return(m_iLevel);};
	int GetPoints(){return(m_iPoints);};
	CField* GetField(){return(m_pField);};
	bool GetShowNext(){return(m_bShowNext);};
	void SetPoints(int points){m_iPoints=points;};
	void AddPoints(int points){m_iPoints+=points;};
	void SetShowNext(bool show){m_bShowNext=show;};
	void RemovePoints(int points){m_iPoints-=points;};
	unsigned long int GetMoveSize(){return(moveSize);};
	unsigned long int GetLastMove(){return(m_lLastMove);};
	void SetMoveSize(unsigned long int size){moveSize=size;};
	void SetLastMove(unsigned long int lastMove){m_lLastMove=lastMove;};

	int GetLines(int index);
};

#endif // __C5BEE1B54433737EFF42__PLAYER__HPP__
