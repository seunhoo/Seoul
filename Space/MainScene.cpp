#include "stdafx.h"
#include "MainScene.h"
#include"StageOne.h"
#include"Player.h"

MainScene::MainScene()
{
}

MainScene::~MainScene()
{
}

void MainScene::Init()
{
	SceneDirector::GetInst()->ChangeScene(new StageOne());
}

void MainScene::Release()
{
}

void MainScene::Update(float deltaTime, float time)
{

}

void MainScene::Render()
{
}
