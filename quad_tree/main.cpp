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

	//INFO: x�� �������� ���� �� ���� ���� �ΰ��� ��ȯ�ؾ� �Ѵ�
	//@param currIndex: �˻縦 ������ �ε���
	int calculate_answer(const int& currIndex)
	{
		//EXAMPLE: (xwbbw), (xwb(xwbwb)b)

		//INFO: ����Ʈ���� ������ �������� ���
		if (arr[currIndex] == 'x') {
			//INFO: ������� �˻��� ĭ�� ��
			int cnt{ 0 };
			//INFO: x �������� ���� ������ �� ĭ�� �����ؾ� �Ѵ�
			int pos = currIndex + 1;

			//INFO: ��� �̹��� ���� ��ġ
			const int upStartPos{ pos };
			//INFO: �ϴ� �̹��� ���� ��ġ
			int downStartPos{ 0 };
			//INFO: �ϴ� �̹��� ������ ��ġ
			int downEndPos{ 0 };

			int totalLength{ 0 };

			while (cnt < 4) {
				//INFO: �� ����Ʈ���� �����Ǵ� ���
				if (arr[pos] == 'x') {
					//INFO: foo�Լ��� ���� �˻��� ��ġ��ŭ �̵��� ĭ ���� ��ȯ�Ѵ�
					//EXAMPLE: xwwbb�� ��� 5�� ��ȯ�ؾ� �� ���� ���ڸ� �˻��� �� �ִ�
					pos += calculate_answer(pos);
				}
				//INFO: �Ϲ� ������ ���
				else {
					pos++;
				}

				//INFO: ����Ʈ������ ������� ó���� ����
				cnt++;

				//INFO: ��� �̹����� ���� ����
				if (cnt == 2) {
					downStartPos = pos;
				}
				//INFO: �ϴ� �̹����� ���� ����
				else if (cnt == 4) {
					downEndPos = pos;
				}
			}

			{//INFO: ��� �̹����� �ϴ� �̹����� ��ȯ�Ѵ�
				char temp[1000];
				const int upImageLength{ downStartPos - upStartPos };
				const int downImageLength{ downEndPos - downStartPos };
				const int newDownStartPos{ upStartPos + downImageLength };
				memcpy(temp, &arr[upStartPos], upImageLength);
				memcpy(&arr[upStartPos], &arr[downStartPos], downImageLength);
				memcpy(&arr[newDownStartPos], &temp[0], upImageLength);
			}

			//INFO: x�� ������ ��ü ���� ����
			totalLength = (downEndPos - upStartPos) + 1;
			return totalLength;
		}
		//INFO: ���� ���� ������ ��� (��� �Ǵ� ������)
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