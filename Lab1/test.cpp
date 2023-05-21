#include <stdio.h>
int gcd(int x, int y);  //function prototype

int main()
{
   int num1, num2, hcf, lcm;

   printf("Enter two integer Values:\n");
   scanf("%d %d", &num1, &num2);

   hcf = gcd(num1, num2);
   printf("GCD: %d", hcf);
   printf("\nLCM: %d", (num1 * num2) / hcf);
   return 0;
}
//recursive function
int gcd(int x, int y)
{
   if (y == 0)   //recursion termination condition
   {
      return x;
   }
   else 
   {
      return gcd(y, x % y);   //calls itself
   }
}
