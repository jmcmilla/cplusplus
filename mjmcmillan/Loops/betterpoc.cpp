#include <iostream>
#include <stdio.h>
#include <vector>
int main ()
{
	printf("%s\n", "Please enter a number");
	unsigned long long int number = 0;
	bool isnumber1 = false;
	while (!isnumber1)
		{
		if(!(1 == scanf("%i", &number)))
			{
			printf("%s\n", "That number was invalid.");
			//Get rid of stored input
			while('\n' != getchar());
			}
		else
			{
			isnumber1 = true;
			}
		}
	//declare an empty array
	std::vector<int> factors;
	for (int i = 1; i <= (number/2); i++)
		{
		//Each time the remainder of the division is zero push the number into the array as a "factor"
		if (number%i == 0)
			{
			factors.push_back(i);
			}
		}
	//attempting to find the size of the array and set it equal to an integer variable
	if (factors.size() > 2)
		{
		printf("%s\n", "Your number was composite.  Here are all of its facotrs.");
		//Iterate over the array of a variable size
		for (int i = 0; i < factors.size(); i++)
			{
			printf("%i\n", factors[i]);
			}
		printf("%i\n", number);
		}
	else
		{
		printf("%s\n", "Your number was prime");
		}
	return 0;
}
