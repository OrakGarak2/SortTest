#include "Sort.h"

void Sort::SetCursorPosition(int x, int y)
{
	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };	// static_cast로 int를 SHORT로 변경해서 사용, 
																	// 왜? int를 매개변수로 받는 편이 더 유연하게 사용할 수 있기 때문.
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Sort::Swap(vector<string>* vec, const int p1, const int p2)
{

}

bool Sort::ShouldSwapValue(string* str01, string* str02)
{
	
}

void BubbleSort::PlaySort()
{
	
}

void QuickSort::PlaySort()
{
	
}

void HeapSort::PlaySort()
{
	
}