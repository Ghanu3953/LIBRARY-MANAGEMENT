# LIBRARY-MANAGEMENT
SMART LIBRARY MANAGEMENT SYSTEM
#  Library Management System (C++ | OOP)

A console-based Library Management System built in **C++17** to demonstrate
Object-Oriented Programming concepts. Supports Students and Faculty with different
borrowing rules, fine calculation, search, and data persistence using file handling.

##  Features
- Add books and register users (Student / Faculty)
- Issue and return books with borrowing limits
- Automatic fine calculation (different rate for each user type)
- Search books by title (case-insensitive)
- Data saved to files and reloaded on next run
- Robust error handling using custom exceptions

## OOP Concepts Used
| Concept | Where |
|---|---|
| **Encapsulation** | `Book` – private data, public getters/setters |
| **Abstraction** | `User` – abstract class with pure virtual functions |
| **Inheritance** | `Student` and `Faculty` inherit from `User` |
| **Polymorphism** | `maxBooks()`, `loanDays()`, `finePerDay()` overridden; called via `User&` / `unique_ptr<User>` |
| **Exception handling** | `LibraryException` extends `std::runtime_error` |
| **File handling** | `Library::save()` / `Library::load()` |
| **STL & smart pointers** | `vector`, `unique_ptr`, `make_unique`, `std::find`, `std::remove` |

## Project Structure
```
LibraryManagementSystem/
├── include/
│   ├── Book.h
│   ├── User.h        (User, Student, Faculty)
│   ├── Library.h     (core logic + exception + file I/O)
│   └── Utils.h
├── src/
│   └── main.cpp      (menu / user interface)
├── data/             (books.txt & users.txt created at runtime)
├── Makefile
├── .gitignore
└── README.md
```

##  Build & Run
Requires `g++` with C++17 support.
```bash
make          # compile
./library     # run   (Windows: library.exe)
```
Without make:
```bash
g++ -std=c++17 src/main.cpp -o library
```

## 🧾 User Rules
| User | Max books | Loan period | Fine / late day |
|---|---|---|---|
| Student | 3 | 14 days | Rs. 2 |
| Faculty | 10 | 30 days | Rs. 1 |

##  Future Improvements
- Real dates using `<chrono>` instead of "days kept"
- Admin login, SQLite database, or a GUI (Qt)
- Unit tests with Google Test
