#pragma once
#include <dxgi.h>
#include <DirectXMath.h>

struct Transform
{
	DirectX::XMFLOAT4X4 m_mat;
	bool m_isDirty;

	DirectX::XMFLOAT4 m_quaternion;
	DirectX::XMFLOAT3 m_position;
	DirectX::XMFLOAT3 m_forward;
	DirectX::XMFLOAT3 m_scale;

	Transform();
	void SetIdentity();

	void SetPosition(const DirectX::XMFLOAT3& position);
	void Translate(const DirectX::XMFLOAT3& translation);

	void AddYaw(const float yaw);
	void AddPitch(const float pitch);
	void AddRoll(const float roll);
	void AddYPR(const float yaw, const float pitch = 0.f, const float roll = 0.f);
	void SetForward(const DirectX::XMFLOAT3& forward);
	void RotateAround(const DirectX::XMFLOAT3& axis, const float angle, const float distance);
	void SetRotationAround(const DirectX::XMFLOAT3& axis, const float angle, const float distance);

	void SetScale(const DirectX::XMFLOAT3& scale);

	void UpdateMatrix();
};

