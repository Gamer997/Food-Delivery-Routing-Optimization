# 🚚 Food Polar Bear Route Optimization 

## 🌟 Overview

Food Polar Bear is a delivery company operating in Grid City, where restaurants and customers are scattered across a grid similar to Manhattan. The company aims to optimize its route planning for delivering orders efficiently, considering various constraints such as time windows for deliveries and minimizing travel time.

## 🎯 Problem Statement

The task is to develop an algorithm that plans routes for delivering orders from different restaurants to customers. Each restaurant has its own set of orders with specific delivery locations and time limits. The algorithm needs to optimize routes to cover the maximum number of deliveries in a day while minimizing travel time.

## 📋 Input

The input to the algorithm is provided through a text file with the following format:
- Number of test cases
- For each test case:
  - Grid size (N), number of riders (I), and number of restaurants (R)
  - For each restaurant:
    - Name, location, and number of orders
    - For each order: name, location, and delivery time limit

## 📝 Output

For each test case, the algorithm outputs the total minimum time required to deliver all orders efficiently. It includes the route details for each rider, showing the order of deliveries and the time taken for each delivery.

## 🏗️ Code Structure

The project is divided into two main files:
1. **File 1**: Contains C++ code for implementing data structures and algorithms related to route planning. It includes structures for Riders, Orders, Restaurants, and a Squared Graph class. It also implements Dijkstra's algorithm for finding the shortest path in the grid-based city.

2. **File 2**: Contains C++ code for implementing the A* algorithm for finding the shortest path in a grid-based environment. It prompts the user for the number of test cases and collects information about grid size, riders, and restaurants. It calculates delivery times for each order using the A* algorithm and compares them with delivery time limits.

## 💻 Usage

To use the project:
1. Compile and run the C++ files.
2. Input the required data for each test case as prompted.
3. The program will output the total minimum time required for delivering all orders efficiently, along with delivery details for each order.

## 🎉 Conclusion

The Food Polar Bear Route Optimization Project aims to optimize delivery routes for maximum efficiency in a grid-based city environment. By implementing algorithms such as Dijkstra's and A*, the project provides solutions to minimize travel time and ensure timely deliveries, benefiting both the delivery company and its customers.
