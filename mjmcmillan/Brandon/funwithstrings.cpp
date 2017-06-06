#include <stdio.h>

int strLength(const char *s)
{
	int idx = 0;
	for (int i = 0; s[i] != 0; i++)
		{
			idx = i;
		}
	int size = idx + 1;
	return size;
}

void strTruncate(char *s, int n)
{
	s[n] = 0;
}

void strCapitalize(char *s)
{
int size = strLength(s);
for (int i = 0; i < size; i++)
	{
		if (s[i] >= 97 && s[i] <= 122)
			{
				s[i] = s[i] - 32;
			}
	}
}

//This is horribly, horribly wrong because it will overflow s1's buffer if s1 is smaller
// or not replace all letters if s2 is smaller..
void strCopy(char *s1, const char *s2)
{
	int size = strLength(s2);
	for (int i = 0; i < size; i++)
		{
			s1[i] = s2[i];
		}
	for (int i = size; i < (sizeof(s1)/sizeof(s1[i])); i++)
		{
			s1[i] = 0;
		}
}

//If s1 does not have enough room buffer overflow.
void strAppend(char *s1, const char *s2)
{
	int startidx = strLength(s1);
	int loopnum = strLength(s2);
	for (int i = startidx; i < startidx + loopnum; i++)
		{
			char nextletter = s2[i - startidx];
			s1[i] = nextletter;
		}
}

int main (int argc, char **argv)
{
	if (argc < 2)
		{
			printf("USAGE: %s [NAME]\n", argv[0]);
		}
	else
		{
			char name[10];
			strCopy(name, argv[1]);
			strTruncate(name, 6);
			char greeting[40] = "hello, ";
			strAppend(greeting, name);
			if (strLength(name) == 3)
				{
					strCapitalize(greeting);
					printf("%s\n", greeting);
				}
			else
				{
					printf("%s\n", greeting);
				}
		}
	return 0;
}
