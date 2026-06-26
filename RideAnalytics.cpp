// Implement Those Functions
#include "RideAnalytics.h"
#include <iostream>
using namespace std;  scope resolution operator

// Add a new Trip
void RideAnalytics::addTrip(Trip trip)
{
    trips.push_back(trip);
}

// Display all trips
void RideAnalytics::displayTrips()
{
    int i=0;
    for (auto &trip : trips). //for(int i=0;i<n;i++)
    {   
        cout<<"Ride"<<i++<<"  ";
        cout << "rideID : " << trip.rideID << endl;
        cout << "driverID : " << trip.driverID << endl;
    }
}

// Return reference to trips vector
vector<Trip>& RideAnalytics ::getTrips()
{
    return trips;
}
