Library Management System (LMS) in C

Department of Computer Science and Engineering
Pundra University of Science & Technology, Bangladesh
Authors: Tasbiha Zaman, Zannatul Raian, Raisa Rasmeen
Supervisor: Sahela Rahman (Lecturer, CSE)
Date: November 2025

Overview

The Library Management System (LMS) is a console-based application written in C designed to streamline library operations. It facilitates the management of books, students, and transactions while maintaining data in text files for persistent storage. This system is ideal for small to medium-sized libraries that require a simple and efficient solution without the complexity of a full-scale database or web-based system.

Features

Admin Features

Add, edit, delete, and search books

Add and view student records

Issue and return books

Calculate, adjust, and clear penalties for overdue books

Generate reports for books issued, returned, and student penalties

Student Features

View personal account details, including issued books and penalties

Search books by title or author

Request book issuance if available

Change personal password for account security

Technical Highlights

Modular programming using functions and structures

Persistent storage using text files (books.txt and students.txt)

Console-based, menu-driven interface

Role-based access: Admin and Student

Basic error handling and input validation

Project Structure
Library-Management-System/
│
├── main.c             # Main program file
├── admin.c            # Admin functionality
├── student.c          # Student functionality
├── library.h          # Header file with structures and function prototypes
├── books.txt          # Persistent storage for books
├── students.txt       # Persistent storage for students
└── README.md          # Project documentation

Requirements

Programming Language: C (ANSI C compliant)

Compiler: GCC or any standard C compiler

Operating System: Windows, Linux, or any OS with a C compiler

IDE/Editor: Code::Blocks, Dev-C++, or VS Code

How to Run

Clone the repository:

git clone <repository-url>


Compile the program:

gcc main.c admin.c student.c -o LMS


Run the executable:

./LMS   # Linux / macOS
LMS.exe # Windows


Follow the console menu to use Admin or Student functionalities.
Main Menu
<img width="1474" height="733" alt="mai" src="https://github.com/user-attachments/assets/53c3c05b-8aa3-4bf6-a736-f21386976cb7" />

Admin Panel
<img width="1473" height="728" alt="ad" src="https://github.com/user-attachments/assets/88403980-c9c0-40ca-87bf-e5da5f44751d" />

Add Book
<img width="1477" height="734" alt="b" src="https://github.com/user-attachments/assets/55dbaadb-1c84-4052-a760-f80f0288c9d9" />

Add Student
<img width="1476" height="734" alt="2" src="https://github.com/user-attachments/assets/3ae2ee2e-2b8b-438d-8381-431c09ba0b3d" />

Issue Book
<img width="1471" height="742" alt="3" src="https://github.com/user-attachments/assets/6a9fd7fd-bcb9-445b-a252-9e0f08aa7a98" />

Return Book
<img width="1471" height="740" alt="4" src="https://github.com/user-attachments/assets/3752c216-0f21-4b70-b1e7-b2688fe3aa34" />

Penalty Report
<img width="1471" height="495" alt="5" src="https://github.com/user-attachments/assets/b9bbb736-563d-47e9-9296-54f7b1e2c2cb" />

Issue/Return Book Report
<img width="1471" height="700" alt="6" src="https://github.com/user-attachments/assets/eeeb9304-8133-44bb-887d-84fe4604dadf" />

Search Book
<img width="1457" height="645" alt="7" src="https://github.com/user-attachments/assets/e802cc71-1c66-4516-ab97-c391a60b76b6" />

Delete Book
<img width="1475" height="593" alt="8" src="https://github.com/user-attachments/assets/ec7d583a-e07f-44f6-9e11-580d7d47c856" />

Student Menu
<img width="1486" height="389" alt="s" src="https://github.com/user-attachments/assets/02757079-a4ad-4dd7-a833-74e4598cfd78" />

My Account
<img width="1474" height="546" alt="11" src="https://github.com/user-attachments/assets/f41958d5-d56f-4de6-982a-7676fd44d83f" />

Search Book
<img width="1459" height="649" alt="12" src="https://github.com/user-attachments/assets/a9f79dec-7953-453f-b173-890b2ec40321" />

Change Password
<img width="1481" height="470" alt="13" src="https://github.com/user-attachments/assets/2254ea20-8e48-4c10-8647-4d7f932138f7" />

Issue Book Report
<img width="1600" height="838" alt="14" src="https://github.com/user-attachments/assets/6c99e875-412d-4403-9154-ae3ea44c87c3" />
<img width="1480" height="746" alt="15" src="https://github.com/user-attachments/assets/c893c107-afb6-4030-9ae2-a930313670e2" />

Exit
<img width="1475" height="238" alt="111" src="https://github.com/user-attachments/assets/208362f6-a139-42a4-bc43-f4e58e7cf28f" />

Limitations

Text file-based storage limits scalability

Admin login uses basic password authentication without encryption

Console-based interface only (no GUI)

Manual input required for book issuance and penalty updates

Designed for small libraries (up to ~100 books and students)

Future Enhancements

Integrate a relational database (MySQL, SQLite) for scalable storage

Implement encrypted passwords and advanced authentication

Add a graphical user interface (GUI)

Automate penalty calculation with real-time tracking

Include automated backup and recovery mechanisms

Support cloud-based or remote access

References

Source code: library.h, main.c, admin.c, student.c, books.txt, students.txt

GeeksforGeeks – File Handling in C

TutorialsPoint – C Programming – Data Structures

W3Schools – C Language Basics

ANSI C Standard Documentation – C Programming Language Reference

Stack Overflow – Implementing LMS in C

License

This project is open-source and available for educational purposes
