/*
*	https://www.algospot.com/judge/problem/read/QUADTREE
*/

#include <iostream>
#include <array>
#include <string>
#include <string.h>

using namespace std;

class game_manager {
public:
	void input_data()
	{
		cin >> arr;
	}

	//INFO: x를 기준으로 앞의 두 개와 뒤의 두개를 교환해야 한다
	//@param currIndex: 검사를 시작할 인덱스
	int calculate_answer(const int& currIndex)
	{
		//EXAMPLE: (xwbbw), (xwb(xwbwb)b)

		//INFO: 쿼드트리로 색상이 나눠지는 경우
		if (arr[currIndex] == 'x') {
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
				if (arr[pos] == 'x') {
					//INFO: foo함수는 다음 검사할 위치만큼 이동할 칸 수를 반환한다
					//EXAMPLE: xwwbb인 경우 5를 반환해야 그 다음 문자를 검사할 수 있다
					pos += calculate_answer(pos);
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
				char temp[1000];
				const int upImageLength{ downStartPos - upStartPos };
				const int downImageLength{ downEndPos - downStartPos };
				const int newDownStartPos{ upStartPos + downImageLength };
				memcpy(temp, &arr[upStartPos], upImageLength);
				memcpy(&arr[upStartPos], &arr[downStartPos], downImageLength);
				memcpy(&arr[newDownStartPos], &temp[0], upImageLength);
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

	string reverse_char(int& currIndex)
	{
		char head = arr[currIndex];
		currIndex++;

		if (head == 'b' || head == 'w') {
			return string(1, head);
		}

		string upperLeft = reverse_char(currIndex);
		string upperRight = reverse_char(currIndex);
		string lowerLeft = reverse_char(currIndex);
		string lowerRight = reverse_char(currIndex);

		return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
	}

	void check_param_valid()
	{
		if (strlen(arr) > 1000) {
			exit(-1);
		}
	}

	string reverse2(string::iterator& it)
	{
		char head = *it;
		++it;

		if (head == 'b' || head == 'w') {
			return string(1, head);
		}

		string upperLeft = reverse2(it);
		string upperRight = reverse2(it);
		string lowerLeft = reverse2(it);
		string lowerRight = reverse2(it);

		return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
	}

	void calculate_answer2()
	{
		/*str = string(arr);
		auto it = str.begin();
		str = reverse2(it);*/
		int currIndex{ 0 };
		str = reverse_char(currIndex);
	}

	void output_data()
	{
		cout << str << endl;
	}

	void clear_data()
	{
		str.clear();
		memset(arr, 0, sizeof(arr));
	}

private:
	char arr[1000]{ 0 };
	string str;
};

int main() {
	int numTests{ 0 };
	cin >> numTests;

	game_manager gm;

	while (numTests--) {
		gm.clear_data();
		gm.input_data();
		gm.check_param_valid();
		gm.calculate_answer2();
		gm.output_data();
	}

	return 0;
}