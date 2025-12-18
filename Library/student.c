#include "library.h"
extern int currentStudentID;
void studentMenu(){
    int id;
    char password[50];
    int found_index = -1;
    printf("Enter Student ID: ");
    if (scanf("%d",&id) != 1) { while(getchar()!='\n'); printf("Invalid ID\n"); return; }
    getchar();
    for(int i=0;i<studentCount;i++){
        if(students[i].id==id){
            found_index = i;
            break;
        }
    }
    if(found_index == -1){ printf("Student not found!\n"); return; }
    printf("Enter Password: ");
    fgets(password,sizeof(password),stdin);
    password[strcspn(password,"\n")] = '\0';
    if(strcmp(password,students[found_index].password) != 0){
        printf("Invalid password!\n");
        return;
    }
    currentStudentID = id;
    int choice;
    printf("Welcome, %s!\n", students[found_index].name);
    while(1){
        printf("\n====== STUDENT MENU ======\n");
        printf("1. My Account\n");
        printf("2. Search Book\n");
        printf("3. Change Password\n");
        printf("4. Issue Book Report\n");
        printf("5. Logout\n");
        printf("Enter choice: ");
        if (scanf("%d",&choice)!=1){ while(getchar()!='\n'); continue; }
        getchar();
        switch (choice){
            case 1: myAccount(id); break;
            case 2: searchBook(); break;
            case 3: changeStudentPassword(id); break;
            case 4: studentIssueBookReport(id); break;
            case 5:
                currentStudentID = 0;
                return;
            default: printf("Invalid choice!\n");
        }
    }
}
void myAccount(int id){
    printf("\n--- My Account ---\n");
    for(int i=0;i<studentCount;i++){
        if(students[i].id == id){
            printf("Name: %s\n",students[i].name);
            printf("Penalty: %.2f\n",students[i].penalty);
            printf("Issued Books:\n\n");
            for(int j=0;j<bookCount;j++){
                if(books[j].issued && books[j].issuedTo==id){
                    printf("ID: %d | %s\nStatus: Issued to YOU\n\n",books[j].id,books[j].title);
                }
            }
            return;
        }
    }
    printf("Account not found!\n");
}
void searchBook(){
    char keyword[100];
    printf("\nEnter keyword to search (title or author): ");
    getchar();
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword,"\n")] ='\0';
    printf("\n--- Search Results ---\n");
    int found=0;
    for(int i=0;i<bookCount;i++){
        if(strstr(books[i].title,keyword)!= NULL ||
            strstr(books[i].author,keyword)!= NULL)
        {
            printf("ID: %d | %s\n",books[i].id,books[i].title);
            if(books[i].issued==0)
                printf("Status: Available\n\n");
            else if(books[i].issuedTo==currentStudentID)
                printf("Status: Issued to YOU\n\n");
            else
                printf("Status: Issued to Student ID %d\n\n",books[i].issuedTo);
            found = 1;
        }
    }
    if(!found)
        printf("No books found for '%s'\n\n", keyword);
}
void changeStudentPassword(int id){
    char newPass[50];
    for(int i=0;i<studentCount;i++){
        if(students[i].id==id){
            printf("Enter New Password: ");
            fgets(newPass,sizeof(newPass),stdin);
            newPass[strcspn(newPass,"\n")]='\0';
            strcpy(students[i].password,newPass);
            saveStudents();
            printf("Password updated successfully!\n");
            return;
        }
    }
    printf("Account not found!\n");
}
void studentIssueBookReport(int studentID){
    printf("\n--- Available / Issued Books ---\n");
    for(int i=0;i<bookCount;i++){
        printf("ID: %d | %s\n",books[i].id,books[i].title);
        if(books[i].issued){
            if(books[i].issuedTo==studentID){
                printf("Status: Issued to YOU\n\n");
            }else{
                printf("Status: Issued | To Student ID: %d\n\n",books[i].issuedTo);
            }
        }else{
            printf("Status: Available\n\n");
        }
    }
    int choice;
    printf("Do you want to issue a book? (1 = Yes, 0 = No): ");
    if (scanf("%d",&choice)!=1){ while(getchar()!='\n'); return; }
    if(choice==1){
        int id;
        printf("Enter Book ID to issue: ");
        if (scanf("%d",&id)!=1){ while(getchar()!='\n'); printf("Invalid input\n"); return; }
        for(int i=0;i<bookCount;i++){
            if(books[i].id==id){
                if(books[i].issued){
                    printf("Sorry, this book is already issued.\n");
                }else{
                    books[i].issued=1;
                    books[i].issuedTo=studentID;
                    saveBooks();
                    printf("Book issued successfully to YOU!\n");
                }
                return;
            }
        }
        printf("Book not found!\n");
    }
}
