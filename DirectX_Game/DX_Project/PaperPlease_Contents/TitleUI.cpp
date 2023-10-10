#include "PreCompile.h"
#include "TitleUI.h"

#include "Cursor.h"
#include "QuitButton.h"

TitleUI::TitleUI()
{
}

TitleUI::~TitleUI()
{
}

void TitleUI::Start()
{

	std::shared_ptr<Cursor> NewCursor = CreateComponent<Cursor>(GameObjectType::Cursor);
	std::shared_ptr<BasicButton> NewQuitButton = CreateComponent<QuitButton>(GameObjectType::UI);
	NewQuitButton.get()->Transform.SetLocalPosition({ 1100,-50 });

}

void TitleUI::Update(float _Delta)
{
}
