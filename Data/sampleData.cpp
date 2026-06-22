// Contains Sample Rides
#include "../RideAnalytics.h"
#include <vector>
#include <iostream>
using namespace std;

vector<Trip> sampleTrips =
    {
        // rideID, driverID, fare, rating, zone, distance, cancelled

        {101, 1, 120, 4.8, "North", 5.2, false},
        {102, 2, 250, 4.5, "South", 8.1, false},
        {103, 1, 180, 4.7, "East", 6.4, false},
        {104, 3, 300, 4.9, "West", 10.2, false},
        {105, 2, 150, 4.1, "North", 4.8, true},

        {106, 4, 400, 5.0, "South", 12.3, false},
        {107, 3, 220, 4.3, "East", 7.5, false},
        {108, 1, 175, 4.6, "West", 5.9, false},
        {109, 4, 350, 4.8, "North", 11.0, false},
        {110, 2, 130, 3.9, "South", 3.7, true},

        {111, 5, 500, 5.0, "Airport", 15.6, false},
        {112, 3, 280, 4.4, "East", 9.2, false},
        {113, 6, 90, 3.8, "North", 2.5, false},
        {114, 5, 450, 4.9, "Airport", 14.1, false},
        {115, 1, 210, 4.7, "West", 7.8, false},

        {116, 6, 160, 4.0, "South", 5.0, true},
        {117, 4, 380, 4.8, "Airport", 13.4, false},
        {118, 2, 145, 4.2, "North", 4.1, false},
        {119, 3, 260, 4.5, "East", 8.7, false},
        {120, 5, 550, 5.0, "Airport", 17.3, false}}
