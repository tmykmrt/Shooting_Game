#pragma once

namespace Collision
{
	class ICollisionReceiver
	{
	public:
		virtual ~ICollisionReceiver() {};
		virtual void Receive() = 0;
	};
}
