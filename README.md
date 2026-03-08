# overflow
HW 2: Binary Representation, Floating-point Math, and Bit Manipulation
# Floating-Point Overflow Detector

# Floating-Point Overflow Detector
* Lester Hadley

---

## Project Description

This program analyzes two floating-point numbers and determines whether a floating-point overflow (loss of precision) may occur when repeatedly incrementing a loop counter.

The program follows the IEEE-754 **single-precision (32-bit)** floating-point representation. It examines the exponent portions of the two values to determine whether an increment may be lost due to insufficient precision in the fraction (mantissa) bits.

If an overflow condition is detected, the program outputs a warning message and calculates the **minimum threshold value** where the increment would no longer affect the stored floating-point value.

---

## Features

The program:

1. Accepts **two floating-point command-line arguments**

   * Loop bound
   * Loop counter increment
2. Prints the **IEEE-754 32-bit representation** of both inputs
3. Determines whether **floating-point overflow is possible**
4. If overflow may occur, computes and prints the **overflow threshold**
5. Displays the threshold in both:

   * Decimal floating-point notation
   * IEEE-754 formatted bit representation

---

## Requirements

* C++ compiler (g++ recommended)
* C++17 or later
* Standard C++ libraries (`bitset`, `cstring`, `cmath`, `cstdint`)

---

## How to Compile

Using **g++**:

```bash
g++ overflow.cpp -o overflow
```

Optional with warnings:

```bash
g++ -Wall -std=c++17 overflow.cpp -o overflow
```

This will produce the executable:

```
overflow (Linux/macOS)
overflow.exe (Windows)
```

---

## How to Run

Run the program from the command line with **two floating-point arguments**:

```bash
./overflow <loop_bound> <increment>
```

Example:

```bash
./overflow 100000000 1
```

or (Windows):

```bash
overflow 100000000 1
```

---

## Example Inputs

```
overflow 100000000 1
overflow 1024 1
overflow 3.14 0.01
overflow 0.314e+01 1
```

---

## Expected Output Behavior

### Incorrect number of arguments

```
Error: Incorrect number of arguments!
```

### No overflow detected

```
No overflow!
```

### Overflow detected

```
Warning: Possible overflow!
Overflow threshold:
<threshold value>
<threshold value in IEEE 754 bit format>
```

---

## Repository Contents

```
overflow-detector/
│
├── overflow.cpp
├── README.md
```

---

## Notes

This program determines overflow **without using brute force iteration**.
Instead, it analyzes the **difference between the exponents** of the loop bound and increment values to determine when floating-point precision is exceeded.

This approach demonstrates how floating-point numbers are stored in memory and highlights limitations of finite-precision arithmetic.
