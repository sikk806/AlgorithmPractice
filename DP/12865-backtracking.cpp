#include <bits/stdc++.h>

using namespace std;

int N, K;
int highest_sum = 0;
vector<pair<int, int>> bag;

void dp(int sum_bag, int sum_price, int start_point) {
    if (sum_bag > K) return;  // �賶�� �뷮�� �ʰ��� ��� ����
    if (start_point == N) {
        highest_sum = max(highest_sum, sum_price);
        return;
    }
    // ���� �������� �������� �ʴ� ���
    dp(sum_bag, sum_price, start_point + 1);
    // ���� �������� �����ϴ� ���
    dp(sum_bag + bag[start_point].first, sum_price + bag[start_point].second, start_point + 1);
}

int main(void) {
    cin >> N >> K;
    bag.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> bag[i].first >> bag[i].second;
    }
    dp(0, 0, 0);
    cout << highest_sum << endl;
    return 0;
}

