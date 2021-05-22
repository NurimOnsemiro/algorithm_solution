/*
* n=2, lost[1,2], reserve[1,2]
* n=5, lost[1,2,3], reserve[2,3,4]
*/

#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> stdInfo(n, 0);

    for (auto& seq : reserve) {
        int idx = seq - 1;
        stdInfo[idx]++;
    }

    for (auto& seq : lost) {
        int idx = seq - 1;
        stdInfo[idx]--;
    }

    int numGoodStudents{ 0 };

    for (auto& seq : lost) {
        int idx = seq - 1;
        if (stdInfo[idx] != -1) continue;

        if (idx != 0) {
            //INFO: 첫 번째 학생이 아니라면
            if (stdInfo[idx - 1] == 1) {
                //INFO: 좌측 학생이 여벌의 체육복이 있다면
                stdInfo[idx - 1] = 0;
                stdInfo[idx] = 0;
                continue;
            }
        }

        if (idx != n - 1) {
            //INFO: 마지막 학생이 아니라면
            if (stdInfo[idx + 1] == 1) {
                //INFO: 우측 학생이 여벌의 체육복이 있다면
                stdInfo[idx + 1] = 0;
                stdInfo[idx] = 0;
                continue;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (stdInfo[i] != -1) {
            numGoodStudents++;
        }
    }

    return numGoodStudents;
}

void main() {
    int numStudents{ 0 };
    int numLost{ 0 };
    int numReserve{ 0 };

    cout << "numStudents : ";
    cin >> numStudents;

    cout << "numLost : ";
    cin >> numLost;
    cout << "numReserve : ";
    cin >> numReserve;

    vector<int> lost;
    vector<int> reserve;

    for (int i = 0; i < numLost; i++) {
        int val;
        cout << "lost val : ";
        cin >> val;
        lost.push_back(val);
    }

    for (int i = 0; i < numReserve; i++) {
        int val;
        cout << "reserve val : ";
        cin >> val;
        reserve.push_back(val);
    }

    int result = solution(numStudents, lost, reserve);
    cout << "result : " << result << endl;
}