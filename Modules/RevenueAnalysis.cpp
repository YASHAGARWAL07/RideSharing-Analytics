#include "../Trip.h"
#include "../RideAnalytics.h"
#include<algorithm>
#include<vector>
#include<numeric>
#include<iostream>

/*
1. Total Revenue
2. Prefix Sum
3. Sliding Window
4. Kadane's Algorithm
*/
 
void calculateTotalRevenue(RideAnalytics &analytics)
{
    vector<Trip> trips = analytics.getTrips();

    double totalRevenue=0;
    for(auto &trip : analytics.getTrips())
    {
        if(!trip.cancelled)
        {
            totalRevenue + = trip.fare;
        }
    }
    cout<<"Total Revenue: "<<totalRevenue<<endl;
}

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
    

void averageRevenue(RideAnalytics &analytics)
{
    vector<Trip> trips = analytics.getTrips();

    int k;
    cout<<"Enter window size: "<<endl;
    cin>>k;
    if(k>0 && k<= trips.size()){
        double sum=0;
       
        for(int i=0;i<k;i++){
            sum+=trips[i].fare;
        }
        double maxAverage=sum/k;
        int start=0;
        for(int i=k;i<trip.size();i++){
            sum=sum-trips[i-k].fare+trips[i].fare;
            double newAverage=sum/k;
            if(newAverage>maxAverage){
                maxAverage=newAverage;
                start=i-k+1;
            }
        }
        cout<<"Best Window starts from Ride: "<< start+1<<endl;
        cout<<" Maximum Average revenue in period k: "<< maxAverage <<endl;

        else{
            cout<<"Invalid window size"
        }
    }
}

void maximumRevenuePeriod(RideAnalytics &analytics)
{
    vector<Trip> trips = analytics.getTrips();

    double currentRevenue = 0;
    double maxRevenue = 0;

    int start = 0;
    int end = 0;
    int tempStart = 0;

    for(int i=0; i<trips.size();i++){
        currentRevenue += trips[i].fare;
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
    cout<<"Maximum Revenue: "<< maxRevenue <<endl;
    cout<<"Maximum Revenue Period: Ride "<< start + 1 <<"to Ride "<< end + 1 <<endl;
}
