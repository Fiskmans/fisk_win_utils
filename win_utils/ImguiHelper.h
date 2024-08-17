
#pragma once

#include "win_utils/Window.h"
#include "win_utils/GraphicsFramework.h"

namespace fisk::win_utils
{
	
	class ImguiHelper
	{
	public:
		ImguiHelper(GraphicsFramework& aFramework, Window& aWindow);

		ImguiHelper(const ImguiHelper&) = delete;
		ImguiHelper(ImguiHelper&&) = delete;

		ImguiHelper& operator=(ImguiHelper&&) = delete;
		ImguiHelper& operator=(const ImguiHelper&) = delete;

		~ImguiHelper();
		
		tools::Event<> DrawImgui;

	private:
		void BeforePresent();
		void AfterPresent();
		std::optional<LRESULT> WndProc(HWND aHWND, UINT aUMsg, WPARAM aWParam, LPARAM aLParam);

		GraphicsFramework& myFramework;
		tools::EventReg myBeforePresentEventReg;
		tools::EventReg myAfterPresentEventReg;
		tools::EventReg myWndProcEventReg;
	};
}