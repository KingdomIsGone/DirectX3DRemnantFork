#include "pch.h"
#include "CCollider3D.h"
#include "CResMgr.h"

CCollider3D::CCollider3D()
	: CComponent(COMPONENT_TYPE::COLLIDER3D)
	  , mType(COLLIDER3D_TYPE::NONE)
{
}

CCollider3D::CCollider3D(const CCollider3D& _collider)
	: CComponent(COMPONENT_TYPE::COLLIDER3D)
	  , mType(_collider.mType)
{
	mMesh = CResMgr::GetInst()->FindRes<CMesh>(L"CubeMesh");
	mMaterial = CResMgr::GetInst()->FindRes<CMaterial>(L"DebugShapeMtrl");
}

CCollider3D::~CCollider3D()
{
}

void CCollider3D::SaveToLevelFile(FILE* _File)
{
}

void CCollider3D::LoadFromLevelFile(FILE* _FILE)
{
}

void CCollider3D::begin()
{
	AssertEx(IsPhysicsObject(), L"Collider::Initialize() - �浹�� ����ϱ� ���ؼ��� RigidBody->SetPhysical()�� ����Ǿ�� ��.");
}

void CCollider3D::tick()
{
}

void CCollider3D::finaltick()
{
}

void CCollider3D::OnCollisionEnter(CCollider3D* _otherCollider)
{
	//mCollisionCount++;
}

void CCollider3D::OnCollisionStay(CCollider3D* _otherCollider)
{
}

void CCollider3D::OnCollisionExit(CCollider3D* _otherCollider)
{
	mCollisionCount--;

	if (0 > mCollisionCount)
		mCollisionCount = 0;
}

void CCollider3D::OnTriggerEnter(CCollider3D* _otherCollider)
{
	mCollisionCount++;
}

void CCollider3D::OnTriggerStay(CCollider3D* _otherCollider)
{
}

void CCollider3D::OnTriggerExit(CCollider3D* _otherCollider)
{
	mCollisionCount--;

	if (0 > mCollisionCount)
		mCollisionCount = 0;
}