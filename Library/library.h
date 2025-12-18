#ifndef LIBRARY_H
#define LIBRARY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct {
    int id;
    char title[100];
    char author[100];
    int branchID;
    int issued;
    int issuedTo;
} Book;
typedef struct {
    int id;
    char name[100];
    char password[50];
    float penalty;
} Student;
extern int currentStudentID;
extern Book books[MAX];
extern Student students[MAX];
extern int bookCount;
extern int studentCount;
void adminMenu();
void addBook();
void addStudent();
void issueBook();
void returnBook();
void penaltyReport();
void issueReturnBookReport();
void adminSearchBook();
void deleteBook();
void studentMenu();
void myAccount(int id);
void searchBook();
void changeStudentPassword(int id);
void studentIssueBookReport(int studentID);
void loadBooks();
void saveBooks();
void loadStudents();
void saveStudents();
#endif
