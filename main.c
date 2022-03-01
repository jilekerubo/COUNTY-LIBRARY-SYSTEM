/*county library management system
By ivy jile morara kerubo
feb 2022
MIT license
C89 compiler
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
       printf("your action\n");
       scanf("%d",&action);
       if (action<1||action > 4){
        printf("invalid action.Try again");
       }
  void execute_action(int action) {
  switch(action){
  case 1:
    printf("1. add new patron\n");
    break;
  case 2:
    printf("2. view all patrons\n");
    break;
  case 3:
    printf("3. view all books\n");
    break;
  case 4:
    printf("4. add new books\n");
    break;
    default:printf ("invalid action.\n");
      }

  }
  return action;
}
int main()
{
    printf("COUNTY LIBRARY MANAGEMENT SYSTEM\n");
    printf("WELCOME MADAM IVY\n");
    printf("you selected action%d",menu());
    return 0;
}
