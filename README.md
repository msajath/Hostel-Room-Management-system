# 🏨 Advanced Hostel Room Allocation System

<p align="center">

<img src="https://readme-typing-svg.herokuapp.com?font=Fira+Code&size=28&duration=3000&pause=1000&color=00C853&center=true&vCenter=true&width=700&lines=Advanced+Hostel+Management+System;Built+with+C%2B%2B+%26+Data+Structures;Smart+Room+Allocation+Solution"/>

</p>


<p align="center">

<img src="https://img.shields.io/badge/C%2B%2B-17-blue?style=for-the-badge&logo=cplusplus">

<img src="https://img.shields.io/badge/Data%20Structures-Advanced-orange?style=for-the-badge">

<img src="https://img.shields.io/badge/Object%20Oriented%20Programming-OOP-green?style=for-the-badge">

<img src="https://img.shields.io/github/stars/msajath/Hostel-Room-Management-system?style=for-the-badge">

</p>


---

# 🌟 Project Overview

**Advanced Hostel Room Allocation System** is a powerful C++ based hostel management solution developed using advanced **Data Structures and Algorithms**.

The system automates hostel operations such as:

🏠 Smart room allocation  
👨‍🎓 Student management  
🔍 Fast searching  
🔄 Room transfer  
⏳ Waiting list handling  
↩ Undo allocation operations  


This project focuses on solving a real-world hostel management problem by combining **efficient algorithms with practical software design**.
# 🚀 Why This Project?

Traditional hostel management systems rely heavily on manual records.

This system introduces:

⚡ Faster searching  
📌 Organized student records  
🔄 Automatic allocation management  
📈 Efficient memory usage  
🧠 Real-world DSA implementation  


# ✨ Features
<table>

<tr>

<td width="50%">

## 👨‍🎓 Student Management

✔ Add student records  
✔ Delete student details  
✔ Search students quickly  
✔ Maintain complete information  

</td>

<td width="50%">

## 🏠 Room Management

✔ Automatic allocation  
✔ Room transfer  
✔ Room availability tracking  
✔ Occupancy monitoring  

</td>

</tr>


<tr>

<td>

## ⏳ Smart Waiting Queue

✔ FIFO based waiting system  
✔ Automatic room assignment  
✔ Fair allocation process  

</td>


<td>

## ↩ Undo System

✔ Reverse previous operations  
✔ Allocation history tracking  
✔ Stack-based implementation  

</td>

</tr>


</table>

# 🧠 Data Structures Implementation


## 🌳 Binary Search Tree (BST)

Used for efficient student record management.

Benefits:

- Faster searching
- Ordered student records
- Efficient insertion and deletion


```
              Student Root

                  1001

              /          \

           1000          1005

          /                 \

       999                  1010


## 🔐 Hash Table

Used for instant student lookup.

Example:

```
Student ID  →  Hash Function  →  Student Record

10025       →       Index 5    →  John

```


Average search:

```
O(1)

## ⏳ Queue

Used for students waiting for rooms.

```
Front

 ↓

Student A → Student B → Student C

                         ↑

                       Rear

```


Allocation follows:

```
First Come First Serve
```
## 📚 Stack

Used for undo operations.

```
       Top

        |
    Allocation 3
    Allocation 2
    Allocation 1

```


Last action is removed first.

---

# 🏗 System Architecture

                    USER

                     |

                     ↓

        Hostel Management System

                     |

 ------------------------------------------------

 |              |             |                 |

Student       Room        Allocation        History

Manager     Manager       Manager          Manager

 |             |             |                 |

BST        Vector          Queue            Stack

 |

Hash Table


```


---

# 📂 Project Structure


```
📦 Hostel-Room-Management-System

│

├── 📁 include

│   ├── Student.h

│   ├── Room.h

│   ├── BST.h

│   ├── HashTable.h

│   └── HostelSystem.h


│

├── 📁 src

│   ├── main.cpp

│   ├── Student.cpp

│   ├── Room.cpp

│   ├── BST.cpp

│   ├── HashTable.cpp

│   └── HostelSystem.cpp


│

└── README.md


# ⚙️ Installation


### Clone Repository


```bash
git clone https://github.com/msajath/Hostel-Room-Management-system.git
```


### Compile


```bash
g++ src/*.cpp -Iinclude -o HostelSystem
```


### Run
./HostelSystem

# 🖥️ Application Preview
====================================

     🏨 HOSTEL MANAGEMENT SYSTEM

====================================

1. Add Student

2. Allocate Room

3. Search Student

4. Transfer Room

5. View Rooms

6. Waiting List

7. Undo Action

8. Exit
====================================

# 📊 Performance Analysis


| Function | Data Structure | Complexity |
|-|-|-|
| Search Student | Hash Table | O(1) |
| Insert Student | BST | O(log n) |
| Delete Student | BST | O(log n) |
| Add Waiting Student | Queue | O(1) |
| Undo Operation | Stack | O(1) |


# 🎯 Skills Demonstrated


<p align="center">

🟢 C++ Programming  

🟢 Object-Oriented Design  

🟢 Advanced Data Structures  

🟢 Algorithm Optimization  

🟢 Memory Management  

🟢 Problem Solving  

</p>

# 🔮 Future Enhancements

🚀 Graphical User Interface

🚀 Database Integration

🚀 Online Hostel Portal

🚀 Admin Authentication

🚀 Mobile Application

🚀 Payment Management

🚀 AI Based Room Recommendation


# 👨‍💻 Developer

## Mohamed Sajath


<a href="https://github.com/msajath">

<img src="https://img.shields.io/badge/GitHub-msajath-black?style=for-the-badge&logo=github">

</a>

# ⭐ Show Your Support

If you like this project:

⭐ Star this repository

🍴 Fork it

💡 Suggest improvements

<p align="center">

<b>Built with ❤️ using C++ and Data Structures</b>

</p>
