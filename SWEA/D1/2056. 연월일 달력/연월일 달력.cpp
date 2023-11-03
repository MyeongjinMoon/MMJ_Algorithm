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

#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int n;
	int M[13] = { 0,31,28,31,30,31,31,30,31,30,31,30,31 };

	scanf("%d", &n);

	int** YMD = (int**)malloc(sizeof(int*) * (n + 1));
	for (int i = 0; i <= n; i++) {
		YMD[i] = (int*)malloc(sizeof(int) * 3);
	}

	for (int i = 1; i <= n; i++) {
		scanf("%4d", &YMD[i][0]);

		for (int j = 1; j < 3; j++) {
			scanf("%2d", &YMD[i][j]);
		}
		if (YMD[i][1] == 0 || YMD[i][1] > 12) {
			YMD[i][0] = -1;
			continue;
		}
		if (YMD[i][2] > M[YMD[i][1]] || YMD[i][2] == 0) {
			YMD[i][0] = -1;
			continue;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (YMD[i][0] == -1) {
			printf("#%d -1\n", i);
		}
		else {
			printf("#%d %04d/%02d/%02d\n", i, YMD[i][0], YMD[i][1], YMD[i][2]);
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}