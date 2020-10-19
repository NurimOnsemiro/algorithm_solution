#include <string>
#include <iostream>

using namespace std;

int main() {
	int cnt{ 0 };
	//scanf("%d", &cnt);
	cin >> cnt;
	while (cnt--) {
		string str;
		cin >> str;
		int sum{ 0 };
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(') {
				sum++;
			}
			else if (str[i] == ')') {
				sum--;
			}
			if (sum < 0) break;
			if (str.length() - i < sum) break;
		}
		if (sum != 0) {
			printf("NO\n");
		}
		else {
			printf("YES\n");
		}
	}
	return 0;
}