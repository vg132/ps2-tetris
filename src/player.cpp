#include "player.hpp"

using namespace Ito;

CPlayer::CPlayer(Pad *pad)
{
	m_pControl=new CPS2Control(pad);

	m_iPoints=0;
  m_iLevel=0;
	for(int i=0;i<4;i++)
		m_iLines[i]=0;
  moveSize=50;
  m_bShowNext=true;
	m_pField=NULL;
}

CPlayer::~CPlayer()
{
  if(m_pField!=NULL)
		delete m_pField;
}

void CPlayer::Reset()
{
	if(m_pField!=NULL)
		delete m_pField;
	m_pField=new CField();
  m_iPoints=0;
  m_iLevel=0;
	m_lLastMove=0;
	for(int i=0;i<4;i++)
		m_iLines[i]=0;
}

void CPlayer::SetLevel(int level)
{
  m_iLevel=level;
  if(m_iLevel==0)
		moveSize=50;
  else if(m_iLevel==1)
		moveSize=40;
  else if(m_iLevel==2)
		moveSize=35;
  else if(m_iLevel==3)
		moveSize=30;
  else if(m_iLevel==4)
		moveSize=25;
  else if(m_iLevel==5)
		moveSize=20;
  else if(m_iLevel==6)
		moveSize=17;
  else if(m_iLevel==7)
		moveSize=15;
  else if(m_iLevel==8)
		moveSize=12;
  else if(m_iLevel==9)
		moveSize=10;
	else if(m_iLevel>9)
		moveSize=6;
}

void CPlayer::DeleteField()
{
	if(m_pField!=NULL)
		delete m_pField;
	m_pField=NULL;
}

void CPlayer::SetField(CField* field)
{
	if(m_pField!=NULL)
		delete m_pField;
	m_pField=field;
}

void CPlayer::SetRows(int rows)
{
	m_iLines[rows-1]++;
}

int CPlayer::GetLines(int index)
{
	if(index<4)
		return(m_iLines[index]);
	else
		return(m_iLines[0]+(m_iLines[1]*2)+(m_iLines[2]*3)+(m_iLines[3]*4));
}
