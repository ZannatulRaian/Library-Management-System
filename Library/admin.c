#include "library.h"
#include <time.h>
void adminMenu(){
    int choice;
    while(1){
        printf("\n====== ADMIN MENU ======\n");
        printf("1. Add Book\n");
        printf("2. Add Student\n");
        printf("3. Issue Book\n");
        printf("4. Return Book\n");
        printf("5. Penalty Report / Manage Penalty\n");
        printf("6. Issue/Return Book Report\n");
        printf("7. Search Book\n");
        printf("8. Delete Book\n");
        printf("9. Logout\n");
        printf("Enter choice: ");
        if (scanf("%d",&choice) != 1) { while(getchar()!='\n'); continue; }
        getchar();
        switch(choice){
            case 1: addBook(); break;
            case 2: addStudent(); break;
            case 3: issueBook(); break;
            case 4: returnBook(); break;
            case 5: penaltyReport(); break;
            case 6: issueReturnBookReport(); break;
            case 7: adminSearchBook(); break;
            case 8: deleteBook(); break;
            case 9: return;
            default: printf("Invalid choice!\n");
        }
    }
}
int bookIssueDate[MAX][3] = {0};
void addBook(){
    if(bookCount>=MAX){printf("Book limit reached!\n"); return;}
    Book b;
    printf("Enter Book ID: "); if (scanf("%d",&b.id)!=1){ while(getchar()!='\n'); printf("Invalid ID\n"); return; } getchar();
    printf("Enter Title: "); fgets(b.title,sizeof(b.title),stdin);
    b.title[strcspn(b.title,"\n")] = '\0';
    printf("Enter Author: "); fgets(b.author,sizeof(b.author),stdin);
    b.author[strcspn(b.author,"\n")] = '\0';
    printf("Enter Branch ID: "); if (scanf("%d",&b.branchID)!=1){ while(getchar()!='\n'); b.branchID = 0; }
    b.issued = 0;
    b.issuedTo = 0;
    books[bookCount++] = b;
    saveBooks();
    printf("Book added successfully!\n");
}
void addStudent(){
    if(studentCount>=MAX){printf("Student limit reached!\n"); return;}
    Student s;
    printf("Enter Student ID: "); if (scanf("%d",&s.id)!=1){ while(getchar()!='\n'); printf("Invalid ID\n"); return; } getchar();
    printf("Enter Name: "); fgets(s.name,sizeof(s.name),stdin);
    s.name[strcspn(s.name,"\n")]='\0';
    printf("Set Password: "); fgets(s.password,sizeof(s.password),stdin);
    s.password[strcspn(s.password,"\n")]='\0';
    s.penalty = 0.0f;
    students[studentCount++] = s;
    saveStudents();
    printf("Student added successfully!\n");
}
void issueBook(){
    int id, studentID;
    printf("Enter Book ID to issue: "); if (scanf("%d",&id)!=1){ while(getchar()!='\n'); printf("Invalid ID\n"); return; }
    printf("Enter Student ID: "); if (scanf("%d",&studentID)!=1){ while(getchar()!='\n'); printf("Invalid Student ID\n"); return; }

    for(int i=0;i<bookCount;i++){
        if(books[i].id==id){
            if(books[i].issued){
                printf("Book already issued!\n");
            } else {
                int found = 0;
                for(int j=0;j<studentCount;j++){
                    if(students[j].id == studentID){ found = 1; break; }
                }
                if(!found){ printf("Student ID %d not found!\n", studentID); return; }
                books[i].issued = 1;
                books[i].issuedTo = studentID;
                time_t t = time(NULL);
                struct tm tm = *localtime(&t);
                bookIssueDate[i][0] = tm.tm_year + 1900;
                bookIssueDate[i][1] = tm.tm_mon + 1;
                bookIssueDate[i][2] = tm.tm_mday;
                saveBooks();
                printf("Book issued to student ID %d successfully!\n", studentID);
            }
            return;
        }
    }
    printf("Book not found!\n");
}
void returnBook(){
    int id;
    printf("Enter Book ID to Return: "); if (scanf("%d",&id)!=1){ while(getchar()!='\n'); printf("Invalid ID\n"); return; }
    for(int i=0;i<bookCount;i++){
        if(books[i].id==id){
            if(!books[i].issued) printf("Book was not issued!\n");
            else{
                books[i].issued = 0;
                books[i].issuedTo = 0;
                saveBooks();
                printf("Book returned successfully!\n");
            }
            return;
        }
    }
    printf("Book not found!\n");
}
void penaltyReport() {
    int choice;
    while(1){
        printf("\n--- Penalty Management ---\n");
        printf("1. View all student penalties\n");
        printf("2. Add penalty (by Book overdue days)\n");
        printf("3. Add manual penalty amount to student\n");
        printf("4. Clear student penalty (payment)\n");
        printf("5. Back to Admin Menu\n");
        printf("Choose option: ");
        if (scanf("%d",&choice)!=1){ while(getchar()!='\n'); continue; }
        if(choice==1){
            printf("\n--- Penalty Report ---\n");
            printf("%-6s %-20s %10s\n", "ID", "Name", "Penalty");
            for(int i = 0; i < studentCount; i++){
                printf("%-6d %-20s %10.2f\n", students[i].id, students[i].name, students[i].penalty);
            }
        } else if(choice==2){
    int studentID;
    const float rate_per_day = 5.0f;
    int year_issue, month_issue, day_issue;
    int year_return, month_return, day_return;
    printf("Enter Student ID: ");
    if(scanf("%d",&studentID)!=1){ while(getchar()!='\n'); printf("Invalid input\n"); continue; }
    int foundStudent = 0;
    for(int i=0;i<studentCount;i++){
        if(students[i].id == studentID){ foundStudent = 1; break; }
    }
    if(!foundStudent){ printf("Student not found!\n"); continue; }
    printf("Enter Issue Date (YYYY MM DD): ");
    if(scanf("%d %d %d",&year_issue,&month_issue,&day_issue)!=3){ while(getchar()!='\n'); printf("Invalid date input\n"); continue; }
    printf("Enter Return Date (YYYY MM DD): ");
    if(scanf("%d %d %d",&year_return,&month_return,&day_return)!=3){ while(getchar()!='\n'); printf("Invalid date input\n"); continue; }
    struct tm tm_issue = {0}, tm_return = {0};
    tm_issue.tm_year = year_issue - 1900;
    tm_issue.tm_mon  = month_issue - 1;
    tm_issue.tm_mday = day_issue;
    tm_issue.tm_hour = 0; tm_issue.tm_min = 0; tm_issue.tm_sec = 0;
    tm_return.tm_year = year_return - 1900;
    tm_return.tm_mon  = month_return - 1;
    tm_return.tm_mday = day_return;
    tm_return.tm_hour = 0; tm_return.tm_min = 0; tm_return.tm_sec = 0;
    time_t t_issue = mktime(&tm_issue);
    time_t t_return = mktime(&tm_return);
    if(t_issue == -1 || t_return == -1){ printf("Error processing dates.\n"); continue; }
    double diff_seconds = difftime(t_return, t_issue);
    int diff_days = (int)(diff_seconds / (60*60*24));
    if(diff_days < 0) diff_days = 0;
    float amount = diff_days * rate_per_day;
    for(int i=0;i<studentCount;i++){
        if(students[i].id == studentID){
            students[i].penalty += amount;
            saveStudents();
            printf("Added penalty %.2f to student %s (ID: %d) for %d days overdue.\n",
                   amount, students[i].name, studentID, diff_days);
            break;
        }
    }
}
 else if(choice==3){
            int sid;
            float amt;
            printf("Enter Student ID: "); if (scanf("%d",&sid)!=1){ while(getchar()!='\n'); printf("Invalid input\n"); continue; }
            printf("Enter amount to add: "); if (scanf("%f",&amt)!=1){ while(getchar()!='\n'); printf("Invalid input\n"); continue; }
            int found=0;
            for(int i=0;i<studentCount;i++){
                if(students[i].id==sid){
                    students[i].penalty += amt;
                    saveStudents();
                    printf("Added %.2f to student %s (ID: %d). New penalty: %.2f\n", amt, students[i].name, sid, students[i].penalty);
                    found=1; break;
                }
            }
            if(!found) printf("Student not found!\n");
        } else if(choice==4){
            int sid;
            printf("Enter Student ID to clear penalty: "); if (scanf("%d",&sid)!=1){ while(getchar()!='\n'); printf("Invalid input\n"); continue; }
            int found=0;
            for(int i=0;i<studentCount;i++){
                if(students[i].id==sid){
                    students[i].penalty = 0.0f;
                    saveStudents();
                    printf("Penalty cleared for %s (ID: %d)\n", students[i].name, sid);
                    found=1; break;
                }
            }
            if(!found) printf("Student not found!\n");
        } else if(choice==5){
            return;
        } else {
            printf("Invalid choice\n");
        }
    }
}
void issueReturnBookReport() {
    printf("\n--- Book Issue/Return Report ---\n");
    for(int i = 0; i < bookCount; i++){
        printf("Book ID: %d | %s\n", books[i].id, books[i].title);
        if(books[i].issued){
            char studentName[100] = "Unknown";
            for(int j = 0; j < studentCount; j++){
                if(students[j].id == books[i].issuedTo){
                    strcpy(studentName, students[j].name);
                    break;
                }
            }
            printf("Status: Issued | To: %s (ID: %d)\n\n", studentName, books[i].issuedTo);
        } else {
            printf("Status: Available\n\n");
        }
    }
}
void adminSearchBook() {
    char keyword[100];
    printf("\nEnter keyword to search (title or author): ");
    getchar();
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = '\0';
    printf("\n--- Admin Search Results ---\n");
    int found = 0;
    for(int i = 0; i < bookCount; i++){
        if (strstr(books[i].title, keyword) != NULL ||
            strstr(books[i].author, keyword) != NULL)
        {
            printf("Book ID: %d | %s\n", books[i].id, books[i].title);
            if(books[i].issued){
                char studentName[100] = "Unknown";
                for(int j = 0; j < studentCount; j++){
                    if(students[j].id == books[i].issuedTo){
                        strcpy(studentName, students[j].name);
                        break;
                    }
                }
                printf("Status: Issued | To: %s (ID: %d)\n\n", studentName, books[i].issuedTo);
            } else {
                printf("Status: Available\n\n");
            }

            found = 1;
        }
    }
    if (!found)
        printf("No books found for '%s'\n\n", keyword);
}
void deleteBook(){
    int id, index=-1;
    printf("Enter Book ID to Delete: "); if (scanf("%d",&id)!=1){ while(getchar()!='\n'); printf("Invalid input\n"); return; }
    for(int i=0;i<bookCount;i++){
        if(books[i].id==id){ index=i; break; }
    }
    if(index==-1){ printf("Book not found!\n"); return; }
    for(int i=index;i<bookCount-1;i++) books[i] = books[i+1];
    bookCount--;
    saveBooks();
    printf("Book deleted successfully!\n");
}
