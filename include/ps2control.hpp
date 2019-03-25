#ifndef __BCE0D0BB94C9B2103263__PS2CONTROL__HPP__
#define __BCE0D0BB94C9B2103263__PS2CONTROL__HPP__

#include <stdio.h>

#include "Ito.h"

struct button_info
{
	u32 nrTriangle;
	u32 nrCross;
	u32 nrCircle;
	u32 nrSquare;
	u32 nrDown;
	u32 nrUp;
	u32 nrLeft;
	u32 nrRight;
	u32 nrStart;
	u32 nrSelect;
	u32 nrL1;
	u32 nrL2;
	u32 nrL3;
	u32 nrR1;
	u32 nrR2;
	u32 nrR3;
};

class CPS2Control
{
private:
	u32 m_CurrentNr;
	button_info m_ButtonInfo;
	u16 m_CurrentButtonState, m_LastButtonState;
	Ito::Pad *m_pPad;
public:
	bool Init(u32 nr);
	bool DUp(u16 delay);
	bool DUpDown();
	bool DUpUp();
	bool DDown(u16 delay);
	bool DDownDown();
	bool DDownUp();
	bool DLeft(u16 delay);
	bool DLeftDown();
	bool DLeftUp();
	bool DRight(u16 delay);
	bool DRightDown();
	bool DRightUp();
	bool Start(u16 delay);
	bool StartDown();
	bool StartUp();
	bool Select(u16 delay);
	bool SelectDown();
	bool SelectUp();
	bool Triangle(u16 delay);
	bool TriangleDown();
	bool TriangleUp();
	bool Cross(u16 delay);
	bool CrossDown();
	bool CrossUp();
	bool Circle(u16 delay);
	bool CircleDown();
	bool CircleUp();
	bool Square(u16 delay);
	bool SquareDown();
	bool SquareUp();
	bool L1(u16 delay);
	bool L1Down();
	bool L1Up();
	bool L2(u16 delay);
	bool L2Down();
	bool L2Up();
	bool L3(u16 delay);
	bool L3Down();
	bool L3Up();
	bool R1(u16 delay);
	bool R1Down();
	bool R1Up();
	bool R2(u16 delay);
	bool R2Down();
	bool R2Up();
	bool R3(u16 delay);
	bool R3Down();
	bool R3Up();

	CPS2Control(Ito::Pad *pad);
	~CPS2Control(void);
};

#endif // __BCE0D0BB94C9B2103263__PS2CONTROL__HPP__
