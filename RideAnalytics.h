// Declares all functions
#ifndef RIDE_ANALYTICS_H
#define RIDE_ANALYTICS_H

#include <iostream>
#include <vector>
#include "Trip.h"
using namespace std;

class RideAnalytics
{
private:
    vector<Trip> trips;

public:
    // Add a new Trip
    void addTrip(Trip trip);

    // Display all Trips
    void displayTrips();

    // Return Trip list
    vector<Trip> &getTrips();
};

#endif
