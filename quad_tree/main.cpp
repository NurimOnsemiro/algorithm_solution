/**
 * https://www.algospot.com/judge/problem/read/QUADTREE
 * 결과: 0ms
 */

#include <iostream>
#include <cstdio>
#include <array>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

class game_manager {
public:
	void input_data()
	{
		scanf("%s", arr.data());
	}

	//INFO: 쿼드트리 탐색
	int find_quadtree(int& currIndex)
	{
		//EXAMPLE: x(xwbbw)bbw
		const char head = arr[currIndex];
		currIndex++;

		//INFO: 원자까지 내려온 경우
		if (head == 'w' || head == 'b') {
			return 1;
		}

		const int startPos = currIndex;

		//INFO: x인 경우 (쿼드트리 생성)
		const int upperLeftLength = find_quadtree(currIndex);
		const int upperRightLength = find_quadtree(currIndex);
		const int lowerLeftLength = find_quadtree(currIndex);
		const int lowerRightLength = find_quadtree(currIndex);

		const int upperLength = upperLeftLength + upperRightLength;
		const int lowerLength = lowerLeftLength + lowerRightLength;
		const int lowerStartPos = startPos + upperLength;
		const int newUpperStartPos = startPos + lowerLength;

		//INFO: 길이가 더 긴 쪽을 temp에 넣어서 스왑해야 한다
		if (upperLength > lowerLength) {
			memcpy(&temp[0], &arr[startPos], upperLength);
			memcpy(&arr[startPos], &arr[lowerStartPos], lowerLength);
			memcpy(&arr[newUpperStartPos], &temp[0], upperLength);
		}
		else {
			memcpy(&temp[0], &arr[lowerStartPos], lowerLength);
			memcpy(&arr[newUpperStartPos], &arr[startPos], upperLength);
			memcpy(&arr[startPos], &temp[0], lowerLength);
		}

		//INFO: x를 포함한 전체 길이
		const int totalLength = upperLength + lowerLength + 1;

		return totalLength;
	}

	//INFO: 정답을 계산
	void find_answer()
	{
		int currIndex{ 0 };
		find_quadtree(currIndex);
	}

	void output_data()
	{
		printf("%s\n", arr.data());
	}

	void clear_data()
	{
		memset(arr.data(), 0, sizeof(arr));
	}

private:
	array<char, 1000> arr;
	array<char, 1000> temp;
};

int main() {
	int numTests{ 0 };
	scanf("%d", &numTests);

	game_manager gm;

	while (numTests--) {
		gm.clear_data();
		gm.input_data();
		gm.find_answer();
		gm.output_data();
	}

	return 0;
}