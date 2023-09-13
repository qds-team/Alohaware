/*!
 * @author		Rishabh Anand
 * @brief		Entitiy Definition
!*/

#pragma once

#include "Component.hpp"
#include <bitset>

namespace Alohaware
{
	using Entity = std::uint32_t;

	constexpr Entity MaxEntities = 5000;

	using Signature = std::bitset<MaxEntities>;
}