#include "ChooseGame.h"
#include "DataManager.h"

CChooseGame::CChooseGame(CGameScene* pGameScene) : CSceneBase(pGameScene)
{
	
}


CChooseGame::~CChooseGame()
{

}


//初始化
void CChooseGame::Init()
{
	m_iGameIndex = GET_INTVALUE("GameIndex", GAME_RACING);
	m_iAnimIndex = 0;
	m_pAnimData = nullptr;
	m_bFirstAnim = false;
	m_iCurTime = 0;

	m_iSpeed = 0;
	m_iLevel = 0;
}


//更新
void CChooseGame::Play(float dt)
{
	m_iCurTime += dt * 1000;
	if (!m_bFirstAnim)
	{
		m_bFirstAnim = true;
	}
	else
	{
		if (m_iCurTime < 1000)
		{
			return;
		}

		m_iCurTime = 0;
	}

	m_pAnimData = CDataManager::getInstance()->GetAnimData(m_iGameIndex, m_iAnimIndex);
	
	//下一个动画
	if (++m_iAnimIndex >= ANIM_NUM)
	{
		m_iAnimIndex = 0;
	}

	//更新所有Brick
	m_pGameScene->UpdateBricks();
}

//获取当前Brick状态
bool CChooseGame::GetBrickState(int iRowIndex, int iColIndex)
{
	int iIndex = iRowIndex * COLUMN_NUM + iColIndex;
	return m_pAnimData->at(iIndex);
}

//获取游戏类型
SCENE_INDEX CChooseGame::GetSceneType()
{
	return SCENE_CHOOSEGAME;
}

//左
void CChooseGame::OnLeft()
{
	if (m_iLevel > 0)
	{
		--m_iLevel;
		m_pGameScene->UpdateLevel(m_iLevel);
	}
}

//右
void CChooseGame::OnRight()
{
	if (m_iLevel < 10)
	{
		++m_iLevel;
		m_pGameScene->UpdateLevel(m_iLevel);
	}
}

//上
void CChooseGame::OnUp()
{
	if (m_iSpeed < 10)
	{
		++m_iSpeed;
		m_pGameScene->UpdateSpeed(m_iSpeed);
	}
}

//下
void CChooseGame::OnDown()
{
	if (m_iSpeed > 0)
	{
		--m_iSpeed;
		m_pGameScene->UpdateSpeed(m_iSpeed);
	}
}

//Fire
void CChooseGame::OnFire()
{

}

//开始
void CChooseGame::OnStart()
{

}
