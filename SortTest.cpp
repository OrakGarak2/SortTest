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

	ViewCursur(FALSE);
	
	vector<string> wordData = {
		"고양이",
		"가방",
		"나무",
		"바다",
		"사과",
		"다리",
		"아침",
		"자전거",
		"하늘",
		"차표",
	};

	switch (static_cast<SortType>(sortIndex))
	{
	case SortType::Bubble:
	{
		BubbleSort sort(isAscendingOrder, wordData.begin(), wordData.end());
		PlaySort(&sort);
		break;
	}
	case SortType::Quick:
	{
		QuickSort sort(isAscendingOrder, wordData.begin(), wordData.end());
		PlaySort(&sort);
		break;
	}
	case SortType::Heap:
	{
		HeapSort sort(isAscendingOrder, wordData.begin(), wordData.end());
		PlaySort(&sort);
		break;
	}
	default:
		cout << "\n치명적 에러";
		return -1;
	}

	return 0;
}

int InputIndex(string guide)
{
	int index = 0;
	cout << guide;
	cin >> index;
	cout << "\n";

	return index;
}

void ViewCursur(BOOL isShowingCursur)
{
	// CONSOLE_CURSOR_INFO라는 구조체를 초기화
	// 첫 번째 변수인 dwSize는 커서의 굵기를 의미하며, 그냥 1로 초기화
	// 두 번째 변수인 bVisible은 커서의 노출 여부를 나타내며 isShowingCursur으로 초기화
	CONSOLE_CURSOR_INFO cursur = { 1, isShowingCursur };

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursur);
}

void PlaySort(Sort* sort)
{
	chrono::system_clock::time_point start = chrono::system_clock::now();

	sort->PlaySort();

	chrono::duration<double>sec = chrono::system_clock::now() - start;

	cout << sec.count() << "초만큼 걸렸습니다." << endl;
}