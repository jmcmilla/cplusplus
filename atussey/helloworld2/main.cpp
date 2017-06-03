#include <iostream>

int main()
{
  int array[6] = { 1, 3, 10, 9, 4, 8 };

for(int i = 0; i < 6; ++i)
{
    // Stop when the first even element is found
    if(array[i] % 2 == 0)
    {
        std::cout << "First even element is " << array[i] << " at " << i;

    }
}
  return 0;
}
