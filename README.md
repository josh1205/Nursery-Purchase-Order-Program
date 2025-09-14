# Nursery Stock Order Management - C++ Project

**Name:** Joshua Lavieri  
**Course:** Foundations of Computer Science  
**Professor:** Dr. Lofton Bullard  
**Date:** 08/03/20

---

## 📘 Overview
This project was created as part of a college assignment. It is written in C++ and demonstrates **object-oriented programming**, **dynamic memory allocation**, and **operator overloading**.  

The program manages nursery stock purchase orders by reading data from a file, processing orders, applying tax rates and discounts, and outputting formatted results.  

---

## ⚙️ Program Components

### **Classes**
- **order_record**
  - Holds plant name, county, plant cost, quantity, and calculated values (net cost, tax, discount, total cost).

- **order_class**
  - Manages an array of `order_record` objects using dynamic memory.  
  - Key features:
    - Default constructor: Reads initial data from `nursery_stock.txt`.
    - Copy constructor: Deep copy of dynamic arrays.
    - Destructor: Deallocates memory.  
    - `add()`: Adds a new order.  
    - `operator-`: Removes orders by plant name.  
    - `process()`: Calculates net cost, tax, discount, and total cost.  
    - `double_size()`: Doubles array size when full.  
    - `operator<<`: Prints all orders neatly formatted.  

### **Driver Program**
- Tests constructors, `add`, `remove`, `process`, copy constructor, and destructor.  
- Demonstrates dynamic array behavior and operator overloading.  

---

## 🛠️ How to Compile and Run
Make sure you have a C++ compiler installed (like `g++`).  

```bash
# Compile
g++ main.cpp order_class.cpp -o order_manager

# Run
./order_manager
```

The program requires an input file named **`nursery_stock.txt`** with plant order data.  

**Example (`nursery_stock.txt`):**
```
owl dade 10.55 100
hibiscus broward 15.82 15
rose dade 9.99 45
carnation palm 7.99 32
rose palm 7.99 60
widow palm 25.75 5
carnation dade 12.55 10
carnation dade 12.55 8
lilly broward 6.92 150
xerabtgemum palm 13.63 50
yarrow dade 22.85 20
zenobia palm 37.19 32
zephyranthes broward 62.82 40
daisy broward 15.99 80
aconitum dade 30.02 72
amaryllis dade 16.14 65
bogonia broward 18.45 3
bellflow broward 2.96 200
bergenia palm 85.92 10
```

---

## ✨ Features
- Demonstrates **constructors, destructors, and operator overloading**.  
- Dynamic memory allocation with array resizing.  
- Tax and discount calculations based on **county** and **quantity**.  
- Input/output handling with formatted display.  

---

## 📚 Notes
- This was created as a **college project**, not for production use.  
- Demonstrates strong use of C++ OOP principles and memory management.  

