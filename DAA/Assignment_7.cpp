#include <iostream>
using namespace std;
 
bool place(int k, int i, int arr[]) {
    for (int j = 1; j < k; j++) {
        if (arr[j] == i || abs(arr[j] - i) == abs(j - k))
            return false;
    }
    return true;
}
 
void nQueen(int k, int n, int arr[]) {
    for (int i = 1; i <= n; i++) {
        if (place(k, i, arr)) {
            arr[k] = i;
            if (k == n) {
                for (int j = 1; j <= n; j++)
                    cout << arr[j] << " ";
                cout << endl;
            } else {
                nQueen(k + 1, n, arr);
            }
        }
    }
}
 
int main() {
    int num;
    cout << "Enter no. of Queens : ";
    cin >> num;
    int arr[num] = {0};
    nQueen(1, num, arr);
    return 0;
}