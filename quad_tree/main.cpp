#include <iostream>
#include <array>
#include <string>

using namespace std;

void func(const std::string& str, const int& currIndex) {
	//EXAMPLE: xwbwb, xwbxwbwbb
	for (int i = currIndex; i < str.length(); i++) {
		if (str[i] == 'x') {
			func(str, i + 1);
		}
	}
}

int main() {
	int numTests{ 0 };
	cin >> numTests;
	cout << "numTests=" << numTests << endl;

	std::string str;

	while (numTests--) {
		cin >> str;
		func(str, 0);
		//INFO: x가 나타나면 함수를 호출한다
	}

	return 0;
}