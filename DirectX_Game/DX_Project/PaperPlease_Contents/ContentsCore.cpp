#include "PreCompile.h"
#include "ContentsCore.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineSampler.h>
#include <GameEngineCore/GameEngineBlend.h>

#include "ControlManager.h"

#include "TitleLevel.h"
#include "PlayLevel.h"
#include"DayOffLevel.h"
#include "StartIntroLevel.h"

//#include<GameEnginePlatform/GameEngineWindow.h>

ContentsCore::ContentsCore() 
{
}

ContentsCore::~ContentsCore() 
{
}

void ContentsCore::UserRes()
{

	{

		{
			// ������ ���̴��� ���δ� ���δ� �ε��ϴ� �ڵ带 ģ��.
			GameEngineDirectory Dir;
			Dir.MoveParentToExistsChild("PaperPlease_Contents");
			Dir.MoveChild("PaperPlease_Contents");
			//Dir.MoveChild("Shader");
			std::vector<GameEngineFile> Files = Dir.GetAllFile({ ".fx" });

			for (size_t i = 0; i < Files.size(); i++)
			{
				// ���������� �� �����ϰ� �ִ����� �ڽ��� ��Ȯ�ϰ� �����ϱ� ���ؼ�
				GameEngineFile& File = Files[i];
				GameEngineShader::AutoCompile(File);
			}
			
		}
	}

	{
		std::shared_ptr<GameEngineMaterial> Mat = GameEngineMaterial::Create("Custom2DTexture");
		Mat->SetVertexShader("CustomTextureShader_VS");
		Mat->SetPixelShader("CustomTextureShader_PS");
	}

	
	{
		
			std::shared_ptr<GameEngineMaterial> Mat = GameEngineMaterial::Create("FacePaletteTexture");
			Mat->SetVertexShader("FacePaletteTexture_VS");
			Mat->SetPixelShader("FacePaletteTexture_PS");
		
	}



	{
		D3D11_BLEND_DESC Desc = {};
		Desc.IndependentBlendEnable = false;
		Desc.RenderTarget[0].BlendEnable = true;
		Desc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;

		Desc.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
		Desc.RenderTarget[0].SrcBlend = D3D11_BLEND_ONE; // src����
		Desc.RenderTarget[0].DestBlend = D3D11_BLEND_ONE;

		Desc.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
		Desc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ZERO;
		Desc.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ONE;

		std::shared_ptr<GameEngineBlend> Blend = GameEngineBlend::Create("OverRay", Desc);
	}

	{
		std::shared_ptr<GameEngineMaterial> Mat = GameEngineMaterial::Create("2DTextureOver");
		Mat->SetVertexShader("TextureShader_VS");
		Mat->SetPixelShader("TextureShader_PS");
		Mat->SetBlendState("OverRay");
	}
}

void ContentsCore::Start()
{

	GameEngineRenderTarget::IsDepth = false;
	GameEngineCore::MainWindow.CursorOff();


	{
		UIWindow =GameEngineGUI::CreateGUIWindow<ControlManager>("ControlManager");
		
	}

	UserRes();

	GameEngineCore::CreateLevel<TitleLevel>("TitleLevel");
	GameEngineCore::CreateLevel<DayOffLevel>("DayOffLevel");
	GameEngineCore::CreateLevel<PlayLevel>("PlayLevel");
	GameEngineCore::CreateLevel<StartIntroLevel>("StartIntroLevel");


	GameEngineCore::ChangeLevel("TitleLevel");

	// �ڱ� �ؽ�ó �ε��ؾ� �Ѵ�.

}

void ContentsCore::Update(float _Delta)
{
	/*float4 MousePos = GameEngineCore::MainWindow.GetMousePos();
	UIWindow.get()->*/
	
}


void ContentsCore::Release()
{

}