#include "Transform.h"

using namespace DirectX;

Transform::Transform()
{
	SetIdentity();
	m_isDirty = true;
}

void Transform::SetIdentity()
{
	XMStoreFloat4x4(&m_mat, XMMatrixIdentity());
	XMStoreFloat4(&m_quaternion, XMQuaternionIdentity());
	m_position = { 0.f, 0.f, 0.f };
	m_forward = { 0.f, 1.f, 0.f };
	m_scale = { 1.f, 1.f, 1.f };
}

void Transform::SetPosition(const DirectX::XMFLOAT3& position)
{
	m_position = position;
}

void Transform::Translate(const DirectX::XMFLOAT3& translation)
{
	XMStoreFloat3(
		&m_position, 
		XMVectorAdd(
			XMLoadFloat3(&m_position),
			XMLoadFloat3(&translation)
		)
	);

	XMVector3TransformCoord()
}

void Transform::AddYaw(const float yaw)
{
	XMMATRIX rotation = XMMatrixRotationRollPitchYaw(0.f, yaw, 0.f);

}

void Transform::AddPitch(const float pitch)
{
	XMMATRIX rotation = XMMatrixRotationRollPitchYaw(pitch, 0.f, 0.f);
}

void Transform::AddRoll(const float roll)
{
	XMMATRIX rotation = XMMatrixRotationRollPitchYaw(0.f, 0.f, roll);
}

void Transform::AddYPR(const float yaw, const float pitch, const float roll)
{
	XMMATRIX rotation = XMMatrixRotationRollPitchYaw(pitch, yaw, roll);
}

void Transform::SetForward(const DirectX::XMFLOAT3& forward)
{
}

void Transform::RotateAround(const DirectX::XMFLOAT3& axis, const float angle, const float distance)
{
}

void Transform::SetRotationAround(const DirectX::XMFLOAT3& axis, const float angle, const float distance)
{
}

void Transform::SetScale(const DirectX::XMFLOAT3& scale)
{
}

void Transform::UpdateMatrix()
{
	XMStoreFloat4x4(
		XMMatrixAffineTransformation(
			XMLoadFloat3()
		)
	);
}
