/*
*	https://www.algospot.com/judge/problem/read/QUADTREE
*/

#include <iostream>
#include <array>
#include <string>
#include <cstring>

using namespace std;

//INFO: x�� �������� ���� �� ���� ���� �ΰ��� ��ȯ�ؾ� �Ѵ�
int foo(std::string& str, const int& currIndex) {
	//EXAMPLE: (xwbbw), (xwb(xwbwb)b)

	//INFO: ����Ʈ���� ������ �������� ���
	if (str[currIndex] == 'x') {
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
			if (str[pos] == 'x') {
				//INFO: func�Լ��� ���� �˻��� ��ġ��ŭ �̵��� ĭ ���� ��ȯ�Ѵ�
				//EXAMPLE: xwwbb�� ��� 5�� ��ȯ�ؾ� �� ���� ���ڸ� �˻��� �� �ִ�
				pos += foo(str, pos);
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
			std::string temp;
			int upImageLength{ downStartPos - upStartPos };
			int downImageLength{ downEndPos - downStartPos };
			int newDownStartPos{ upStartPos + downImageLength };
			temp = str.substr(upStartPos, upImageLength);
			memcpy(&str[upStartPos], &str[downStartPos], downImageLength);
			memcpy(&str[newDownStartPos], &temp[0], upImageLength);
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