#include <stdio.h>
#include <string>

bool isNumeric (const std::string &s)
{
		bool isnumber = true;
		for (int i = 0; i < s.size(); i++)
			{
				if(s[i] < 48 || s[i] > 57)
					{
						isnumber = false;
					}
			}

		return isnumber;
}

char calculateCheckDigit(const std::string &ncpdp)
{
	int actualints[6];
	for (int i = 0; i < 6; i++)
		{
			actualints[i] = (ncpdp[i] - 48);
		}
	return (((actualints[0] + actualints[2] + actualints[4]) + 2*(actualints[1] + actualints[3] + actualints[5])) % 10) + 48;



}

int main(int argc, char **argv)
{
	if (argc < 2)
		{
			printf("USAGE %s [store tag|ncpdp]\n", argv[0]);
		}
	else
		{
			std::string realargv = argv[1];
			if (!isNumeric(realargv))
				{
					printf("That was not a store tag or ncpdp number\n");
				}
			else
				{
					if (realargv.size() < 6 || realargv.size() > 7)
						{
							printf("That is not a store tag or ncpdp number.\n");
						}
					else if (realargv.size() == 6)
						{
							std::string fulltag = realargv + calculateCheckDigit(realargv);
							printf("%s\n", fulltag.c_str());
						}
					else
						{
							if (calculateCheckDigit(realargv) == realargv[6])
							 	{
									printf("Your check digit is correct.\n");
								}
							else
								{
									printf("Your check digit is incorrect. Are you sure you typed the ncpdp number correctly?\n");
									realargv[6] = calculateCheckDigit(realargv);
									printf("Did you mean %s?\n", realargv.c_str());
								}
						}
				}
		}
}
