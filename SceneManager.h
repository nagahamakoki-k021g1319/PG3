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

	// �V�[���؂�ւ�w
	void SceneNo(int num);
};

