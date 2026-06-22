// Implement Those Functions
#include "RideAnalytics.h"
#include <iostream>
using namespace std;

// Add a new Trip
void RideAnalytics::addTrip(Trip trip)
{
    trips.push_back(trip);
}

// Display all trips
void RideAnalytics::displayTrips()
{
    for (auto &trip : trips)
    {
        cout << "rideID : " << trip.rideID << endl;
    }
}

// Return reference to trips vector
vector<Trip>& RideAnalytics ::getTrips()
{
    return trips;
}
 