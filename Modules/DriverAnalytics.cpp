#include "../Trip.h"
#include "../RideAnalytics.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

/*
1. Driver Statistics
2. Sorting
3. Partial_sort
4. Count if
*/

// Driver Statistics
void driverStatistics(RideAnalytics &analytics)
{
    vector<Trip> &trips = analytics.getTrips();

    if(trips.empty())
    {
        cout << "No Trips Available!" << endl;
        return;
    }

    map<int, int> totalRides;
    map<int, double> totalRevenue;

    for(auto &trip : trips)
    {
        totalRides[trip.driverID]++;

        if(!trip.cancelled)
        {
            totalRevenue[trip.driverID] += trip.fare;
        }
    }

    cout << "\n----- Driver Statistics -----" << endl;

    for(auto &driver : totalRides)
    {
        cout << "Driver ID : " << driver.first << endl;
        cout << "Total Rides : " << driver.second << endl;
        cout << "Revenue : " << totalRevenue[driver.first] << endl;
        cout << "---------------------------" << endl;
    }
}


// Sort Rides by Rating
void sortDriversByRating(RideAnalytics &analytics)
{
    vector<Trip> trips = analytics.getTrips();

    sort(trips.begin(), trips.end(), [](Trip a, Trip b)
    {
        return a.rating > b.rating;
    });

    cout << "\n----- Rides Sorted By Rating -----" << endl;

    for(auto &trip : trips)
    {
        cout << "Ride ID : " << trip.rideID
             << "  Driver ID : " << trip.driverID
             << "  Rating : " << trip.rating
             << "  Fare : " << trip.fare
             << endl;
    }
}


// Top K Drivers
void topDrivers(RideAnalytics &analytics)
{
    vector<Trip> trips = analytics.getTrips();

    if(trips.empty())
    {
        cout << "No Trips Available!" << endl;
        return;
    }

    int k;

    cout << "Enter K : ";
    cin >> k;

    if(k <= 0)
    {
        cout << "Invalid Value!" << endl;
        return;
    }

    if(k > trips.size())
    {
        k = trips.size();
    }

    partial_sort(trips.begin(), trips.begin() + k, trips.end(), [](Trip a, Trip b)
    {
        return a.rating > b.rating;
    });

    cout << "\n----- Top " << k << " Drivers -----" << endl;

    for(int i = 0; i < k; i++)
    {
        cout << "Driver ID : " << trips[i].driverID
             << "  Rating : " << trips[i].rating
             << "  Ride ID : " << trips[i].rideID
             << endl;
    }
}


// Highest Rated Driver
void highestRatedDriver(RideAnalytics &analytics)
{
    vector<Trip> &trips = analytics.getTrips();

    if(trips.empty())
    {
        cout << "No Trips Available!" << endl;
        return;
    }

    auto best = max_element(trips.begin(), trips.end(), [](Trip a, Trip b)
    {
        return a.rating < b.rating;
    });

    cout << "\n----- Highest Rated Driver -----" << endl;
    cout << "Ride ID : " << best->rideID << endl;
    cout << "Driver ID : " << best->driverID << endl;
    cout << "Rating : " << best->rating << endl;
    cout << "Fare : " << best->fare << endl;
    cout << "Zone : " << best->zone << endl;
}


// Count High Rated Trips
void countHighRatedTrips(RideAnalytics &analytics)
{
    vector<Trip> &trips = analytics.getTrips();

    double rating;

    cout << "Enter Minimum Rating : ";
    cin >> rating;

    int count = count_if(trips.begin(), trips.end(), [rating](Trip trip)
    {
        return trip.rating >= rating;
    });

    cout << "Total High Rated Trips : " << count << endl;
}