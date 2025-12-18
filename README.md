# Library Management System in C

A console-based Library Management System developed in C language. 
Features include book management, student management, book issuance, returns, penalty calculation, and report generation. 
 
Date: November 2025

---

## Overview

The Library Management System (LMS) is a console-based application written in C.  
It helps manage books, students, and transactions while keeping data in text files.  
Designed for small to medium-sized libraries, it is lightweight, simple, and efficient.

---

## Features

**Admin Features**
- Add, edit, delete, and search books
- Add and view student records
- Issue and return books
- Calculate, adjust, and clear penalties for overdue books
- Generate reports on issued books and student penalties

**Student Features**
- View personal account details, including issued books and penalties
- Search books by title or author
- Request book issuance if available
- Change personal password

**Technical Highlights**
- Modular programming with functions and structures
- Persistent storage using text files (`books.txt`, `students.txt`)
- Console-based, menu-driven interface
- Role-based access for Admin and Student
- Input validation and error handling

---

## Project Structure

- Library-Management-System/
  - main.c        : Main program file
  - admin.c       : Admin functionalities
  - student.c     : Student functionalities
  - files.c       : File Handling
  - library.h     : Header file with structures and prototypes
  - books.txt     : Persistent storage for books
  - students.txt  : Persistent storage for students
  - README.md     : Project documentation

---

## Requirements

- Programming Language: C (ANSI C)
- Compiler: GCC or any standard C compiler
- Operating System: Windows, Linux, or macOS
- IDE/Editor: Code::Blocks, Dev-C++, VS Code, or any text editor

---

## Block Diagram

<img width="682" height="736" alt="2145" src="https://github.com/user-attachments/assets/f2d00057-e00e-4e07-9cc9-550662ae96c3" />

## How to Run

1. Clone the repository:
git clone <repository-url>


2. Compile the program:


gcc main.c admin.c student.c -o LMS


3. Run the executable:


./LMS # Linux / macOS
LMS.exe # Windows


4. Follow the menu to use Admin or Student functionalities.

---

## Output Screenshots
**Main Menu**
<img width="1474" height="733" alt="mai" src="https://github.com/user-attachments/assets/53c3c05b-8aa3-4bf6-a736-f21386976cb7" />

**Admin Panel**
<img width="1473" height="728" alt="ad" src="https://github.com/user-attachments/assets/88403980-c9c0-40ca-87bf-e5da5f44751d" />

**Add Book**
<img width="1477" height="734" alt="b" src="https://github.com/user-attachments/assets/55dbaadb-1c84-4052-a760-f80f0288c9d9" />

**Add Student**
<img width="1476" height="734" alt="2" src="https://github.com/user-attachments/assets/3ae2ee2e-2b8b-438d-8381-431c09ba0b3d" />

**Issue Book**
<img width="1471" height="742" alt="3" src="https://github.com/user-attachments/assets/6a9fd7fd-bcb9-445b-a252-9e0f08aa7a98" />

**Return Book**
<img width="1471" height="740" alt="4" src="https://github.com/user-attachments/assets/3752c216-0f21-4b70-b1e7-b2688fe3aa34" />

**Penalty Report**
<img width="1471" height="495" alt="5" src="https://github.com/user-attachments/assets/b9bbb736-563d-47e9-9296-54f7b1e2c2cb" />

**Issue/Return Book Report**
<img width="1471" height="700" alt="6" src="https://github.com/user-attachments/assets/eeeb9304-8133-44bb-887d-84fe4604dadf" />

**Search Book**
<img width="1457" height="645" alt="7" src="https://github.com/user-attachments/assets/e802cc71-1c66-4516-ab97-c391a60b76b6" />

**Delete Book**
<img width="1475" height="593" alt="8" src="https://github.com/user-attachments/assets/ec7d583a-e07f-44f6-9e11-580d7d47c856" />

**Student Menu**
<img width="1486" height="389" alt="s" src="https://github.com/user-attachments/assets/02757079-a4ad-4dd7-a833-74e4598cfd78" />

**My Account**
<img width="1474" height="546" alt="11" src="https://github.com/user-attachments/assets/f41958d5-d56f-4de6-982a-7676fd44d83f" />

**Search Book**
<img width="1459" height="649" alt="12" src="https://github.com/user-attachments/assets/a9f79dec-7953-453f-b173-890b2ec40321" />

**Change Password**
<img width="1481" height="470" alt="13" src="https://github.com/user-attachments/assets/2254ea20-8e48-4c10-8647-4d7f932138f7" />

**Issue Book Report**
<img width="1600" height="838" alt="14" src="https://github.com/user-attachments/assets/6c99e875-412d-4403-9154-ae3ea44c87c3" />
<img width="1480" height="746" alt="15" src="https://github.com/user-attachments/assets/c893c107-afb6-4030-9ae2-a930313670e2" />

**Exit**
<img width="1475" height="238" alt="111" src="https://github.com/user-attachments/assets/208362f6-a139-42a4-bc43-f4e58e7cf28f" />

---

## Limitations

- Text file storage limits scalability
- Basic password authentication for admin only
- Console-based interface (no GUI)
- Manual input required for book issuance and penalty updates
- Designed for up to ~100 books and students

---

## Future Enhancements

- Integrate relational database (MySQL, SQLite)
- Encrypted passwords and advanced authentication
- Graphical User Interface (GUI)
- Automated penalty calculation
- Backup and recovery mechanisms
- Cloud-based or remote access

---

## References

1. Source code: `library.h`, `main.c`, `admin.c`, `student.c`, `books.txt`, `students.txt`  
2. GeeksforGeeks – File Handling in C: https://www.geeksforgeeks.org/file-handling-c-classes/  
3. TutorialsPoint – C Programming – Data Structures: https://www.tutorialspoint.com/cprogramming/c_data_structures.htm  
4. W3Schools – C Language Basics: https://www.w3schools.com/c/  
5. ANSI C Standard Documentation: https://www.iso-9899.info/  
6. Stack Overflow – Implementing LMS in C  

---

## License

opensource.org/licenses/MIT
