#include <iostream>
using  namespace std;

int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

#pragma region 이진 탐색
int main() {
	int x, low, high, mid;
	cin >> x;
	low = 0;
	high = 9;

	while (low < high)
	{
		mid = (low + high) / 2;
		if (x == arr[mid]) {
			cout << x << "는 " << mid << " 번 index에 있습니다" << endl;
			break;
		}
		else if (x < arr[mid]) { // 왼쪽에 있는 상황
			high = mid - 1;
		}
		else if (x > arr[mid]) { // 오른쪽에 있는 상황
			low = mid + 1;
		}
	}
}
#pragma endregion