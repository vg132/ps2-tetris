#include "ps2control.hpp"

using namespace Ito;

CPS2Control::CPS2Control(Pad *pad)
{
	m_pPad=pad;

	m_LastButtonState=0;
	m_CurrentButtonState=0;
	m_ButtonInfo.nrSquare=0;
	m_ButtonInfo.nrCircle=0;
	m_ButtonInfo.nrCross=0;
	m_ButtonInfo.nrTriangle=0;
	m_ButtonInfo.nrStart=0;
	m_ButtonInfo.nrSelect=0;
	m_ButtonInfo.nrUp=0;
	m_ButtonInfo.nrDown=0;
	m_ButtonInfo.nrLeft=0;
	m_ButtonInfo.nrRight=0;
	m_ButtonInfo.nrL1=0;
	m_ButtonInfo.nrL2=0;
	m_ButtonInfo.nrL3=0;
	m_ButtonInfo.nrR1=0;
	m_ButtonInfo.nrR2=0;
	m_ButtonInfo.nrR3=0;
}

CPS2Control::~CPS2Control(void)
{
}

bool CPS2Control::Init(u32 nr)
{
	m_CurrentNr=nr;
	m_LastButtonState=m_CurrentButtonState;
	m_CurrentButtonState=m_pPad->ReadButtons();
	return(true);
}

bool CPS2Control::DUp(u16 delay)
{
	if((m_CurrentButtonState & PAD_UP)&&((m_ButtonInfo.nrUp+delay)<m_CurrentNr))
	{
		m_ButtonInfo.nrUp=m_CurrentNr;
		return(true);
	}
	else if(!m_CurrentButtonState & PAD_UP)
	{
		m_ButtonInfo.nrUp=0;
		return(false);
	}
	return(false);
}

bool CPS2Control::DDown(u16 delay)
{
	if((m_CurrentButtonState & PAD_DOWN)&&((m_ButtonInfo.nrDown+delay)<m_CurrentNr))
	{
		m_ButtonInfo.nrDown=m_CurrentNr;
		return(true);
	}
	else if(!m_CurrentButtonState & PAD_DOWN)
	{
		m_ButtonInfo.nrDown=0;
		return(false);
	}
	return(false);
}

bool CPS2Control::DLeft(u16 delay)
{
	if((m_CurrentButtonState & PAD_LEFT)&&((m_ButtonInfo.nrLeft+delay)<m_CurrentNr))
	{
		m_ButtonInfo.nrLeft=m_CurrentNr;
		return(true);
	}
	else if(!m_CurrentButtonState & PAD_LEFT)
	{
		m_ButtonInfo.nrLeft=0;
		return(false);
	}
	return(false);
}

bool CPS2Control::DRight(u16 delay)
{
	if((m_CurrentButtonState & PAD_RIGHT)&&((m_ButtonInfo.nrRight+delay)<m_CurrentNr))
	{
		m_ButtonInfo.nrRight=m_CurrentNr;
		return(true);
	}
	else if(!m_CurrentButtonState & PAD_RIGHT)
	{
		m_ButtonInfo.nrRight=0;
		return(false);
	}
	return(false);
}

bool CPS2Control::Start(u16 delay)
{
	if((m_CurrentButtonState & PAD_START)&&((m_ButtonInfo.nrStart+delay)<m_CurrentNr))
	{
		m_ButtonInfo.nrStart=m_CurrentNr;
		return(true);
	}
	else if(!m_CurrentButtonState & PAD_START)
	{
		m_ButtonInfo.nrStart=0;
		return(false);
	}
	return(false);
}

bool CPS2Control::Select(u16 delay)
{
	if((m_CurrentButtonState & PAD_SELECT)&&((m_ButtonInfo.nrSelect+delay)<m_CurrentNr))
	{
		m_ButtonInfo.nrSelect=m_CurrentNr;
		return(true);
	}
	else if(!m_CurrentButtonState & PAD_SELECT)
	{
		m_ButtonInfo.nrSelect=0;
		return(false);
	}
	return(false);
}

bool CPS2Control::Square(u16 delay)
{
	if((m_CurrentButtonState & PAD_SQUARE)&&((m_ButtonInfo.nrSquare+delay)<m_CurrentNr))
	{
		m_ButtonInfo.nrSquare=m_CurrentNr;
		return(true);
	}
	else if(!m_CurrentButtonState & PAD_SQUARE)
	{
		m_ButtonInfo.nrSquare=0;
		return(false);
	}
	return(false);
}

bool CPS2Control::Cross(u16 delay)
{
	if((m_CurrentButtonState & PAD_CROSS)&&((m_ButtonInfo.nrCross+delay)<m_CurrentNr))
	{
		m_ButtonInfo.nrCross=m_CurrentNr;
		return(true);
	}
	else if(!m_CurrentButtonState & PAD_CROSS)
	{
		m_ButtonInfo.nrCross=0;
		return(false);
	}
	return(false);
}

bool CPS2Control::Circle(u16 delay)
{
	if((m_CurrentButtonState & PAD_CIRCLE)&&((m_ButtonInfo.nrCircle+delay)<m_CurrentNr))
	{
		m_ButtonInfo.nrCircle=m_CurrentNr;
		return(true);
	}
	else if(!m_CurrentButtonState & PAD_CIRCLE)
	{
		m_ButtonInfo.nrCircle=0;
		return(false);
	}
	return(false);
}

bool CPS2Control::Triangle(u16 delay)
{
	if((m_CurrentButtonState & PAD_TRIANGLE)&&((m_ButtonInfo.nrTriangle+delay)<m_CurrentNr))
	{
		m_ButtonInfo.nrTriangle=m_CurrentNr;
		return(true);
	}
	else if(!m_CurrentButtonState & PAD_TRIANGLE)
	{
		m_ButtonInfo.nrTriangle=0;
		return(false);
	}
	return(false);
}

bool CPS2Control::L1(u16 delay)
{
	if((m_CurrentButtonState & PAD_L1)&&((m_ButtonInfo.nrL1+delay)<m_CurrentNr))
	{
		m_ButtonInfo.nrL1=m_CurrentNr;
		return(true);
	}
	else if(!m_CurrentButtonState & PAD_L1)
	{
		m_ButtonInfo.nrL1=0;
		return(false);
	}
	return(false);
}

bool CPS2Control::L2(u16 delay)
{
	if((m_CurrentButtonState & PAD_L2)&&((m_ButtonInfo.nrL2+delay)<m_CurrentNr))
	{
		m_ButtonInfo.nrL2=m_CurrentNr;
		return(true);
	}
	else if(!m_CurrentButtonState & PAD_L2)
	{
		m_ButtonInfo.nrL2=0;
		return(false);
	}
	return(false);
}

bool CPS2Control::L3(u16 delay)
{
	if((m_CurrentButtonState & PAD_L3)&&((m_ButtonInfo.nrL3+delay)<m_CurrentNr))
	{
		m_ButtonInfo.nrL3=m_CurrentNr;
		return(true);
	}
	else if(!m_CurrentButtonState & PAD_L3)
	{
		m_ButtonInfo.nrL3=0;
		return(false);
	}
	return(false);
}

bool CPS2Control::R1(u16 delay)
{
	if((m_CurrentButtonState & PAD_R1)&&((m_ButtonInfo.nrR1+delay)<m_CurrentNr))
	{
		m_ButtonInfo.nrR1=m_CurrentNr;
		return(true);
	}
	else if(!m_CurrentButtonState & PAD_R1)
	{
		m_ButtonInfo.nrR1=0;
		return(false);
	}
	return(false);
}

bool CPS2Control::R2(u16 delay)
{
	if((m_CurrentButtonState & PAD_R2)&&((m_ButtonInfo.nrR2+delay)<m_CurrentNr))
	{
		m_ButtonInfo.nrR2=m_CurrentNr;
		return(true);
	}
	else if(!m_CurrentButtonState & PAD_R2)
	{
		m_ButtonInfo.nrR2=0;
		return(false);
	}
	return(false);
}

bool CPS2Control::R3(u16 delay)
{
	if((m_CurrentButtonState & PAD_R3)&&((m_ButtonInfo.nrR3+delay)<m_CurrentNr))
	{
		m_ButtonInfo.nrR3=m_CurrentNr;
		return(true);
	}
	else if(!m_CurrentButtonState & PAD_R3)
	{
		m_ButtonInfo.nrR3=0;
		return(false);
	}
	return(false);
}

bool CPS2Control::DUpUp()
{
	if((!(m_CurrentButtonState & PAD_UP))&&(m_LastButtonState & PAD_UP))
		return(true);
	return(false);
}

bool CPS2Control::DUpDown()
{
	if((!(m_LastButtonState & PAD_UP))&&(m_CurrentButtonState & PAD_UP))
		return(true);
	return(false);
}

bool CPS2Control::DDownUp()
{
	if((!(m_CurrentButtonState & PAD_DOWN))&&(m_LastButtonState & PAD_DOWN))
		return(true);
	return(false);
}

bool CPS2Control::DDownDown()
{
	if((!(m_LastButtonState & PAD_DOWN))&&(m_CurrentButtonState & PAD_DOWN))
		return(true);
	return(false);
}

bool CPS2Control::DLeftUp()
{
	if((!(m_CurrentButtonState & PAD_LEFT))&&(m_LastButtonState & PAD_LEFT))
		return(true);
	return(false);
}

bool CPS2Control::DLeftDown()
{
	if((!(m_LastButtonState & PAD_LEFT))&&(m_CurrentButtonState & PAD_LEFT))
		return(true);
	return(false);
}

bool CPS2Control::DRightUp()
{
	if((!(m_CurrentButtonState & PAD_RIGHT))&&(m_LastButtonState & PAD_RIGHT))
		return(true);
	return(false);
}
bool CPS2Control::DRightDown()
{
	if((!(m_LastButtonState & PAD_RIGHT))&&(m_CurrentButtonState & PAD_RIGHT))
		return(true);
	return(false);
}

bool CPS2Control::StartUp()
{
	if((!(m_CurrentButtonState & PAD_START))&&(m_LastButtonState & PAD_START))
		return(true);
	return(false);
}

bool CPS2Control::StartDown()
{
	if((!(m_LastButtonState & PAD_START))&&(m_CurrentButtonState & PAD_START))
		return(true);
	return(false);
}

bool CPS2Control::SelectUp()
{
	if((!(m_CurrentButtonState & PAD_SELECT))&&(m_LastButtonState & PAD_SELECT))
		return(true);
	return(false);
}

bool CPS2Control::SelectDown()
{
	if((!(m_LastButtonState & PAD_SELECT))&&(m_CurrentButtonState & PAD_SELECT))
		return(true);
	return(false);
}

bool CPS2Control::SquareUp()
{
	if((!(m_CurrentButtonState & PAD_SQUARE))&&(m_LastButtonState & PAD_SQUARE))
		return(true);
	return(false);
}

bool CPS2Control::SquareDown()
{
	if((!(m_LastButtonState & PAD_SQUARE))&&(m_CurrentButtonState & PAD_SQUARE))
		return(true);
	return(false);
}

bool CPS2Control::CrossUp()
{
	if((!(m_CurrentButtonState & PAD_CROSS))&&(m_LastButtonState & PAD_CROSS))
		return(true);
	return(false);
}

bool CPS2Control::CrossDown()
{
	if((!(m_LastButtonState & PAD_CROSS))&&(m_CurrentButtonState & PAD_CROSS))
		return(true);
	return(false);
}

bool CPS2Control::CircleUp()
{
	if((!(m_CurrentButtonState & PAD_CIRCLE))&&(m_LastButtonState & PAD_CIRCLE))
		return(true);
	return(false);
}

bool CPS2Control::CircleDown()
{
	if((!(m_LastButtonState & PAD_CIRCLE))&&(m_CurrentButtonState & PAD_CIRCLE))
		return(true);
	return(false);
}

bool CPS2Control::TriangleUp()
{
	if((!(m_CurrentButtonState & PAD_TRIANGLE))&&(m_LastButtonState & PAD_TRIANGLE))
		return(true);
	return(false);
}

bool CPS2Control::TriangleDown()
{
	if((!(m_LastButtonState & PAD_TRIANGLE))&&(m_CurrentButtonState & PAD_TRIANGLE))
		return(true);
	return(false);
}

bool CPS2Control::L1Up()
{
	if((!(m_CurrentButtonState & PAD_L1))&&(m_LastButtonState & PAD_L1))
		return(true);
	return(false);
}

bool CPS2Control::L1Down()
{
	if((!(m_LastButtonState & PAD_L1))&&(m_CurrentButtonState & PAD_L1))
		return(true);
	return(false);
}

bool CPS2Control::L2Up()
{
	if((!(m_CurrentButtonState & PAD_L2))&&(m_LastButtonState & PAD_L2))
		return(true);
	return(false);
}

bool CPS2Control::L2Down()
{
	if((!(m_LastButtonState & PAD_L2))&&(m_CurrentButtonState & PAD_L2))
		return(true);
	return(false);
}

bool CPS2Control::L3Up()
{
	if((!(m_CurrentButtonState & PAD_L3))&&(m_LastButtonState & PAD_L3))
		return(true);
	return(false);
}

bool CPS2Control::L3Down()
{
	if((!(m_LastButtonState & PAD_L3))&&(m_CurrentButtonState & PAD_L3))
		return(true);
	return(false);
}

bool CPS2Control::R1Up()
{
	if((!(m_CurrentButtonState & PAD_R1))&&(m_LastButtonState & PAD_R1))
		return(true);
	return(false);
}

bool CPS2Control::R1Down()
{
	if((!(m_LastButtonState & PAD_R1))&&(m_CurrentButtonState & PAD_R1))
		return(true);
	return(false);
}

bool CPS2Control::R2Up()
{
	if((!(m_CurrentButtonState & PAD_R2))&&(m_LastButtonState & PAD_R2))
		return(true);
	return(false);
}

bool CPS2Control::R2Down()
{
	if((!(m_LastButtonState & PAD_R2))&&(m_CurrentButtonState & PAD_R2))
		return(true);
	return(false);
}

bool CPS2Control::R3Up()
{
	if((!(m_CurrentButtonState & PAD_R3))&&(m_LastButtonState & PAD_R3))
		return(true);
	return(false);
}

bool CPS2Control::R3Down()
{
	if((!(m_LastButtonState & PAD_R3))&&(m_CurrentButtonState & PAD_R3))
		return(true);
	return(false);
}
