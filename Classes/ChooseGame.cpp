#include "ChooseGame.h"
#include "DataManager.h"

CChooseGame::CChooseGame(CGameScene* pGameScene) : CSceneBase(pGameScene)
{
	
}


CChooseGame::~CChooseGame()
{

}


//��ʼ��
void CChooseGame::Init()
{
	m_iGameIndex = GET_INTVALUE("GameIndex", GAME_RACING);
	m_iAnimIndex = 0;
	m_pAnimData = nullptr;
	m_bFirstAnim = false;
	m_iCurTime = 0;
}


//��Ϸ���У�����ֵ��ʾ��ǰ״̬
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
	
	//��һ������
	if (++m_iAnimIndex >= ANIM_NUM)
	{
		m_iAnimIndex = 0;
	}

	//��������Brick
	m_pGameScene->UpdateBricks();
}

//��ȡ��ǰBrick״̬
bool CChooseGame::GetBrickState(int iRowIndex, int iColIndex)
{
	int iIndex = iRowIndex * COLUMN_NUM + iColIndex;
	return m_pAnimData->at(iIndex);
}

//��ȡ��Ϸ����
SCENE_INDEX CChooseGame::GetSceneType()
{
	return SCENE_CHOOSEGAME;
}

//��
void CChooseGame::OnLeft()
{

}

//��
void CChooseGame::OnRight()
{

}

//��
void CChooseGame::OnUp()
{

}

//��
void CChooseGame::OnDown()
{

}

//Fire
void CChooseGame::OnFire()
{

}

//��ʼ
void CChooseGame::OnStart()
{

}