#include <iostream>
#include <cmath>
using namespace std;

void update(int *a, int *b) {
    int x = *a;
    int y = *b;

    *a = x + y;
    *b = abs(x - y);
}

int main() {
    int a, b;
    cin >> a >> b;

    update(&a, &b);

    cout << a << endl;
    cout << b << endl;

    return 0;
}
