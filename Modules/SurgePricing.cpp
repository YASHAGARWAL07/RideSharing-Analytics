#include "../Trip.h"
#include "../RideAnalytics.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

/*
1. Difference Array
2. Zone Analysis
3. Reports
*/

// Difference Array
void surgePricingSimulation(RideAnalytics &analytics)
{
    vector<Trip> &trips = analytics.getTrips();

    if(trips.empty())
    {
        cout << "No Trips Available!" << endl;
        return;
    }

    int n = trips.size();

    // Difference Array
    vector<double> diff(n, 0);

    int left, right;
    double surge;

    cout << "\n----- Surge Pricing Simulation -----" << endl;
    cout << "Enter Starting Ride Index : ";
    cin >> left;

    cout << "Enter Ending Ride Index : ";
    cin >> right;

    cout << "Enter Surge Amount : ";
    cin >> surge;

    if(left < 0 || right >= n || left > right)
    {
        cout << "Invalid Range!" << endl;
        return;
    }

    // Range Update
    diff[left] += surge;

    if(right + 1 < n)
    {
        diff[right + 1] -= surge;
    }

    // Prefix Sum
    for(int i = 1; i < n; i++)
    {
        diff[i] += diff[i - 1];
    }

    cout << "\n----- Updated Fares -----" << endl;

    for(int i = 0; i < n; i++)
    {
        double updatedFare = trips[i].fare + diff[i];

        cout << "Ride ID : " << trips[i].rideID
             << "  Old Fare : " << trips[i].fare
             << "  New Fare : " << updatedFare
             << endl;
    }
}


// Zone Analysis
void zoneWiseAnalysis(RideAnalytics &analytics)
{
    vector<Trip> &trips = analytics.getTrips();

    if(trips.empty())
    {
        cout << "No Trips Available!" << endl;
        return;
    }

    map<string, int> totalRides;
    map<string, double> totalRevenue;
    map<string, double> totalRating;

    for(auto &trip : trips)
    {
        totalRides[trip.zone]++;

        if(!trip.cancelled)
        {
            totalRevenue[trip.zone] += trip.fare;
        }

        totalRating[trip.zone] += trip.rating;
    }

    cout << "\n----- Zone Wise Analysis -----" << endl;

    for(auto &zone : totalRides)
    {
        double averageRating = totalRating[zone.first] / totalRides[zone.first];

        cout << "Zone : " << zone.first << endl;
        cout << "Total Rides : " << totalRides[zone.first] << endl;
        cout << "Revenue : Rs. " << totalRevenue[zone.first] << endl;
        cout << "Average Rating : " << averageRating << endl;
        cout << "----------------------------" << endl;
    }
}


// Generate Report
void generateReport(RideAnalytics &analytics)
{
    vector<Trip> &trips = analytics.getTrips();

    if(trips.empty())
    {
        cout << "No Trips Available!" << endl;
        return;
    }

    int totalRides = trips.size();
    int cancelledRides = 0;

    double totalRevenue = 0;
    double totalRating = 0;

    double highestFare = trips[0].fare;
    double lowestFare = trips[0].fare;

    for(auto &trip : trips)
    {
        if(trip.cancelled)
        {
            cancelledRides++;
        }
        else
        {
            totalRevenue += trip.fare;
        }

        totalRating += trip.rating;

        if(trip.fare > highestFare)
        {
            highestFare = trip.fare;
        }

        if(trip.fare < lowestFare)
        {
            lowestFare = trip.fare;
        }
    }

    cout << "\n========================================" << endl;
    cout << "       RIDE SHARING ANALYTICS REPORT" << endl;
    cout << "========================================" << endl;
    cout << "Total Rides : " << totalRides << endl;
    cout << "Completed Rides : " << totalRides - cancelledRides << endl;
    cout << "Cancelled Rides : " << cancelledRides << endl;
    cout << "Total Revenue : Rs. " << totalRevenue << endl;
    cout << "Average Rating : " << totalRating / totalRides << endl;
    cout << "Highest Fare : Rs. " << highestFare << endl;
    cout << "Lowest Fare : Rs. " << lowestFare << endl;
    cout << "========================================" << endl;
}