// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include "HeapStackExample.h"

using namespace std;

// 2025.02.16
// C++에서는 객체 생성 방법이 두 가지 있습니다.
// StackTest() 함수처럼 객체를 생성한다면, Stack 영역에 객체를 할당한 것으로 함수 내에서만 사용 가능합니다.
// 별도의 소멸자를 호출하지 않았음에도 자동으로 소멸자가 호출됩니다. 
void StackTest()
{
	cout << "*** StackTest Orange orange(500); ***" << endl;
	Orange orange(500);
	orange.ShowPrice();
}

// 2025.02.16
// new 키워드가 동적으로 힙 영역에 메모리를 동적으로 할당합니다. (C의 malloc 과 비슷한 맥락입니다.)
// 일반적으로 동적으로 할당된 메모리는 delete 하기 전까지 힙에 생존합니다.
// 따라서 함수가 종료되어도, 소멸자가 호출되지 않습니다.
void HeapTest()
{
	cout << "*** HeapTest Orange *orange = new Orange(1000); ***" << endl;
	Orange* orange = new Orange(1000);
	orange->ShowPrice();
}

// 2025.02.17
// vector를 이용해서 중복 방지를 하였습니다.
vector<int> AvoidDuplicate(vector<int> arr) {
	vector<int> answer;

	answer.push_back(arr[0]);

	for (int i = 1, j = 0; i < arr.size(); i++)
	{
		if (arr[i] == answer[j])
		{
			continue;
		}
		else
		{
			answer.push_back(arr[i]);
			j++;
		}
	}
	return answer;
}

// 2025.02.18
// 버블 정렬을 하였습니다.
vector<int> BubbleSort(vector<int> arr, int size) {
	int temp;

	for (int i = size - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}

	return arr;
}

int main()
{
	vector<int> previousVector;
	vector<int> afterVector;
	vector<int> finalVector;

	for (int i = 0; i < 6; i++)
	{
		int a;
		cin >> a;
		previousVector.push_back(a);
	}

	afterVector = AvoidDuplicate(previousVector);
	
	for (int i = 0; i < afterVector.size(); i++)
	{
		cout << afterVector[i] << endl;
	}

	finalVector = BubbleSort(afterVector, 5);
	
	for (int i = 0; i < finalVector.size(); i++)
	{
		cout << finalVector[i] << endl;
	}

	return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
