#include "library.h"
void loadBooks(){
    FILE *fp = fopen("books.txt","r");
    if(!fp) { bookCount = 0; return; }
    bookCount = 0;
    while(1){
        int id;
        if (fscanf(fp, "%d\n", &id) != 1) break;
        books[bookCount].id = id;
        if (!fgets(books[bookCount].title, sizeof(books[bookCount].title), fp)) break;
        books[bookCount].title[strcspn(books[bookCount].title, "\n")] = '\0';
        if (!fgets(books[bookCount].author, sizeof(books[bookCount].author), fp)) break;
        books[bookCount].author[strcspn(books[bookCount].author, "\n")] = '\0';
        if (fscanf(fp, "%d\n%d\n%d\n",
                   &books[bookCount].branchID,
                   &books[bookCount].issued,
                   &books[bookCount].issuedTo) != 3) break;
        bookCount++;
        if (bookCount >= MAX) break;
    }
    fclose(fp);
}
void saveBooks(){
    FILE *fp = fopen("books.txt", "w");
    if(!fp) return;
    for(int i = 0; i < bookCount; i++){
        fprintf(fp, "%d\n%s\n%s\n%d\n%d\n%d\n",
            books[i].id,
            books[i].title,
            books[i].author,
            books[i].branchID,
            books[i].issued,
            books[i].issuedTo
        );
    }
    fclose(fp);
}
void loadStudents(){
    FILE *fp = fopen("students.txt", "r");
    if(!fp) { studentCount = 0; return; }
    studentCount = 0;
    while(1){
        int id;
        if (fscanf(fp, "%d\n", &id) != 1) break;
        students[studentCount].id = id;
        if (!fgets(students[studentCount].name, sizeof(students[studentCount].name), fp)) break;
        students[studentCount].name[strcspn(students[studentCount].name, "\n")] = '\0';
        if (!fgets(students[studentCount].password, sizeof(students[studentCount].password), fp)) break;
        students[studentCount].password[strcspn(students[studentCount].password, "\n")] = '\0';
        if (fscanf(fp, "%f\n", &students[studentCount].penalty) != 1) break;
        studentCount++;
        if (studentCount >= MAX) break;
    }
    fclose(fp);
}
void saveStudents(){
    FILE *fp = fopen("students.txt", "w");
    if(!fp) return;
    for(int i = 0; i < studentCount; i++){
        fprintf(fp, "%d\n%s\n%s\n%.2f\n",
            students[i].id,
            students[i].name,
            students[i].password,
            students[i].penalty
        );
    }
    fclose(fp);
}
