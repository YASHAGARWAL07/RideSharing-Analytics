// Defining Trip class
#ifndef TRIP_H
#define TRIP_H

#include <iostream>
#include <string>
using namespace std;
class Trip
{
public:
    int rideID;
    int driverID;
    double fare; 
    double rating;
    string zone;
    double distance;
    bool cancelled;
 
    // Constructor
    Trip(int rideID,
         int driverID,
         double fare,
         double rating,
         string zone,
         double distance,
         bool cancelled)
    {
        this->rideID = rideID;
        this->driverID = driverID;
        this->fare = fare;
        this->rating = rating;
        this->zone = zone;
        this->distance = distance;
        this->cancelled = cancelled;
    }
};

#endif
