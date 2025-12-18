#include "library.h"
int currentStudentID = 0;
Book books[MAX];
Student students[MAX];
int bookCount = 0;
int studentCount = 0;
void showMainMenu(){
    printf("\n====== LIBRARY SYSTEM ======\n");
    printf("1. Admin Login\n");
    printf("2. Student Login\n");
    printf("3. Exit\n");
    printf("Enter choice: ");
}
int main(){
    loadBooks();
    loadStudents();

    int choice;
    while(1){
        showMainMenu();
        if (scanf("%d",&choice)!=1){ while(getchar()!='\n'); continue; }
        getchar();
        if(choice==1){
            char pass[50];
            printf("Enter admin password: ");
            fgets(pass,sizeof(pass),stdin);
            pass[strcspn(pass,"\n")] = '\0';
            /* simple admin password: "admin" (change as needed) */
            if(strcmp(pass,"admin")==0){
                adminMenu();
            } else {
                printf("Incorrect admin password.\n");
            }
        } else if(choice==2){
            studentMenu();
        } else if(choice==3){
            printf("Exiting... Saving data.\n");
            saveBooks();
            saveStudents();
            break;
        } else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}
