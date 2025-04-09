#include "Sort.h"

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
}

bool Sort::ShouldSwapValue(const string frontStr, const string backStr)
{
	if(isAscendingOrder) // 오름차순 정렬일 때
	{
		// 앞에 있는 문자열이 뒤에 있는 문자열보다
		// 사전순으로 뒤에 있을 때 vector에서의 위치를 바꿔야 함(true를 반환).
		return frontStr.compare(backStr) > 0;
	}
	else				// 내림차순 정렬일 때
	{
		// 앞에 있는 문자열이 뒤에 있는 문자열보다
		// 사전순으로 앞에 있을 때 vector에서의 위치를 바꿔야 함(true를 반환).
		return frontStr.compare(backStr) < 0;
	}
}

void BubbleSort::PlaySort()
{
	Sort::PlaySort();

	int i = 0;

	for (i = 0; end - i != begin; i++)
	{
		for (int ii = 0; begin + ii != end - i - 1; ii++)
		{
			MarkVisited('>', 0, ii);
			MarkVisited('>', 0, ii + 1);

			if (ShouldSwapValue(begin[ii], begin[ii + 1]))
			{
				Swap(ii, ii + 1, ii, ii + 1);
			}

			Sleep(waitTime);
			EraseMark(0, ii);
			EraseMark(0, ii + 1);
		}
	}

	SetCursorPosition(0, i);

	cout << "버블 정렬을 완료했습니다." << endl;
}

void QuickSort::PlaySort()
{
	Sort::PlaySort();
}

void HeapSort::PlaySort()
{
	Sort::PlaySort();
}