#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <windows.h>

using namespace std;

enum class SortType {
	Bubble,
	Quick,
	Heap,
	/// <summary>
	/// 몇 개의 enum이 있는지 새는 용도
	/// </summary>
	TypeCount
};

class Sort
{
protected:
	// AscendingOrder: 오름차순 정렬
	bool isAscendingOrder;
	// 방문한 곳을 표시하는 마크가 한 번에 몇 개까지 있을 수 있는지 알려주는 변수
	int markCount = 0;
	
	vector<string>::iterator begin;
	vector<string>::iterator end;

	int waitTime = 500;

public:
	Sort(bool isAscendingOrder, vector<string>::iterator begin, vector<string>::iterator end)
	{
		this->isAscendingOrder = isAscendingOrder;
		this->begin = begin;
		this->end = end;
	}

	virtual void PlaySort()
	{
		PrintAllData();
	}

	// (x, y) 위치로 콘솔 커서 이동
	void SetCursorPosition(const int x, const int y);
	
	/// <summary>
	/// 방문한 곳 표시
	/// </summary>
	/// <param name="mark">표시할 마크</param>
	/// <param name="x">표시할 마크의 x좌표</param>
	/// <param name="y">표시할 마크의 y좌표</param>
	void MarkVisited(const char mark, const int x, const int y);

	void EraseMark(const int x, const int y);

	void PrintAllData();

	/// <summary>
	/// 출력되어 있는 문자열을 지우는 함수
	/// </summary>
	/// <param name="x">커서의 x좌표</param>
	/// <param name="y">커서의 y좌표</param>
	/// <param name="index">vector의 index, 현재는 y와 동일하지만 후에 달라질 수도 있으므로 매개변수를 따로 놓음.</param>
	void ErasePrintedData(const int x, const int y, const int index);

	/// <summary>
	/// 출력되어 있는 문자열을 지우는 함수
	/// </summary>
	/// <param name="x">커서의 x좌표</param>
	/// <param name="y">커서의 y좌표</param>
	/// <param name="index">vector의 index, 현재는 y와 동일하지만 후에 달라질 수도 있으므로 매개변수를 따로 놓음.</param>
	void PrintData(const int x, const int y, const int index);

	void Swap(const int y1, const int y2, const int p1, const int p2);

	bool ShouldSwapValue(const string frontStr, const string backStr);
};

class BubbleSort : public Sort
{
public:
	BubbleSort(bool isAscendingOrder, vector<string>::iterator begin, vector<string>::iterator end) 
		: Sort(isAscendingOrder, begin, end) 
	{
		markCount = 1;
	}

	void PlaySort() override;
};

class QuickSort : Sort
{
public:
	QuickSort(bool isAscendingOrder, vector<string>::iterator begin, vector<string>::iterator end) 
		: Sort(isAscendingOrder, begin, end) 
	{
		markCount = 3;
	}

	void PlaySort() override;
};

class HeapSort : Sort
{
public:
	HeapSort(bool isAscendingOrder, vector<string>::iterator begin, vector<string>::iterator end)
		: Sort(isAscendingOrder, begin, end) 
	{
		markCount = 2;
	}

	void PlaySort() override;
};