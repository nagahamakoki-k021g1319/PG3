#include <stdio.h>
#include <iostream>
#include <string>

template <typename T>
struct Cell
{
	//�l
	T value;
	Cell* prev;
	Cell* next;

	//�R���X�g���N�^
	Cell()
	{
		//�_�~�[�m�[�h��p��
		prev = this;
		next = this;
	}

	Cell(T value_, Cell* prev_, Cell* next_)
	{
		value = value_;
		prev = prev_;
		next = next_;

	}
};

template <class T>
class List
{
public:
	List()
	{
		dummy = new Cell<T>();

		size = 0;
	}

	~List()
	{
		//Clear();
	}

	//��ԑO�ɒǉ�
	void PushFront(T value_)
	{
		Cell<T>* cur = dummy;
		Add(value_, cur);
	}

	/// <summary>
	/// ��Ԍ��ɒǉ�
	/// </summary>
	/// <param name="value_">�l</param>
	void PushBack(T value_)
	{
		Cell<T>* cur = dummy->prev;
		Add(value_, cur);
	}

	/// <summary>
	/// �C�ӂ̏ꏊ�ɒǉ�
	/// </summary>
	/// <param name="value_">�l</param>
	/// <param name="num">�ǉ�����ꏊ(0~)</param>
	void Insert(T value_, int num)
	{
		Cell<T>* tmpCell = nullptr;
		tmpCell = dummy;

		//�C�ӂ̏ꏊ�܂ňړ�
		for (int i = 0; i < num; i++)
		{
			tmpCell = tmpCell->next;
		}

		//�ǉ�
		Add(value_, tmpCell);
	}

	//
	bool Search(int num)
	{
		if (num < 0 || num>size)
		{
			return false;
		}

		return true;
	}

	/// <summary>
	/// �C�ӂ̏ꏊ�̒l��ύX
	/// </summary>
	/// <param name="value_">�l</param>
	/// <param name="num">�ύX����ꏊ(0~)</param>
	bool ChangeValue(T value_, int num)
	{

		if (num < 0 || num>size)
		{
			return false;
		}

		Cell<T>* tmpCell = nullptr;
		tmpCell = dummy;

		//�C�ӂ̏ꏊ�܂ňړ�
		for (int i = 0; i < num + 1; i++)
		{
			tmpCell = tmpCell->next;
		}

		//�ύX
		tmpCell->value = value_;

		return true;

	}

	/// <summary>
	/// �ꗗ�\��
	/// </summary>
	void Dump()
	{
		Cell<T>* ptr = dummy->next;
		int index = 0;
		for (int i = 0; i < size - 1; i++)
		{
			std::cout << ' ' << index << ':' << '"' << ptr->value << '"' << ',' << std::endl;
			ptr = ptr->next;
			index++;
		}
		std::cout << ' ' << index << ':' << '"' << ptr->value << '"' << std::endl;

	}

	void SpecifyElement(int num)
	{
		Cell<T>* tmpCell = nullptr;
		tmpCell = dummy;

		int index = -1;

		for (int i = 0; i < num + 1; i++)
		{
			tmpCell = tmpCell->next;
			index++;
		}

		std::cout << index << ':' << tmpCell->value << '\n';
	}

	T GetElement(int num)
	{
		Cell<T>* tmpCell = nullptr;
		tmpCell = dummy;

		for (int i = 0; i < num + 1; i++)
		{
			tmpCell = tmpCell->next;
		}

		return tmpCell->value;
	}

	int Size()
	{
		return size;
	}

	bool Delete(int num)
	{
		if (num < 0 || num>size)
		{
			return false;
		}

		Cell<T>* tmpCell = nullptr;
		tmpCell = dummy;

		//�C�ӂ̏ꏊ�܂ňړ�
		for (int i = 0; i < num + 1; i++)
		{
			tmpCell = tmpCell->next;
		}

		tmpCell->prev->next = tmpCell->next;
		tmpCell->next->prev = tmpCell->next;

		delete tmpCell;

		size--;

		return true;
	}


	void Sort(bool flag = true)
	{
		Cell<T>* tmpCell = nullptr;

		Cell<T>* tmpCell2 = nullptr;

		for (int i = 0; i < (size - 1); i++)
		{
			tmpCell = GetCell(i);

			for (int j = (size - 1); j > i; j--)
			{
				tmpCell2 = GetCell(j);
				if (flag)
				{
					if (tmpCell2->value < tmpCell2->prev->value)
					{
						T value = tmpCell2->value;
						ChangeValue(tmpCell2->prev->value, j);
						ChangeValue(value, j - 1);
					}
				}
				else
				{
					if (tmpCell2->value > tmpCell2->prev->value)
					{
						T value = tmpCell2->value;
						ChangeValue(tmpCell2->prev->value, j);
						ChangeValue(value, j - 1);
					}
				}
			}
		}
	}

private:

	//�_�~�[
	Cell<T>* dummy;

	int size;

	//�Z�����w�������ɒǉ�
	void Add(T v, Cell<T>* node)
	{
		//�V�����Z���𐶐�
		Cell<T>* newNode = new Cell<T>(v, node, node->next);
		node->next->prev = newNode;
		node->next = newNode;
		node = newNode;
		size++;
	}

	Cell<T>* GetCell(int num)
	{
		Cell<T>* tmpCell = dummy;

		//�C�ӂ̏ꏊ�܂ňړ�
		for (int i = 0; i < num + 1; i++)
		{
			tmpCell = tmpCell->next;
		}

		return tmpCell;
	}
};

template<typename T>
void Display(List<T>& list, int& SceneNo, int& displaySceneNo);

template<typename T>
void Insert(List<T>& list, int& SceneNo);

template<typename T>
void Edit(List<T>& list, int& SceneNo);

template<typename T>
void Delete(List<T>& list, int& SceneNo);

int main()
{
	List<std::string> list;

	//�v�f�̑���̑���ԍ�
	int SceneNo = 0;

	//�v�f�̕\���̑���ԍ�
	int displaySceneNo = 0;


	while (true)
	{
		std::cout << "[�v�f�̑���]" << std::endl;
		std::cout << "1.�v�f�̕\��" << std::endl;
		std::cout << "2.�v�f�̑}��" << std::endl;
		std::cout << "3.�v�f�̕ҏW" << std::endl;
		std::cout << "4.�v�f�̍폜" << std::endl;
		std::cout << "----------------------------------" << std::endl;
		std::cout << "�����I�����Ă�������" << std::endl;

		if (SceneNo == 0) {
			//����ԍ����擾
			std::cin >> SceneNo;
		}

		if (SceneNo == 1) {
			Display(list, SceneNo, displaySceneNo);
		}
		else if (SceneNo == 2) {
			Insert(list, SceneNo);
		}
		else if (SceneNo == 3) {
			Edit(list, SceneNo);
		}
		else if (SceneNo == 4) {
			Delete(list, SceneNo);
		}
	}

	return 0;
}

template<typename T>
void Display(List<T>& list, int& SceneNo, int& displaySceneNo)
{
	std::cout << "[�v�f�̕\��]" << std::endl;
	std::cout << "1.�v�f�̈ꗗ�\��" << std::endl;
	std::cout << "2.���Ԃ��w�肵�ėv�f��\��" << std::endl;
	std::cout << "9.�v�f����ɖ߂�" << std::endl;
	std::cout << std::endl;
	std::cout << "�����I�����Ă�������" << std::endl;

	//����ԍ����擾
	std::cin >> displaySceneNo;

	if (displaySceneNo == 1) {
		std::cout << "[�v�f�̈ꗗ�\��]" << std::endl;

		//�ꗗ�\��
		list.Dump();

		std::cout << "�v�f��:" << list.Size() << std::endl;
	}
	else if (displaySceneNo == 2) {
		std::cout << "[���Ԃ��w�肵�ėv�f��\��]" << std::endl;
		std::cout << "�\���������v�f�̏��Ԃ��w�肵�Ă��������B" << std::endl;

		//�w�肷��ԍ����擾
		int getNo;
		std::cin >> getNo;
		std::cout << std::endl;

		//�w�肵�ĕ\��
		list.SpecifyElement(getNo);
	}
	else if (displaySceneNo == 9) {
		SceneNo = 0;
	}


	//�v�f����ɖ߂�Ȃ�������
	if (displaySceneNo == 1 || displaySceneNo == 2)
	{
		std::cout << std::endl;
		std::cout << "----------------------------------" << std::endl;
		std::cout << "1.�v�f�̕\���ɖ߂�" << std::endl;
		std::cout << "2.�v�f�̑���ɖ߂�" << std::endl;

		//����ԍ����擾
		std::cin >> displaySceneNo;

		if (displaySceneNo == 1) {
			SceneNo = 1;
		}
		else if (displaySceneNo == 2) {
			SceneNo = 2;
		}
	}
}

template<typename T>
void Insert(List<T>& list, int& SceneNo)
{
	std::cout << "[���X�g�v�f�̑}��]" << std::endl;
	std::cout << std::endl;
	std::cout << "�v�f��ǉ��ꏊ���w�肵�Ă��������B�Ō���ɒǉ�����ꍇ�͉������͂��Ȃ��ł��������B" << std::endl;

	std::string insertNo;
	while (std::getchar() != '\n');

	std::getline(std::cin, insertNo);

	if (insertNo == "")
	{
		std::cout << "�ǉ�����v�f�̒l����͂��Ă�������" << std::endl;
		T element{};

		std::cin >> element;

		list.PushBack(element);

		std::cout << "�v�f" << element << "��" << "�Ō���ɑ}������܂���" << std::endl;
	}
	else
	{
		int index = std::atoi(insertNo.c_str());

		std::cout << "�ǉ�����v�f�̒l����͂��Ă�������" << std::endl;
		T element{};

		std::cin >> element;

		list.Insert(element, index);

		std::cout << "�v�f" << element << "��" << index << "�Ԗڂɑ}������܂���" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "9.�v�f����ɖ߂�" << std::endl;

	std::cin >> SceneNo;

	if (SceneNo == 9)
	{
		SceneNo = 0;
	}
	else
	{
		SceneNo = 2;
	}
}

template<typename T>
void Edit(List<T>& list, int& SceneNo)
{
	std::cout << "[�v�f�̕ҏW]" << std::endl;
	std::cout << std::endl;
	std::cout << "�ҏW�������v�f�̔ԍ�����͂��Ă�������" << std::endl;

	int elmtNo;
	std::cin >> elmtNo;
	std::cout << std::endl;

	if (list.Search(elmtNo))
	{
		std::cout << elmtNo << "�Ԗڂ̗v�f�̕ύX����l����͂��Ă��������B" << std::endl;

		T changeElement{};
		std::cin >> changeElement;

		list.ChangeValue(changeElement, elmtNo);
		std::cout << std::endl;

		std::cout << elmtNo << "�Ԗڂ̗v�f�̒l��" << '"' << changeElement << '"' << "�ɕύX����܂���" << std::endl;
	}
	else
	{
		std::cout << elmtNo << "�Ԗڂ̗v�f�̂�������܂���ł����B" << std::endl;
	}


	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "9.�v�f����ɖ߂�" << std::endl;

	std::cin >> SceneNo;

	if (SceneNo == 9)
	{
		SceneNo = 0;
	}
	else
	{
		SceneNo = 3;
	}

}

template<typename T>
void Delete(List<T>& list, int& SceneNo)
{
	std::cout << "[�v�f�̍폜]" << std::endl;
	std::cout << std::endl;
	std::cout << "�폜�������v�f�̔ԍ����w�肵�Ă�������" << std::endl;

	int elmtNo;
	std::cin >> elmtNo;
	std::cout << std::endl;

	if (list.Search(elmtNo))
	{
		std::cout << elmtNo << "�Ԗڂ̗v�f" << '"' << list.GetElement(elmtNo) << '"' << "�폜���܂���" << std::endl;

		list.Delete(elmtNo);

		std::cout << std::endl;
	}
	else
	{
		std::cout << elmtNo << "�Ԗڂ̗v�f�̂�������܂���ł����B" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "9.�v�f����ɖ߂�" << std::endl;

	std::cin >> SceneNo;

	if (SceneNo == 9)
	{
		SceneNo = 0;
	}
	else
	{
		SceneNo = 4;
	}
}

