#pragma once
class SceneManager final
{
private:
	SceneManager();
	~SceneManager();

public:
	SceneManager(const SceneManager&) = delete;

	SceneManager& operator = (const SceneManager&) = delete;

	static SceneManager* GetInstance();

	// ƒV[ƒ“Ø‚è‘Ö‚¦w
	void SceneNo(int num);
};

