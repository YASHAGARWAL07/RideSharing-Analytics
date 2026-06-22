# Ride Sharing Analytics

## Project Overview

Ride Sharing Analytics is a C++ based project that simulates the analytics system of a ride-sharing platform such as Ola or Uber.

The project focuses on processing ride data and generating useful insights using Data Structures, Algorithms, and Object-Oriented Programming concepts.

Instead of simply storing ride information, the system performs various analytical operations such as revenue analysis, driver performance evaluation, ride filtering, surge pricing simulation, and fare-based searches.

The primary objective of the project is to understand how optimized algorithms can be used to efficiently process large datasets.

---

## Team Members

* Yash Agarwal
* Shivani
* Nitya
* Pooja

Team Name: **The Optimizers**

---

## OOP Concepts Used

* Class
* Object
* Encapsulation
* Abstraction
* Constructor
* Access Specifiers (Public / Private)
* this Pointer
* Inheritance (for extended ride types)

---

## Algorithms Used

### Revenue Analysis

* Prefix Sum
* Sliding Window
* Kadane's Algorithm
* accumulate()

### Driver Analytics

* Sorting
* partial_sort()
* count_if()

### Search & Filter

* Binary Search
* min_element()
* remove + erase

### Surge Pricing & Reports

* Difference Array
* Driver Bucketing / Grouping

---

## Project Structure

```text
RideSharingAnalytics/
│
├── main.cpp
├── Trip.h
├── RideAnalytics.h
├── RideAnalytics.cpp
│
├── modules/
│   ├── RevenueAnalysis.cpp
│   ├── DriverAnalytics.cpp
│   ├── SearchAndFilter.cpp
│   └── SurgePricing.cpp
│
├── data/
│   └── sampleData.cpp
│
└── README.md
```

---

## Module Description

### Trip.h

Defines the Trip class and stores information related to a ride.

### RideAnalytics.h / RideAnalytics.cpp

Acts as the central analytics engine and manages all ride records.

### RevenueAnalysis.cpp

Contains revenue-related analytics and optimization algorithms.

### DriverAnalytics.cpp

Handles driver performance analysis and ranking.

### SearchAndFilter.cpp

Implements searching and filtering operations on ride data.

### SurgePricing.cpp

Handles surge pricing simulation and zone-based analysis.

### sampleData.cpp

Contains sample ride records used for testing.

---

## Features

* Add and store ride records
* Revenue analysis
* Peak earning period detection
* Driver performance evaluation
* Fare threshold search
* Cheapest and highest fare detection
* Cancelled ride filtering
* Surge pricing simulation
* Zone-wise analytics
* Report generation

---

## How To Run

### Compile

```bash
g++ main.cpp RideAnalytics.cpp data/sampleData.cpp modules/*.cpp -o analytics
```

### Execute

```bash
./analytics
```

---
