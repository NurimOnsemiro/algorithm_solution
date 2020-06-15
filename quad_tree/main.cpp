/*
*	https://www.algospot.com/judge/problem/read/QUADTREE
*/

#include <iostream>
#include <array>
#include <string>
#include <cstring>

using namespace std;

//INFO: x를 기준으로 앞의 두 개와 뒤의 두개를 교환해야 한다
int foo(std::string& str, const int& currIndex) {
	//EXAMPLE: (xwbbw), (xwb(xwbwb)b)

	//INFO: 쿼드트리로 색상이 나눠지는 경우
	if (str[currIndex] == 'x') {
		//INFO: 현재까지 검사한 칸의 수
		int cnt{ 0 };
		//INFO: x 다음부터 같은 레벨의 네 칸을 조사해야 한다
		int pos = currIndex + 1;

		//INFO: 상단 이미지 시작 위치
		const int upStartPos{ pos };
		//INFO: 하단 이미지 시작 위치
		int downStartPos{ 0 };
		//INFO: 하단 이미지 마지막 위치
		int downEndPos{ 0 };

		int totalLength{ 0 };

		while (cnt < 4) {
			//INFO: 또 쿼드트리가 생성되는 경우
			if (str[pos] == 'x') {
				//INFO: func함수는 다음 검사할 위치만큼 이동할 칸 수를 반환한다
				//EXAMPLE: xwwbb인 경우 5를 반환해야 그 다음 문자를 검사할 수 있다
				pos += foo(str, pos);
			}
			//INFO: 일반 색상인 경우
			else {
				pos++;
			}

			//INFO: 쿼드트리에서 현재까지 처리한 개수
			cnt++;

			//INFO: 상단 이미지가 끝난 시점
			if (cnt == 2) {
				downStartPos = pos;
			}
			//INFO: 하단 이미지가 끝난 시점
			else if (cnt == 4) {
				downEndPos = pos;
			}
		}

		{//INFO: 상단 이미지와 하단 이미지를 교환한다
			std::string temp;
			int upImageLength{ downStartPos - upStartPos };
			int downImageLength{ downEndPos - downStartPos };
			int newDownStartPos{ upStartPos + downImageLength };
			temp = str.substr(upStartPos, upImageLength);
			memcpy(&str[upStartPos], &str[downStartPos], downImageLength);
			memcpy(&str[newDownStartPos], &temp[0], upImageLength);
		}

		//INFO: x를 포함한 전체 문자 개수
		totalLength = (downEndPos - upStartPos) + 1;
		return totalLength;
	}
	//INFO: 전부 같은 색상인 경우 (흰색 또는 검정색)
	else {
		return 1;
	}
}

int main() {
	int numTests{ 0 };
	cin >> numTests;

	std::string str;

	while (numTests--) {
		str.clear();

		cin >> str;
		foo(str, 0);
		printf("%s\n", str.c_str());
	}

	return 0;
}