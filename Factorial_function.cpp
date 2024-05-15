//#include<iostream>
//#include<string>
//#include<cmath>
//using namespace std;
//
//const int MAX_RIDERS = 100;
//const int MAX_RESTAURANTS = 100;
//const int MAX_ORDERS_PER_RESTAURANT = 100;
//const int MAX_GRID_SIZE = 100;
//
//struct Rider {
//    int id;
//    int location;
//};
//
//struct Order {
//    string order_name;
//    int location;
//    int time_limit;
//    int assigned_rider;
//    int travel_distance;
//    Order() : order_name(""), location(0), time_limit(0), assigned_rider(-1), travel_distance(0) {}
//};
//
//struct Restaurant {
//    string name;
//    int location;
//    int total_orders;
//    Order orders[MAX_ORDERS_PER_RESTAURANT];
//};
//
//// Function to relax edge in Dijkstra's algorithm
//void relaxEdge(int dist[], int u, int v, int weight) {
//    if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
//        dist[v] = dist[u] + weight;
//    }
//}
//
//// Function to find minimum distance vertex
//int minimumDist(int dist[], bool visited[], int num_vertices) {
//    int min_dist = INT_MAX, min_index = -1;
//
//    for (int v = 0; v < num_vertices; ++v) {
//        if (!visited[v] && dist[v] < min_dist) {
//            min_dist = dist[v];
//            min_index = v;
//        }
//    }
//
//    return min_index;
//}
//
//// Dijkstra's algorithm implementation
//int Dijkstra(int size, int src, int dest) {
//    int num_vertices = size * size;
//    if (src < 0 || dest >= num_vertices) {
//        cout << "Out of range\n";
//        return INT_MAX;
//    }
//
//    int dist[MAX_GRID_SIZE * MAX_GRID_SIZE];
//    bool visited[MAX_GRID_SIZE * MAX_GRID_SIZE];
//
//    for (int i = 0; i < num_vertices; ++i) {
//        dist[i] = INT_MAX;
//        visited[i] = false;
//    }
//
//    dist[src] = 0;
//
//    for (int count = 0; count < num_vertices - 1; ++count) {
//        int u = minimumDist(dist, visited, num_vertices);
//        if (u == -1) break;
//        visited[u] = true;
//
//        int row = u / size, col = u % size;
//        int adj_positions[4][2] = { {row - 1, col}, {row + 1, col}, {row, col - 1}, {row, col + 1} };
//        for (auto& pos : adj_positions) {
//            int adj_row = pos[0], adj_col = pos[1];
//            if (adj_row >= 0 && adj_row < size && adj_col >= 0 && adj_col < size) {
//                int v = adj_row * size + adj_col;
//                relaxEdge(dist, u, v, 1);
//            }
//        }
//    }
//
//    int result = dist[dest];
//    return result;
//}
//
//void assignRidersAndCalculateDistances(Rider riders[], int num_riders, Restaurant restaurants[], int num_restaurants, int size) {
//    int total_travel_time = 0;
//    for (int i = 0; i < num_restaurants; i++) {
//        for (int j = 0; j < restaurants[i].total_orders; j++) {
//            Order& order = restaurants[i].orders[j];
//            int min_distance = INT_MAX;
//            int best_rider = -1;
//
//            for (int k = 0; k < num_riders; k++) {
//                int distance = Dijkstra(size, riders[k].location, order.location);
//                if (distance < min_distance) {
//                    min_distance = distance;
//                    best_rider = k;
//                }
//            }
//
//            order.assigned_rider = best_rider + 1;
//            order.travel_distance = min_distance;
//            total_travel_time += min_distance;
//            riders[best_rider].location = order.location;  // Update rider's location
//
//            cout << "Order " << order.order_name << " assigned to rider " << order.assigned_rider << " with travel distance " << order.travel_distance << endl;
//        }
//    }
//    cout << "\nTotal travel time for all orders: " << total_travel_time << endl;
//}
//
//void printGrid(int size, Rider riders[], int num_riders, Restaurant restaurants[], int num_restaurants) {
//    char grid[MAX_GRID_SIZE][MAX_GRID_SIZE] = {};
//
//    // Place riders on the grid
//    for (int i = 0; i < num_riders; i++) {
//        int x = riders[i].location / size;
//        int y = riders[i].location % size;
//        grid[x][y] = 'R'; // Representing Rider
//    }
//
//    // Print the grid
//    for (int i = 0; i < size; i++) {
//        for (int j = 0; j < size; j++) {
//            cout << grid[i][j] << "-";
//        }
//        cout << endl;
//    }
//}
//
//int main() {
//    int num_test_cases;
//    cout << "Enter the number of test cases: ";
//    cin >> num_test_cases;
//
//    for (int t = 0; t < num_test_cases; t++) {
//        cout << "\nRunning test case #" << (t + 1) << endl;
//
//        int size, num_riders, num_restaurants;
//        cout << "Enter the size of the grid (n x n): ";
//        cin >> size;
//        cout << "Enter the number of riders: ";
//        cin >> num_riders;
//        cout << "Enter the number of restaurants: ";
//        cin >> num_restaurants;
//
//        Rider riders[MAX_RIDERS];
//        for (int i = 0; i < num_riders; i++) {
//            riders[i].id = i + 1;
//            riders[i].location = 0;  // Assuming initial location is 0
//        }
//
//        Restaurant restaurants[MAX_RESTAURANTS];
//        for (int i = 0; i < num_restaurants; i++) {
//            cout << "Enter the name of restaurant " << i + 1 << ": ";
//            cin >> restaurants[i].name;
//            cout << "Enter the grid location of restaurant " << i + 1 << " (1 to " << (size * size) << "): ";
//            cin >> restaurants[i].location;
//            restaurants[i].location--;
//            cout << "Enter the number of orders for " << restaurants[i].name << ": ";
//            cin >> restaurants[i].total_orders;
//
//            for (int j = 0; j < restaurants[i].total_orders; j++) {
//                cout << "Enter name of order " << j + 1 << ": ";
//                cin >> restaurants[i].orders[j].order_name;
//                cout << "Enter pickup location for order " << j + 1 << " (1 to " << (size * size) << "): ";
//                cin >> restaurants[i].orders[j].location;
//                restaurants[i].orders[j].location--;
//                cout << "Enter delivery time limit (in minutes) for order " << j + 1 << ": ";
//                cin >> restaurants[i].orders[j].time_limit;
//            }
//        }
//
//        assignRidersAndCalculateDistances(riders, num_riders, restaurants, num_restaurants, size);
//        cout << "\nFinal grid positions:\n";
//        printGrid(size, riders, num_riders, restaurants, num_restaurants);
//    }
//
//    return 0;
//}
//
////
////////Test Cases 
////2
////5 2 2
////BurgerPalace 10 2
////Beef 7 5
////Zinger 15 8 
//// 
////PizzaPlanet 18 1
////Tikka 21 5
////5 2 1
////CurryHouse 10 3
////Chicken 2 7
////ButterChicken 18 5
////Biryani 15 2