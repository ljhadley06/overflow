# overflow
HW 2: Binary Representation, Floating-point Math, and Bit Manipulation

# Floating-Point Overflow Checker

## Team Members

* Lester Hadley

---

# Project Description

This program analyzes two floating-point numbers and determines whether a **floating-point overflow (loss of precision)** may occur when repeatedly adding a loop counter to a loop bound.

The program works with **IEEE-754 single-precision (32-bit) floating-point numbers**. It examines the **exponent fields** of the floating-point representation to determine if the increment becomes too small to affect the stored value due to the limited number of fraction bits.

If overflow may occur, the program computes the **minimum threshold value** where the increment will no longer change the loop variable.

The program prints:

* The IEEE-754 bit representation of the inputs
* A warning if overflow may occur
* The overflow threshold (decimal and bit representation)

---

# Files in Repository

```
overflow_checker/
│
├── overflow.cpp
└── README.md
```

---

# Compilation

Compile the program using **g++**.

```bash
g++ -Wall -std=c++17 overflow.cpp -o overflow_checker
```

This command creates the executable:

```
overflow_checker
```

or on Windows:

```
overflow_checker.exe
```

---

# Running the Program

Run the program from the command line with **two floating-point arguments**:

```
overflow_checker <loop_bound> <loop_counter>
```

Example:

```
overflow_checker 1e+08 1.0
```

Example output:

```
loop bound:   0 10011001 01111101011110000100000
loop counter: 0 01111111 00000000000000000000000

Warning: Possible overflow!
Overflow threshold:
1.67772e+07
0 10010111 00000000000000000000000
```

---

# Incorrect Usage

If the program is run with an incorrect number of arguments, it prints:

```
usage: overflow_checker loop_bound loop_counter

    loop_bound is a positive floating-point value
    loop_counter is a positive floating-point value
```

Example:

```
overflow_checker
```

or

```
overflow_checker 17.0
```

---

# How the Program Works

1. The program reads two floating-point numbers from the command line.
2. Each value is converted into its **32-bit IEEE-754 representation** using bit manipulation.
3. The **exponent values** are extracted and compared.
4. If the exponent difference exceeds the **precision of the mantissa (24 bits)**, an overflow condition may occur.
5. The program calculates the **threshold value** where the increment would no longer change the stored floating-point value.

---

# Concepts Demonstrated

This project demonstrates:

* IEEE-754 floating-point representation
* Bit manipulation in C++
* Command-line argument handling
* Floating-point precision limits
* Efficient overflow detection without brute-force iteration
