#include <bits/stdc++.h>

using namespace std;

void read(int n) {
    bool diffs[n + 1] = {false};
    string trash;
    int last, cur;
    int counter = 0;

    scanf(" %d", &last);
    for (int i = 1; i < n; i++) {
        scanf(" %d", &cur);

        if ((abs(last - cur) > n) || (last - cur == 0) || diffs[last - cur]) {
            printf("Not jolly\n");
            getline(cin, trash);
            return;
        } else {
            counter++;
            diffs[last - cur] = true;
        }
        last = cur;
    }

    if (counter == n - 1)
        printf("Jolly\n");
    else
        printf("Not jolly\n");
}

int main() {
    int n;

    while(scanf(" %d", &n) != EOF && n) {
        read(n);
    }

    return 0;
}
