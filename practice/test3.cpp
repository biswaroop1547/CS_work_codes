#include <iostream>

using namespace std;

int main() {
    int *p = new int[5];
    for (int i = 0; i < 5; i++) {
        scanf(" %d", p + i);
    }

    delete[] p;

    for (int i = 0; i < 5; ++i) {
        printf("%d ", *(p + 4));
    }
    return 0;
}