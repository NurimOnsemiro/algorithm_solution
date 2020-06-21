/**
 * https://www.algospot.com/judge/problem/read/FENCE
 * ���: 56ms
 */

#include <iostream>
#include <stack>
#include <array>
#include <algorithm>

using namespace std;

//INFO: ���� ������� �ִ� ũ�� + 1 ��ġ�� ������ �� ����
array<int, 20001> fences;
int numFences{ 0 };

int find_max_size_fence() {
	int maxSquareSize{ 0 };
	stack<int> stk;
	//INFO: ������ ���� ���� numFences + 1 ��° ��ġ�� ��Ÿ�� ���̸� 0���� �����Ѵ�.
	fences[numFences] = 0;
	
	for (int i = 0; i <= numFences; i++) {
		//INFO: ������ ���� �ʰ�, ���ÿ� ����� ��ġ�� ���̰� ���� ���̺��� Ŭ ���
		while (!stk.empty() && fences[stk.top()] >= fences[i]) {
			int pos = stk.top();
			stk.pop();
			//INFO: ������ ����ٸ�, i�� �ʺ� �ȴ�. �ƴ϶�� i - ���߿� ����� ��ġ -1
			int width = stk.empty() ? i : (i - stk.top() - 1);
			int squareSize = width * fences[pos];
			maxSquareSize = max(maxSquareSize, squareSize);
		}

		stk.push(i);
	}

	return maxSquareSize;
}

int main() {
	int numTests;
	scanf("%d", &numTests);

	while (numTests > 0) {
		scanf("%d", &numFences);
		for (int i = 0; i < numFences; i++) {
			scanf("%d", &fences[i]);
		}

		int maxSquareSize{ find_max_size_fence() };
		printf("%d\n", maxSquareSize);

		numTests--;
	}
	
	return 0;
}