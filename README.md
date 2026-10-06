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

---

#  How to Upload This Project to GitHub

## One-time setup
1. Create an account at https://github.com
2. Install Git: https://git-scm.com/downloads
3. Tell Git who you are:
```bash
git config --global user.name  "Your Name"
git config --global user.email "you@example.com"
```

## Step 1 – Create an empty repository on GitHub
1. Click **+ → New repository**
2. Name: `library-management-system-cpp`
3. Add a short description
4. Choose **Public** (so recruiters can see it)
5. **Do NOT** tick "Add README / .gitignore" (we already have them)
6. Click **Create repository** and copy the repo URL

## Step 2 – Push from your computer
Open a terminal inside the project folder:
```bash
git init                                   # start tracking this folder
git add .                                  # stage all files
git commit -m "Initial commit: Library Management System in C++"
git branch -M main                         # name the branch 'main'
git remote add origin https://github.com/<your-username>/library-management-system-cpp.git
git push -u origin main                    # upload
```
When asked for a password, use a **Personal Access Token**
(GitHub → Settings → Developer settings → Personal access tokens), not your account password.

## Step 3 – Updating later
```bash
git add .
git commit -m "Describe what you changed"
git push
```

## Step 4 – Make it recruiter-ready
- Keep a clear README (this one) and add a screenshot of the output
- Commit often with meaningful messages (shows real development history)
- **Pin** the repo on your GitHub profile (Profile → Customize your pins)
- Add the link in your resume under *Projects*

## Common errors
| Error | Fix |
|---|---|
| `remote origin already exists` | `git remote set-url origin <url>` |
| `failed to push… fetch first` | `git pull origin main --rebase` then `git push` |
| Authentication failed | Use a Personal Access Token, not your password |
| `src refspec main does not match` | Make a commit first, then `git branch -M main` |
