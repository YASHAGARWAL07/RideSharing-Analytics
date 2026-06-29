# Ride Sharing Analytics

## Project Overview

Ride Sharing Analytics is a C++ based project that simulates the backend analytics system of a ride-sharing platform such as Ola or Uber.

The project focuses on processing ride data and generating meaningful insights using Data Structures, Algorithms, and Object-Oriented Programming concepts.

Instead of simply storing ride information, the system performs analytical operations such as revenue analysis, driver performance evaluation, ride filtering, surge pricing simulation, and fare-based searches.

The primary objective of this project is to understand how optimized algorithms can be used to efficiently process and analyze large datasets.

---

## Team Members
 
* Shivani Joshi (2024BTCSE017)
* Yash Agarwal (2024BTCSE020)
* Nitya (2024BTCSE014)
* Pooja Jangir (2025BTECE016)

**Team Name:** The Optimizers

---

## OOP Concepts Used

* Class
* Object
* Encapsulation
* Abstraction
* Constructor
* Access Specifiers (Public / Private)
* this Pointer
* Inheritance

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
├── Modules/
│   ├── RevenueAnalysis.cpp
│   ├── DriverAnalytics.cpp
│   ├── SearchAndFilter.cpp
│   └── SurgePricing.cpp
│
├── Data/
│   └── sampleData.cpp
│
└── README.md
```

---

## Module Description

### Trip.h

Defines the Trip class and stores ride-related information.

### RideAnalytics.h / RideAnalytics.cpp

Acts as the central analytics engine and manages all ride records.

### RevenueAnalysis.cpp

Implements revenue-related analytics and optimization algorithms.

### DriverAnalytics.cpp

Handles driver statistics, rankings, and performance analysis.

### SearchAndFilter.cpp

Implements ride searching and filtering operations.

### SurgePricing.cpp

Handles surge pricing simulation and zone-wise analysis.

### sampleData.cpp

Contains sample ride records used for testing and development.

---

## Features

* Store and manage ride records
* Revenue analysis
* Peak earning period detection
* Driver performance evaluation
* Fare threshold search
* Cheapest and highest fare detection
* Cancelled ride filtering
* Surge pricing simulation
* Zone-wise analytics
* Driver-wise analytics
* Report generation

---

## How To Run

### Compile

```bash
g++ main.cpp RideAnalytics.cpp Data/sampleData.cpp Modules/*.cpp -o analytics
```

### Run

```bash
./analytics
```

---
