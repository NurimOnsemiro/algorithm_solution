/**
 * https://www.algospot.com/judge/problem/read/FENCE
 * 결과: 56ms
 */

#include <iostream>
#include <stack>
#include <array>
#include <algorithm>

using namespace std;

//INFO: 스택 사용으로 최대 크기 + 1 위치를 접근할 수 있음
array<int, 20001> fences;
int numFences{ 0 };

int find_max_size_fence() {
	int maxSquareSize{ 0 };
	stack<int> stk;
	//INFO: 스택을 비우기 위해 numFences + 1 번째 위치에 울타리 높이를 0으로 설정한다.
	fences[numFences] = 0;
	
	for (int i = 0; i <= numFences; i++) {
		//INFO: 스택이 비지 않고, 스택에 저장된 위치의 높이가 현재 높이보다 클 경우
		while (!stk.empty() && fences[stk.top()] >= fences[i]) {
			int pos = stk.top();
			stk.pop();
			//INFO: 스택이 비었다면, i가 너비가 된다. 아니라면 i - 나중에 저장된 위치 -1
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