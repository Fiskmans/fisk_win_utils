
#include "win_utils/Window.h"
#include "win_utils/GraphicsFramework.h"
#include "win_utils/ImguiHelper.h"

#include "imgui.h"
#include "imgui_tree.h"

struct TreeLike
{
	TreeLike(std::string aName)
	{
		myName = aName;
	}

	std::string myName;
	std::vector<TreeLike> myNodes;
};

int main()
{
	fisk::win_utils::Window window;
	fisk::win_utils::GraphicsFramework framework(window);
	fisk::win_utils::ImguiHelper imgui(framework, window);

	fisk::tools::V4f clearColor = { 0.5f, 0.5f, 0.5f, 1.f };
	bool demoWindowEnabled = false;
	bool vSync = true;
	float rounding = 0.f;
	float indentDepth = 15.f;
	float thickness = 1.f;
	fisk::tools::V4f treeColor = { 0.5f, 0.5f, 0.5f, 1.f };

	TreeLike tree("Root");

	tree.myNodes.emplace_back("Node 1");
	tree.myNodes[0].myNodes.emplace_back("Leaf 1");
	tree.myNodes[0].myNodes.emplace_back("Leaf 2");
	
	tree.myNodes.emplace_back("Node 2");
	tree.myNodes[1].myNodes.emplace_back("Leaf 3");

	tree.myNodes.emplace_back("Node 3");
	tree.myNodes[2].myNodes.emplace_back("Leaf 4\nmultiline\nadventures");

	fisk::tools::EventReg demoWindowHandle = imgui.DrawImgui.Register([&]()
	{
		ImGui::Begin("Graphics");

		ImGui::Checkbox("Imgui demo", &demoWindowEnabled);
		ImGui::ColorEdit4("Clear color", clearColor.Raw());
		ImGui::Checkbox("V sync", &vSync);

		if (ImGui::CollapsingHeader("Tree"))
		{
			ImGui::DragFloat("Rounding", &rounding);
			ImGui::DragFloat("Indent", &indentDepth);
			ImGui::DragFloat("Thickness", &thickness);
			ImGui::ColorEdit4("Color", treeColor.Raw());

			imgui_extensions::Tree("Tree",
				tree, 
				[](TreeLike& aNode)
				{
					ImGui::Text(aNode.myName.c_str());
				},
				[](TreeLike& aNode) -> auto&
				{
					return aNode.myNodes;
				},
				ImColor(treeColor[0], treeColor[1], treeColor[2], treeColor[3]),
				indentDepth,
				rounding,
				thickness);
		}

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