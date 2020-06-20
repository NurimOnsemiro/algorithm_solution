/**
 * https://www.algospot.com/judge/problem/read/QUADTREE
 * ���: 0ms
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

	//INFO: ����Ʈ�� Ž��
	int find_quadtree(int& currIndex)
	{
		//EXAMPLE: x(xwbbw)bbw
		const char head = arr[currIndex];
		currIndex++;

		//INFO: ���ڱ��� ������ ���
		if (head == 'w' || head == 'b') {
			return 1;
		}

		const int startPos = currIndex;

		//INFO: x�� ��� (����Ʈ�� ����)
		const int upperLeftLength = find_quadtree(currIndex);
		const int upperRightLength = find_quadtree(currIndex);
		const int lowerLeftLength = find_quadtree(currIndex);
		const int lowerRightLength = find_quadtree(currIndex);

		const int upperLength = upperLeftLength + upperRightLength;
		const int lowerLength = lowerLeftLength + lowerRightLength;
		const int lowerStartPos = startPos + upperLength;
		const int newUpperStartPos = startPos + lowerLength;

		//INFO: ���̰� �� �� ���� temp�� �־ �����ؾ� �Ѵ�
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

		//INFO: x�� ������ ��ü ����
		const int totalLength = upperLength + lowerLength + 1;

		return totalLength;
	}

	//INFO: ������ ���
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