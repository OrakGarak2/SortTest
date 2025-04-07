#include "SortTest.h"

int main()
{
	int sortIndex = InputIndex("버블 정렬을 테스트하시려면 1, 퀵 정렬을 테스트하시려면 2, 힙 정렬을 테스트하시려면 3을 입력해주세요. -> ");

	// AscendingOrder: 오름차순 정렬
	bool isAscendingOrder = InputIndex("내림차순 정렬을 원하시면 0, 오름차순 정렬을 원하시면 1을 입력해주세요. -> ");

	system("cls");
	
	vector<string> wordData = {
		"고양이",
		"나무",
		"바다",
		"가방",
		"사과",
		"다리",
		"아침",
		"자전거",
		"하늘",
		"차표",
	};

	if (sortIndex < 2) 
	{
		PlayBubbleSort(&wordData, isAscendingOrder);
	}
	else if (sortIndex == 2)
	{
		PlayQuickSort(&wordData, isAscendingOrder);
	}
	else // sortIndex가 2보다 클 때
	{
		PlayHeapSort(&wordData, isAscendingOrder);
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
	BubbleSort sort(isAscendingOrder);

	sort.PlaySort();
}

void PlayQuickSort(vector<string>* vec, bool isAscendingOrder)
{
	QuickSort sort(isAscendingOrder);

	sort.PlaySort();
}

void PlayHeapSort(vector<string>* vec, bool isAscendingOrder)
{
	HeapSort sort(isAscendingOrder);

	sort.PlaySort();
}