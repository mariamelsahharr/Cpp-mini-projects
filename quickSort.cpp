#include <iostream>
using namespace std;

void quick_sort(int[], int, int);
int partition(int[], int, int);

int main() {
    int i, num;
    cin >> num;

    int* a = new int[num];
    for (i = 0; i < num; i++) {
        cin >> a[i];
    }

    quick_sort(a, 0, num - 1);

    for (i = 0; i < num; i++) {
        cout << a[i] << " ";
    }

    delete[] a;  
    return 0;
}

void quick_sort(int a[], int l, int u) {
    if (l < u) {
        int j = partition(a, l, u);
        quick_sort(a, l, j - 1);
        quick_sort(a, j + 1, u);
    }
}

int partition(int a[], int l, int u) {
    int v = a[l];
    int i = l;
    int j = u + 1;
    do {
        do {
            i++;
        } while (a[i] < v && i <= u);

        do {
            j--;
        } while (v < a[j]);

        if (i < j) {
            swap(a[i], a[j]);
        }
    } while (i < j);

    a[l] = a[j];
    a[j] = v;

    return j;
}
