#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	auto start_time = std::chrono::high_resolution_clock::now();

	int flag = 0;
    for(int i = 2; i < 100; i++)
	{
		if(100 % i == 0)
		{
			flag = 1;
			break;
		}
	}
	if(flag == 0) cout << "소수";
	else cout << "합성수"; 

    // 종료 시간 기록
    auto end_time = std::chrono::high_resolution_clock::now();

    // 시간 차이 계산
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    // 결과 출력
    std::cout << "Execution time: " << duration.count() << " microseconds" << std::endl;

    return 0;
}
