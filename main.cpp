#include <stdio.h>
#include <iostream>
#include <string>

template <typename T>
struct Cell
{
	//値
	T value;
	Cell* prev;
	Cell* next;

	//コンストラクタ
	Cell()
	{
		//ダミーノードを用意
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

	//一番前に追加
	void PushFront(T value_)
	{
		Cell<T>* cur = dummy;
		Add(value_, cur);
	}

	/// <summary>
	/// 一番後ろに追加
	/// </summary>
	/// <param name="value_">値</param>
	void PushBack(T value_)
	{
		Cell<T>* cur = dummy->prev;
		Add(value_, cur);
	}

	/// <summary>
	/// 任意の場所に追加
	/// </summary>
	/// <param name="value_">値</param>
	/// <param name="num">追加する場所(0~)</param>
	void Insert(T value_, int num)
	{
		Cell<T>* tmpCell = nullptr;
		tmpCell = dummy;

		//任意の場所まで移動
		for (int i = 0; i < num; i++)
		{
			tmpCell = tmpCell->next;
		}

		//追加
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
	/// 任意の場所の値を変更
	/// </summary>
	/// <param name="value_">値</param>
	/// <param name="num">変更する場所(0~)</param>
	bool ChangeValue(T value_, int num)
	{

		if (num < 0 || num>size)
		{
			return false;
		}

		Cell<T>* tmpCell = nullptr;
		tmpCell = dummy;

		//任意の場所まで移動
		for (int i = 0; i < num + 1; i++)
		{
			tmpCell = tmpCell->next;
		}

		//変更
		tmpCell->value = value_;

		return true;

	}

	/// <summary>
	/// 一覧表示
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

		//任意の場所まで移動
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

	//ダミー
	Cell<T>* dummy;

	int size;

	//セルが指した後ろに追加
	void Add(T v, Cell<T>* node)
	{
		//新しいセルを生成
		Cell<T>* newNode = new Cell<T>(v, node, node->next);
		node->next->prev = newNode;
		node->next = newNode;
		node = newNode;
		size++;
	}

	Cell<T>* GetCell(int num)
	{
		Cell<T>* tmpCell = dummy;

		//任意の場所まで移動
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

	//要素の操作の操作番号
	int SceneNo = 0;

	//要素の表示の操作番号
	int displaySceneNo = 0;


	while (true)
	{
		std::cout << "[要素の操作]" << std::endl;
		std::cout << "1.要素の表示" << std::endl;
		std::cout << "2.要素の挿入" << std::endl;
		std::cout << "3.要素の編集" << std::endl;
		std::cout << "4.要素の削除" << std::endl;
		std::cout << "----------------------------------" << std::endl;
		std::cout << "操作を選択してください" << std::endl;

		if (SceneNo == 0) {
			//操作番号を取得
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
	std::cout << "[要素の表示]" << std::endl;
	std::cout << "1.要素の一覧表示" << std::endl;
	std::cout << "2.順番を指定して要素を表示" << std::endl;
	std::cout << "9.要素操作に戻る" << std::endl;
	std::cout << std::endl;
	std::cout << "操作を選択してください" << std::endl;

	//操作番号を取得
	std::cin >> displaySceneNo;

	if (displaySceneNo == 1) {
		std::cout << "[要素の一覧表示]" << std::endl;

		//一覧表示
		list.Dump();

		std::cout << "要素数:" << list.Size() << std::endl;
	}
	else if (displaySceneNo == 2) {
		std::cout << "[順番を指定して要素を表示]" << std::endl;
		std::cout << "表示したい要素の順番を指定してください。" << std::endl;

		//指定する番号を取得
		int getNo;
		std::cin >> getNo;
		std::cout << std::endl;

		//指定して表示
		list.SpecifyElement(getNo);
	}
	else if (displaySceneNo == 9) {
		SceneNo = 0;
	}


	//要素操作に戻らなかったら
	if (displaySceneNo == 1 || displaySceneNo == 2)
	{
		std::cout << std::endl;
		std::cout << "----------------------------------" << std::endl;
		std::cout << "1.要素の表示に戻る" << std::endl;
		std::cout << "2.要素の操作に戻る" << std::endl;

		//操作番号を取得
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
	std::cout << "[リスト要素の挿入]" << std::endl;
	std::cout << std::endl;
	std::cout << "要素を追加場所を指定してください。最後尾に追加する場合は何も入力しないでください。" << std::endl;

	std::string insertNo;
	while (std::getchar() != '\n');

	std::getline(std::cin, insertNo);

	if (insertNo == "")
	{
		std::cout << "追加する要素の値を入力してください" << std::endl;
		T element{};

		std::cin >> element;

		list.PushBack(element);

		std::cout << "要素" << element << "が" << "最後尾に挿入されました" << std::endl;
	}
	else
	{
		int index = std::atoi(insertNo.c_str());

		std::cout << "追加する要素の値を入力してください" << std::endl;
		T element{};

		std::cin >> element;

		list.Insert(element, index);

		std::cout << "要素" << element << "が" << index << "番目に挿入されました" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "9.要素操作に戻る" << std::endl;

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
	std::cout << "[要素の編集]" << std::endl;
	std::cout << std::endl;
	std::cout << "編集したい要素の番号を入力してください" << std::endl;

	int elmtNo;
	std::cin >> elmtNo;
	std::cout << std::endl;

	if (list.Search(elmtNo))
	{
		std::cout << elmtNo << "番目の要素の変更する値を入力してください。" << std::endl;

		T changeElement{};
		std::cin >> changeElement;

		list.ChangeValue(changeElement, elmtNo);
		std::cout << std::endl;

		std::cout << elmtNo << "番目の要素の値が" << '"' << changeElement << '"' << "に変更されました" << std::endl;
	}
	else
	{
		std::cout << elmtNo << "番目の要素のが見つかりませんでした。" << std::endl;
	}


	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "9.要素操作に戻る" << std::endl;

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
	std::cout << "[要素の削除]" << std::endl;
	std::cout << std::endl;
	std::cout << "削除したい要素の番号を指定してください" << std::endl;

	int elmtNo;
	std::cin >> elmtNo;
	std::cout << std::endl;

	if (list.Search(elmtNo))
	{
		std::cout << elmtNo << "番目の要素" << '"' << list.GetElement(elmtNo) << '"' << "削除しました" << std::endl;

		list.Delete(elmtNo);

		std::cout << std::endl;
	}
	else
	{
		std::cout << elmtNo << "番目の要素のが見つかりませんでした。" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "9.要素操作に戻る" << std::endl;

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

