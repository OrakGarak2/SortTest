#include "SortTest.h"

int main()
{
	int sortIndex = 0;

	do {
		sortIndex = InputIndex("버블 정렬을 테스트하시려면 0, 퀵 정렬을 테스트하시려면 1, 힙 정렬을 테스트하시려면 2을 입력해주세요. -> ");
	} while (sortIndex < 0 || sortIndex >= static_cast<int>(SortType::TypeCount));

	// AscendingOrder: 오름차순 정렬
	bool isAscendingOrder = InputIndex("내림차순 정렬을 원하시면 0, 오름차순 정렬을 원하시면 1을 입력해주세요. -> ");

	system("cls");
	
	vector<string> wordData = {
		"고양이",
		"나무",
		"바다",
		"사과",
		"다리",
		"아침",
		"자전거",
		"하늘",
		"가방",
		"차표",
	};

	switch (static_cast<SortType>(sortIndex))
	{
	case SortType::Bubble:
		PlayBubbleSort(&wordData, isAscendingOrder);
		break;
	case SortType::Quick:
		PlayQuickSort(&wordData, isAscendingOrder);
		break;
	case SortType::Heap:
		PlayHeapSort(&wordData, isAscendingOrder);
		break;
	default:
		cout << "\n치명적 에러";
		return -1;
	}
}

int InputIndex(string guide)
{
	int index = 0;
	cout << guide;
	cin >> index;
	cout << "\n";

	return index;
}

void PlayBubbleSort(vector<string>* vec, bool isAscendingOrder)
{
	BubbleSort sort(isAscendingOrder, vec->begin(), vec->end());

	sort.PlaySort();
}

void PlayQuickSort(vector<string>* vec, bool isAscendingOrder)
{
	QuickSort sort(isAscendingOrder, vec->begin(), vec->end());

	sort.PlaySort();
}

void PlayHeapSort(vector<string>* vec, bool isAscendingOrder)
{
	HeapSort sort(isAscendingOrder, vec->begin(), vec->end());

	sort.PlaySort();
}