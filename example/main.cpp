
#include "win_utils/Window.h"
#include "win_utils/GraphicsFramework.h"
#include "win_utils/ImguiHelper.h"

#include "imgui.h"

int main()
{
	fisk::win_utils::Window window;
	fisk::win_utils::GraphicsFramework framework(window);
	fisk::win_utils::ImguiHelper imgui(framework, window);

	fisk::tools::V4f clearColor = { 0.5f, 0.5f, 0.5f, 1.f };
	bool demoWindowEnabled = false;
	bool vSync = true;

	fisk::tools::EventReg demoWindowHandle = imgui.DrawImgui.Register([&]()
	{
		ImGui::Begin("Graphics");

		ImGui::Checkbox("Imgui demo", &demoWindowEnabled);
		ImGui::ColorEdit4("Clear color", clearColor.Raw());
		ImGui::Checkbox("V sync", &vSync);

		ImGui::End();

		if (demoWindowEnabled)
			ImGui::ShowDemoWindow(&demoWindowEnabled);
	});

	while (window.ProcessEvents())
	{
		{
			fisk::win_utils::ContextUtility context = framework.Context();

			ID3D11RenderTargetView* renderTarget = framework.GetBackBufferRenderTarget();

			context.ClearRenderTarget(renderTarget, clearColor);
		}

		if (vSync)
		{
			framework.Present(fisk::win_utils::GraphicsFramework::VSyncState::OnVerticalBlank);
		}
		else
		{
			framework.Present(fisk::win_utils::GraphicsFramework::VSyncState::Immediate);
		}
	}
}