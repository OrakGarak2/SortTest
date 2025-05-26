#include "Sort.h"

#pragma region Sort
void Sort::SetCursorPosition(const int x, const int y)
{
	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };	// static_cast로 int를 SHORT로 변경해서 사용, 
																	// 왜? int를 매개변수로 받는 편이 더 유연하게 사용할 수 있기 때문.
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Sort::MarkVisited(const char mark, const int x, const int y)
{
	SetCursorPosition(x, y);

	cout << mark;
}

void Sort::EraseMark(const int x, const int y)
{
	SetCursorPosition(x, y);
	cout << " ";
}

void Sort::PrintAllData()
{
	for (int i = 0; begin + i != end; i++)
	{
		SetCursorPosition(markCount, i);

		cout << begin[i];
	}
}

void Sort::ErasePrintedData(const int x, const int y, const int index)
{
	SetCursorPosition(x, y);

	for (int i = 0; i < begin[index].size(); i++)
		cout << " ";
}

void Sort::PrintData(const int x, const int y, const int index)
{
	SetCursorPosition(x, y);

	cout << begin[index];
}

void Sort::Swap(const int y1, const int y2, const int p1, const int p2)
{
	Sleep(waitTime);
	
	ErasePrintedData(markCount, y1, p1);
	ErasePrintedData(markCount, y2, p2);
	
	string temp = begin[p1];
	begin[p1] = begin[p2];
	begin[p2] = temp;

	PrintData(markCount, y1, p1);
	PrintData(markCount, y2, p2);
	
	Sleep(waitTime);
}

// 오름차순 정렬일 때
// str1이 str2보다 사전순으로 뒤에 있을 때 true를 반환
// 내림차순 정렬일 때	
// str1이 str2보다 사전순으로 앞에 있을 때 true를 반환
bool Sort::CompareValue(const string str1, const string str2)
{
	return isAscendingOrder ? str1.compare(str2) > 0 : str1.compare(str2) < 0;
}
#pragma endregion

#pragma region Bubble Sort
void BubbleSort::PlaySort()
{
	Sort::PlaySort();

	for (int i = 0; end - i != begin; i++)
	{
		for (int ii = 0; begin + ii != end - i - 1; ii++)
		{
			MarkVisited('>', 0, ii);
			MarkVisited('>', 0, ii + 1);

			if (CompareValue(begin[ii], begin[ii + 1]))
			{
				Swap(ii, ii + 1, ii, ii + 1);
			}

			Sleep(waitTime);
			EraseMark(0, ii);
			EraseMark(0, ii + 1);
		}
	}

	SetCursorPosition(0, static_cast<int>(end - begin));

	cout << "버블 정렬을 완료했습니다." << endl;
}
#pragma endregion

#pragma region Quick Sort
void QuickSort::PlaySort()
{
	Sort::PlaySort();

	RecursiveQuickSort(0, static_cast<int>(end - begin) - 1);

	SetCursorPosition(0, static_cast<int>(end - begin));

	cout << "퀵 정렬을 완료했습니다." << endl;
}

void QuickSort::RecursiveQuickSort(const int low, const int high)
{
	if (low >= high) return;

	int pivot = Partition(low, high);

	// pivot을 기점으로 분할
	RecursiveQuickSort(low, pivot - 1);
	RecursiveQuickSort(pivot + 1, high);
}

// 스왑으로 졍렬을 진행하며, 분할할 부분을 반환
int QuickSort::Partition(const int left, const int right)
{
	int low = left;
	int high = right;
	int pivot = left; // pivot이 부분 배열의 가장 왼쪽을 가리키도록 설정

	// 처음 pivot의 위치와 low, high의 위치를 표시
	MarkVisited('p', 0, pivot);
	MarkVisited('l', 1, low);
	MarkVisited('h', 2, high);

	Sleep(waitTime);

	while (low < high)
	{
		// Swap 조건을 만족하고, high가 low보다 클 때까지만 high--를 반복 
		while (CompareValue(begin[high], begin[pivot]) && low < high) 
		{
			EraseMark(2, high);
			high--;						
			MarkVisited('h', 2, high);

			Sleep(waitTime);
		}

		// Swap 조건을 만족하거나 low랑 pivot이 같고, low가 high보다 작을 때까지만 low++를 반복
		while ((CompareValue(begin[pivot], begin[low]) || pivot == low) && low < high) 
		{
			EraseMark(1, low);
			low++;
			MarkVisited('l', 1, low);

			Sleep(waitTime);
		}

		if(low < high) // 제자리 스왑을 방지하기 위함.
			Swap(low, high, low, high); // low가 가리키는 값이랑 high가 가리키는 값을 스왑
	}

	// pivot이 가리키는 갑과 low가 가리키는 값을 스왑
	Swap(pivot, low, pivot, low);

	EraseMark(0, pivot);
	EraseMark(1, low);
	EraseMark(2, high);

	Sleep(waitTime);

	return low; // low와 high가 교차하는 지점을 반환(low와 같음.)
}
#pragma endregion