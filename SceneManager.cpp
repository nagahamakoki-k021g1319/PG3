#include "SceneManager.h"
#include <stdio.h>

SceneManager::SceneManager() {}

SceneManager::~SceneManager(){}

SceneManager* SceneManager::GetInstance()
{
	//ŠÖ”“àstatic•Ï”‚Æ‚µ‚ÄéŒ¾‚·‚é
	static SceneManager instance;

	return &instance;
}

void SceneManager::SceneNo(int num)
{
	switch (num)
	{
	case 0:

		printf("SceneNo == 0\n");
		printf("Title\n");

		break;
	case 1:

		printf("SceneNo == 1\n");
		printf("New Game\n");

		break;
	case 2:

		printf("SceneNo == 2\n");
		printf("Game Play\n");

		break;
	case 3:

		printf("SceneNo == 3\n");
		printf("Game Clear \n");

		break;
	default:
		break;
	}


}
