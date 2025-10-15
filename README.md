<p align="center">
  <img src="https://raw.githubusercontent.com/nazmul-1117/Academic-Programming/main/assets/banner.gif" alt="Academic Programming Banner" width="100%" />
</p>

<h1 align="center">🎓 Academic Programming</h1>

<p align="center">
  <em>A comprehensive archive of university programming practice, lab assignments, and academic projects.</em>
</p>

<p align="center">
  <a href="https://github.com/nazmul-1117/Academic-Programming/stargazers">
    <img src="https://img.shields.io/github/stars/nazmul-1117/Academic-Programming?style=for-the-badge&color=yellow" />
  </a>
  <a href="https://github.com/nazmul-1117/Academic-Programming/network/members">
    <img src="https://img.shields.io/github/forks/nazmul-1117/Academic-Programming?style=for-the-badge&color=blue" />
  </a>
  <a href="https://github.com/nazmul-1117/Academic-Programming">
    <img src="https://img.shields.io/github/repo-size/nazmul-1117/Academic-Programming?style=for-the-badge&color=brightgreen" />
  </a>
  <a href="https://opensource.org/licenses/MIT">
    <img src="https://img.shields.io/badge/License-MIT-green.svg?style=for-the-badge" />
  </a>
</p>

<p align="center">
  <img src="https://img.shields.io/github/languages/top/nazmul-1117/Academic-Programming?style=flat-square&color=orange" />
  <img src="https://img.shields.io/github/languages/count/nazmul-1117/Academic-Programming?style=flat-square&color=blueviolet" />
  <img src="https://img.shields.io/github/last-commit/nazmul-1117/Academic-Programming?style=flat-square&color=red" />
  <img src="https://img.shields.io/github/commit-activity/m/nazmul-1117/Academic-Programming?style=flat-square&color=success" />
</p>

---

## 📚 Table of Contents
- [📚 Table of Contents](#-table-of-contents)
- [📖 About](#-about)
- [📁 Repository Structure](#-repository-structure)
- [🧠 Topics Covered](#-topics-covered)
- [🧰 Languages Used](#-languages-used)
- [🛠 Environment Setup](#-environment-setup)
  - [🧩 Install Compilers](#-install-compilers)
    - [**C / C++**](#c--c)
    - [**Java**](#java)
    - [**Python**](#python)
    - [**8086 Assembly**](#8086-assembly)
    - [**Web Development**](#web-development)
- [⚙️ How to Run Programs](#️-how-to-run-programs)
  - [1️⃣ Clone the Repository](#1️⃣-clone-the-repository)
  - [2️⃣ Navigate to a Folder](#2️⃣-navigate-to-a-folder)
  - [3️⃣ Compile \& Run](#3️⃣-compile--run)
    - [🧮 **C**](#-c)
    - [🧩 **C++**](#-c-1)
    - [☕ **Java**](#-java)
    - [🐚 **Shell Script**](#-shell-script)
    - [⚙️ **Assembly (8086)**](#️-assembly-8086)
- [🧾 License](#-license)
- [🤝 Contributing](#-contributing)
- [👨‍💻 Author](#-author)

---

## 📖 About

This repository contains my **university-level programming assignments and projects**, developed during my studies in **Computer Science & Engineering** at Green University of Bangladesh.

It aims to:
- 📂 Keep coursework and lab work organized  
- 💡 Help others learn fundamental to advanced programming concepts  
- 🧠 Serve as a personal knowledge archive  

Each folder represents a **course**, **topic**, or **language** — covering everything from C basics to web programming.

---

## 📁 Repository Structure

```bash
Academic-Programming/
│
├── 8086-ASM-Language/      # Assembly programs and exercises
├── Algorithm/              # Sorting, searching, recursion, etc.
├── Computer_Networking/    # Socket programming and networking examples
├── Data_Communication/     # Data communication-related programs
├── Data_Structure/         # Linked lists, stacks, queues, trees, graphs
├── Operating_System/       # Scheduling, memory management, shell tasks
├── Web-Programming/        # HTML, CSS, and frontend exercises
├── README.md               # Documentation
└── .gitignore              # Ignore build and temp files
````

---

## 🧠 Topics Covered

* **Programming Fundamentals** (Syntax, Control Structures, Loops)
* **Functions & Recursion**
* **Pointers and Memory Management (C/C++)**
* **Object-Oriented Programming (Java, C++)**
* **File I/O & Exception Handling**
* **Data Structures** – Stack, Queue, Linked List, Tree, Graph, Hashing
* **Algorithms** – Sorting, Searching, Recursion, Greedy, Dynamic Programming
* **Operating Systems** – Scheduling, Deadlocks, Memory Management
* **Networking** – Client–Server Models, Socket Programming
* **Shell Scripting & Web Programming**

---

## 🧰 Languages Used

| Language            | Folder(s)                              | Description                         |
| ------------------- | -------------------------------------- | ----------------------------------- |
| **C**               | `Data_Structure/`, `Operating_System/` | Core algorithms, OS programs        |
| **C++**             | `Algorithm/`, `Data_Structure/`        | OOP, STL, problem-solving           |
| **Java**            | `Java/`                                | OOP, multithreading, coursework     |
| **Assembly (8086)** | `8086-ASM-Language/`                   | Microprocessor-level programming    |
| **Shell Script**    | `Operating_System/`, `Shell/`          | Linux automation and system tasks   |
| **HTML/CSS**        | `Web-Programming/`                     | Frontend design and basic web pages |

---

## 🛠 Environment Setup

Before running the programs, make sure you have the required compilers installed.

### 🧩 Install Compilers

#### **C / C++**

```bash
sudo apt install gcc g++
```

#### **Java**

```bash
sudo apt install openjdk-17-jdk
```

#### **Python**

```bash
sudo apt install python3
```

#### **8086 Assembly**

Install or use:

* **MASM / TASM** (Windows)
* **EMU8086** (for simulation)
* **DOSBox** (to run `.asm` programs)

#### **Web Development**

Simply open `.html` files in any web browser.

---

## ⚙️ How to Run Programs

### 1️⃣ Clone the Repository

```bash
git clone https://github.com/nazmul-1117/Academic-Programming.git
cd Academic-Programming
```

### 2️⃣ Navigate to a Folder

```bash
cd Data_Structure/LinkedList
```

### 3️⃣ Compile & Run

#### 🧮 **C**

```bash
gcc filename.c -o output
./output
```

#### 🧩 **C++**

```bash
g++ filename.cpp -o output
./output
```

#### ☕ **Java**

```bash
javac Main.java
java Main
```

#### 🐚 **Shell Script**

```bash
bash script.sh
```

#### ⚙️ **Assembly (8086)**

> Use **TASM**, **MASM**, or **EMU8086** depending on your setup.

---

## 🧾 License

This project is licensed under the **MIT License**.
You are free to use and modify the code for **educational purposes** — please give appropriate credit.

📄 [View Full License](https://opensource.org/licenses/MIT)

---

## 🤝 Contributing

Contributions are always welcome!

1. **Fork** the repository
2. **Create** a new branch:

   ```bash
   git checkout -b improve-docs
   ```
3. **Commit** changes:

   ```bash
   git commit -m "Improve README or add new example"
   ```
4. **Push** the branch:

   ```bash
   git push origin improve-docs
   ```
5. **Open a Pull Request**

---

## 👨‍💻 Author

**Md. Nazmul Hossain**
🎓 Undergraduate Student – Computer Science & Engineering
📍 Green University of Bangladesh
🔗 [GitHub Profile](https://github.com/nazmul-1117)
📧 [223002089@student.green.ac.bd](mailto:223002089@student.green.ac.bd)

---

> 💬 *“Programming is not about typing; it’s about thinking.”*
> — **Rich Hickey**

---

⭐ **If you find this repository helpful, please give it a star!**
Your support motivates continuous learning and improvement 🌱

---
