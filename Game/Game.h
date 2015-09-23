#pragma once

#include "Utilities/Logger/Log.h"

#include "Application.h"
#include "Subsystems/Logic/BaseLogic.h"
#include "Logic/BaseGameLogic.h"

namespace liman {

	class Game : public Application
	{
	public:
		Game();
		virtual ~Game() {}

	public:
		virtual bool VInit() override;
		virtual void VDoLoop() override;
		virtual bool VDeInit() override;

	public:
		virtual BaseGameLogic* GetGameLogic(void) override { return m_pLogic; }

	protected:
		BaseGameLogic* m_pLogic ;

	};

}