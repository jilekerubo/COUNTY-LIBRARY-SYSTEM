/*county library management system
By CYPRIAN MWENDA
feb 2022
MIT license
C89 compiler
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct Patron {
    char name[100];
    char pass[30];
    char email[50];
    int is_staff;
};

// function prototypes
int save_patron(struct Patron patron);
void add_patron();
int menu();
void execute_action(int action);
void view_patrons();
void add_book();
void view_books();

int main()
{
    while(1) {
        printf("COUNTY LIBRARY SYSTEM!\n");
        printf("Welcome Mr. Cyprian!\n");
        execute_action(menu());
        printf("Press any key to continue");
        getch();
        system("cls");
    }
    return 0;
}

int save_patron(struct Patron patron){
    FILE *fp;
    fp = fopen("patrons","ab");
    fwrite(&patron,sizeof(struct Patron),1,fp);
    fclose(fp);
    return 1;
}

void add_patron() {
    struct Patron patron;
    printf("Enter name:");
    getchar();
    gets(patron.name);
    printf("Enter Email:");
    gets(patron.email);
    printf("Initial Password: ");
    gets(patron.pass);
    printf("Enter 1 if staff 0 otherwise: ");
    scanf("%d",&patron.is_staff);
    if(save_patron(patron))
        printf("Patron %s successfully added\n",patron.name);
    else
        printf("Unsuccessful\n");
}
//adding books
struct Book {
    char title[100];
    char department[30];
    char shelf[50];
    int book_added;
};
int save_book(struct Book book){
    FILE *fp;
    fp = fopen("books","ab");
    fwrite(&book,sizeof(struct Book),1,fp);
    fclose(fp);
    return 1;
}
void add_book() {
    struct Book book;
    printf("Enter title:");
    getchar();
    gets(book.title);
    printf("Enter department:");
    gets(book.department);
    printf("Enter shelf no: ");
    gets(book.shelf);
    printf("Enter 4 if book 0 otherwise: ");
    scanf("%d",&book.book_added);
    if(save_book(book))
        printf("Book %s successfully added\n",book.title);
    else
        printf("Unsuccessful\n");
}

int menu()
{
  int action;
  printf("Select an action:\n");
  printf("1. Add new patron\n");
  printf("2. View Patrons\n");
  printf("3. View Books\n");
  printf("4. Add New Book\n");
  printf("Your Action: ");
  scanf("%d",&action);
  if(action < 1 || action > 4) {
    printf("Invalid action. Try again\n");
  }
  return action;
}

void execute_action(int action) {
    switch(action) {
    case 1:
        add_patron();
        break;
    case 2:
        view_patrons();
        break;
    case 3:
        view_books();
        break;
    case 4:
        add_book();
        break;
    default:
        printf("Invalid action.\n");
    }
}

void view_patrons() {
    FILE *fp;
    struct Patron patron;
    if((fp = fopen("patrons","rb")) == NULL) {
        printf("Unable to open file.\n");
        return;
    }
    printf("%-20s%-30s%-10s\n","NAME","EMAIL","IS STAFF");
    while(!feof(fp)){
       fread(&patron,sizeof(struct Patron),1,fp);
       printf("%-20s",patron.name);
       printf("%-30s",patron.email);
       printf("%-10d\n",patron.is_staff);
    }

    fclose(fp);
}
void view_books() {
    FILE *fp;
    struct Book book;
    if((fp = fopen("books","rb")) == NULL) {
        printf("Unable to open file.\n");
        return;
    }
    printf("%-20s%-30s%-10s\n","TITLE","DEPARTMENT","BOOK ADDED");
    while(!feof(fp)){
       fread(&book,sizeof(struct Book),1,fp);
       printf("%-20s",book.title);
       printf("%-30s",book.department);
       printf("%-10d\n",book.book_added);
    }

    fclose(fp);
}
