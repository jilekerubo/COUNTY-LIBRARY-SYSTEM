/*COUNTY LIBRARY MANAGEMENT SYSTEM
BY IVY JILE
FEBRUARY 2022
MIT license
C89 Compiler
*/
#include <stdio.h>
#include <stdlib.h>

int menu()
{
  int action;
    printf("select an action below\n");
    printf("1. add new patron\n");
    printf("2. view all patrons\n");
    printf("3. view all books\n");
    printf("4. add new books\n");
    printf("Your action\n");
    scanf("%d",action);
    return action;
}
int main()
{
    printf("COUNTY LIBRARY MANAGEMENT SYSTEM\n");
    printf("WELCOME MADAM IVY");
    printf("you selected action %d", menu());
    return 0;
}
