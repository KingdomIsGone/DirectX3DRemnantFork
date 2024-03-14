#pragma once
#include "CC_StatesScript.h"


enum class eB_States
{
	IDLE,
	MOVE,
	RANGED, // 원거리 공격
	MELEE, // 근접 공격
	DAMAGED,
	DEAD,
	END,
};


class CB_FSMScript;

class CB_StateScript :
    public CC_StatesScript
{
protected:
	CB_FSMScript*	m_BHQ;
	
private:
	eB_States		m_BStateType;

public:
	virtual void begin() override;

public:
	virtual void SetStateType(UINT _StateType) override { m_BStateType = static_cast<eB_States>(_StateType); }
	virtual UINT GetStateType() const override { return static_cast<UINT>(m_BStateType); }

public:
	CLONE(CB_StateScript);
	virtual void SaveToScene(FILE* _pFile);
	virtual void LoadFromScene(FILE* _pFile);

public:
	CB_StateScript();
	virtual ~CB_StateScript();

};

