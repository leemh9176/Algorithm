//정올 약수의 합
//http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=1488&sca=50&sfl=wr_subject&stx=%EC%95%BD%EC%88%98&sop=and
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef long long Big;

int main(void)
{
	Big n;
	scanf("%lld", &n);
	Big result = -n;
	Big i;
	
	for (i = 1; i*i < n; i++)
	{
		if (n % i == 0)
		{
			result += (i + (n / i));
		}
	}
	if (i*i == n) result += i;
	printf("%lld\n", result);


	return 0;
}