/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv)
{
	int c;
	scanf("%d", &c);

	for (int s = 0; s < c; s++) {
		int n, m;
		
		int max = 1;

		scanf("%d %d", &n, &m);

		int** fly = (int**)malloc(sizeof(int*) * n);
		for (int i = 0; i < n; i++) {
			fly[i] = (int*)malloc(sizeof(int) * n);
			for (int j = 0; j < n; j++) {
				scanf("%d", &fly[i][j]);
			}
		}

		for (int i = 0; i <= (n - m); i++) {
			for (int j = 0; j <= (n - m); j++) {
				int temp = 0;

				for (int k = i; k < i + m; k++) {
					for (int f = j; f < j + m; f++) {
						temp += fly[k][f];
					}
				}
				if (temp > max)
					max = temp;
			}
		}

		printf("#%d %d\n", s + 1, max);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}