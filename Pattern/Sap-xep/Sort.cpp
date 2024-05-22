#include <bits/stdc++.h>
using namespace std;

const int N = 50'000'000;
int t[N]; // Mảng phụ của thuật toán merge sort
int a[N], b[N],c[N+1], d[N];

// trộn 2 mảng
void merge(int a[], int L, int M, int R) {
    int i = L, j = M + 1;
    for (int k = L; k <= R; k++) {
        if (i > M) t[k] = a[j++];
        else if (j > R) t[k] = a[i++];
        else if (a[i] < a[j]) t[k] = a[i++];
        else t[k] = a[j++];
    }
    for (int k = L; k <= R; k++) {
        a[k] = t[k];
    }
}

// gọi đệ quy sắp xếp 2 mảng
void mergeSort(int a[], int L, int R) {  
    if (L == R) return;
    int M = (L + R) / 2;
    mergeSort(a, L, M);
    mergeSort(a, M+1, R);
    merge(a, L, M, R);;
}

void init() {
    srand(time(0));
    for (int i = 0; i < N; i++) a[i] = b[i] = c[i] = d[i] = rand() * rand();
}

void print(int a[]) {
    for (int i = 0; i < N; i++)
        cout << i << " ";
    cout << endl;
}

int partition(int a[], int L, int R) {
    int M = (L + R) / 2;  // index của giá trị phân hoạch
    int pivot = a[M];     // giá trị phân hoạch
    swap(a[M], a[R]);
    int store = L;
    for (int i = L; i < R; i++) {
        if (a[i] < pivot) {
            swap(a[store], a[i]);
            store++;
        }
    }
    swap(a[store], a[R]);
    return store;
}

// gọi đệ quy sắp xếp từ a[L] đến a[R]
void quickSort(int a[], int L, int R) {
    if (L == R) return;
    int M = partition(a, L, R);
    if (L < M) quickSort(a, L, M);
    if (M < R) quickSort(a, M+1, R);

}

// xây heap từ gốc a[i] và giới hạn tới a[n]
void heapify(int a[], int i, int n) {
    int L = i * 2;
    int R = L + 1;
    int m = i;
    if (L <= n && a[L] > a[m]) m = L;
    if (R <= n && a[R] > a[m]) m = R;
    if (m != i) {
        swap(a[i], a[m]);
        heapify(a, m, n);
    }
}

// xây heap ban đầu từ gốc a[1] và giới hạn tới a[n]
void build_heap(int a[], int n) {
    for (int i = n/2; i >= 1; i--) heapify(a, i, n);
}

void heapSort(int a[], int n) {
    build_heap(a, n);
    for (int i = n; i > 1; i--) {
        swap(a[1], a[i]);
        heapify(a, 1, i-1);
    }
}

int main()
{
    clock_t start;    

    start = clock();
    init();
    mergeSort(a, 0, N-1);    
    // print(a);
    cout << "Time merge sort: " << (clock() - start) / (double) CLOCKS_PER_SEC << endl;

    start = clock();
    quickSort(b, 0, N-1);
    // print(b);
    cout << "Time quick sort: " << (clock() - start) / (double) CLOCKS_PER_SEC << endl;

    start = clock();
    heapSort(c, N-1);
    // print(b);
    cout << "Time heap sort: " << (clock() - start) / (double) CLOCKS_PER_SEC << endl;

    start = clock();
    sort(d, d+N);
    // print(b);
    cout << "Time STL sort: " << (clock() - start) / (double) CLOCKS_PER_SEC << endl;
    return 0;
}