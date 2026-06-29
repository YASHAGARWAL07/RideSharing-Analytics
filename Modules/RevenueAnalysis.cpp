#include "../Trip.h"
#include "../RideAnalytics.h"
#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

/*
1. Total Revenue
2. Prefix Sum
3. Sliding Window
4. Kadane's Algorithm
*/

// Total Revenue
void calculateTotalRevenue(RideAnalytics &analytics)
{
    vector<Trip> &trips = analytics.getTrips();

    double totalRevenue = 0;

    for(auto &trip : trips)
    {
        if(!trip.cancelled)
        {
            totalRevenue += trip.fare;
        }
    }

    cout << "\n----- Total Revenue -----" << endl;
    cout << "Total Revenue : Rs. " << totalRevenue << endl;
}


// Prefix Sum
void revenueRangeQuery(RideAnalytics &analytics)
{
    vector<Trip> &trips = analytics.getTrips();

    if(trips.empty())
    {
        cout << "No Trips Available!" << endl;
        return;
    }

    int n = trips.size();

    vector<double> prefix(n + 1, 0);

    for(int i = 0; i < n; i++)
    {
        if(trips[i].cancelled)
            prefix[i + 1] = prefix[i];
        else
            prefix[i + 1] = prefix[i] + trips[i].fare;
    }

    int left, right;

    cout << "\n----- Revenue Range Query -----" << endl;
    cout << "Enter Left Index : ";
    cin >> left;

    cout << "Enter Right Index : ";
    cin >> right;

    if(left < 0 || right >= n || left > right)
    {
        cout << "Invalid Range!" << endl;
        return;
    }

    double revenue = prefix[right + 1] - prefix[left];

    cout << "Revenue : Rs. " << revenue << endl;
}


// Sliding Window
void averageRevenue(RideAnalytics &analytics)
{
    vector<Trip> &trips = analytics.getTrips();

    if(trips.empty())
    {
        cout << "No Trips Available!" << endl;
        return;
    }

    int k;

    cout << "\nEnter Window Size : ";
    cin >> k;

    if(k <= 0 || k > trips.size())
    {
        cout << "Invalid Window Size!" << endl;
        return;
    }

    double sum = 0;

    for(int i = 0; i < k; i++)
    {
        if(!trips[i].cancelled)
            sum += trips[i].fare;
    }

    double maxAverage = sum / k;
    int start = 0;

    for(int i = k; i < trips.size(); i++)
    {
        if(!trips[i].cancelled)
            sum += trips[i].fare;

        if(!trips[i - k].cancelled)
            sum -= trips[i - k].fare;

        double average = sum / k;

        if(average > maxAverage)
        {
            maxAverage = average;
            start = i - k + 1;
        }
    }

    cout << "\n----- Sliding Window -----" << endl;
    cout << "Best Window Starts From Ride : " << start + 1 << endl;
    cout << "Maximum Average Revenue : Rs. " << maxAverage << endl;
}


// Kadane's Algorithm
void maximumRevenuePeriod(RideAnalytics &analytics)
{
    vector<Trip> &trips = analytics.getTrips();

    if(trips.empty())
    {
        cout << "No Trips Available!" << endl;
        return;
    }

    double currentRevenue = 0;
    double maxRevenue = 0;

    int start = 0;
    int end = 0;
    int tempStart = 0;

    for(int i = 0; i < trips.size(); i++)
    {
        if(!trips[i].cancelled)
        {
            currentRevenue += trips[i].fare;
        }

        if(currentRevenue > maxRevenue)
        {
            maxRevenue = currentRevenue;
            start = tempStart;
            end = i;
        }

        if(currentRevenue < 0)
        {
            currentRevenue = 0;
            tempStart = i + 1;
        }
    }

    cout << "\n----- Maximum Revenue Period -----" << endl;
    cout << "Best Revenue Period : Ride " << start + 1
         << " to Ride " << end + 1 << endl;

    cout << "Maximum Revenue : Rs. " << maxRevenue << endl;
}
