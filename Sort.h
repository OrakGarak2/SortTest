#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <windows.h>

using namespace std;

class Sort
{
protected:
	// AscendingOrder: 오름차순 정렬
	bool isAscendingOrder;

public:
	Sort(bool isAscendingOrder)
	{
		this->isAscendingOrder = isAscendingOrder;
	}

	virtual void PlaySort() = 0;

	// (x, y) 위치로 콘솔 커서 이동
	void SetCursorPosition(int x, int y);

	void Swap(vector<string>* vec, const int p1, const int p2);

	bool ShouldSwapValue(string* str01, string* str02);
};

class BubbleSort : public Sort
{
public:
	BubbleSort(bool isAscendingOrder) : Sort(isAscendingOrder) {}

	void PlaySort() override;
};

class QuickSort : Sort
{
public:
	QuickSort(bool isAscendingOrder) : Sort(isAscendingOrder) {}

	void PlaySort() override;
};

class HeapSort : Sort
{
public:
	HeapSort(bool isAscendingOrder) : Sort(isAscendingOrder) {}

	void PlaySort() override;
};