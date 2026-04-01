#include <iostream>
using namespace std;

int main() {
    int N;

    while (cin >> N) { 

        for (int i = 0; i < N; i++) {
            int M, x, sum = 0;
            cin >> M;

            for (int j = 0; j < M; j++) {
                cin >> x;
                sum += x;
            }

            cout << sum << endl;

            if (i != N - 1) {
                cout << endl;
            }
        }
    }

    return 0;
}