#include "control.hpp"

CControl::CControl(void)
{
}

CControl::~CControl(void)
{
}

void CControl::Handle(CGame *game,u32 frmctr)
{
	CPlayer *player=game->GetPlayer();
	CPS2Control *control=player->GetControl();

	control->Init(frmctr);

	if(game->GetStatus()==CGame::STATUS_MAIN_MENU)
	{
		if(control->StartUp())
		{
			player->Reset();
			player->GetField()->NewBlock();
			game->SetStatus(CGame::STATUS_RUNNING);
		}
	}
	else if(game->GetStatus()==CGame::STATUS_RUNNING)
	{
		if(control->StartDown())
		{
			game->SetStatus(CGame::STATUS_PAUSED);
		}
		else if(control->SelectDown())
		{
			player->SetShowNext(!player->GetShowNext());
		}
		else if(control->DLeft(7))
		{
			player->GetField()->Move(CField::MOVE_LEFT);
		}
		else if(control->DRight(7))
		{
			player->GetField()->Move(CField::MOVE_RIGHT);
		}
		else if(control->DDown(2))
		{
			if(player->GetField()->Move(CField::MOVE_DOWN))
			{
				player->SetLastMove(frmctr);
				player->AddPoints(1);
			}
		}
		else if(control->Cross(14))
		{
			player->GetField()->Rotate(CField::ROTATE_LEFT);
		}
		else if(control->Circle(14))
		{
			player->GetField()->Rotate(CField::ROTATE_RIGHT);
		}
	}
	else if(game->GetStatus()==CGame::STATUS_PAUSED)
	{
		if(control->StartDown())
			game->SetStatus(CGame::STATUS_RUNNING);
	}
	else if(game->GetStatus()==CGame::STATUS_GAME_OVER)
	{
		if(control->StartUp())
			game->SetStatus(CGame::STATUS_MAIN_MENU);
	}
}
