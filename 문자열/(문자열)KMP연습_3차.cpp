//KMP¿¬½À 3Â÷
//http://m.blog.naver.com/choyi0521/80206821567
#include <iostream>
#include <stdio.h>
using namespace std;

char str[1001];
char pattern[1001];
int pi[1001];
int s_len, p_len;

int Strlen(char * str) { int i = 0; for (i = 0; str[i] != '\0'; i++); return i; }

void Check_Pi()
{
	int i = 0, j = -1;
	pi[0] = -1;
	while (i < p_len)
	{
		if (j == -1 || pattern[i] == pattern[j]) { i++, j++, pi[i] = j; }
		else j = pi[j];
	}
}

void KMP()
{
	int i = 0, j = 0;
	while (i < s_len)
	{
		if (j == -1 || str[i] == pattern[j]) { i++, j++; }
		else j = pi[j];
		
		if (j == p_len)
		{
			printf("%d\n", i - p_len);
			j = pi[j];
		}
	}
}

int main(void)
{
	cin >> str;
	cin >> pattern;
	s_len = Strlen(str);
	p_len = Strlen(pattern);
	Check_Pi();
	KMP();

	return 0;
}