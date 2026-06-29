#include "RideAnalytics.h"

// Forward declarations of all module functions
extern vector<Trip> sampleTrips;

// RevenueAnalysis.cpp
void calculateTotalRevenue(RideAnalytics &analytics);
void revenueRangeQuery(RideAnalytics &analytics);
void averageRevenue(RideAnalytics &analytics);
void maximumRevenuePeriod(RideAnalytics &analytics);

// DriverAnalytics.cpp
void driverStatistics(RideAnalytics &analytics);
void sortDriversByRating(RideAnalytics &analytics);
void topDrivers(RideAnalytics &analytics);
void highestRatedDriver(RideAnalytics &analytics);
void countHighRatedTrips(RideAnalytics &analytics);

// SearchAndFilter.cpp
void searchTripsByFare(RideAnalytics &analytics);
void findCheapestRide(RideAnalytics &analytics);
void removeCancelledTrips(RideAnalytics &analytics);
void filterRidesByZone(RideAnalytics &analytics);
void filterRidesByRating(RideAnalytics &analytics);

// SurgePricing.cpp
void surgePricingSimulation(RideAnalytics &analytics);
void zoneWiseAnalysis(RideAnalytics &analytics);
void generateReport(RideAnalytics &analytics);

int main()
{
    RideAnalytics analytics;

    // Load sample data
    for (auto &trip : sampleTrips)
        analytics.addTrip(trip);

    // menu
    int choice;
    do
    {
        cout << "\n========================================" << endl;
        cout << "     RIDE SHARING ANALYTICS SYSTEM      " << endl;
        cout << "========================================" << endl;
        cout << "  1. Display All Trips" << endl;
        cout << "  --- Revenue Analysis ---" << endl;
        cout << "  2. Total Revenue" << endl;
        cout << "  3. Revenue Range Query (Prefix Sum)" << endl;
        cout << "  4. Average Revenue per Window (Sliding Window)" << endl;
        cout << "  5. Maximum Revenue Period (Kadane)" << endl;
        cout << "  --- Driver Analytics ---" << endl;
        cout << "  6. Driver Statistics" << endl;
        cout << "  7. Sort Rides by Rating" << endl;
        cout << "  8. Top K Drivers" << endl;
        cout << "  9. Highest Rated Driver" << endl;
        cout << "  10. Count High Rated Trips" << endl;
        cout << "  --- Search & Filter ---" << endl;
        cout << "  11. Search Trip by Fare (Binary Search)" << endl;
        cout << "  12. Find Cheapest Ride" << endl;
        cout << "  13. Remove Cancelled Trips" << endl;
        cout << "  14. Filter Rides by Zone" << endl;
        cout << "  15. Filter Rides by Rating" << endl;
        cout << "  --- Surge Pricing & Reports ---" << endl;
        cout << "  16. Surge Pricing Simulation" << endl;
        cout << "  17. Zone-wise Analysis" << endl;
        cout << "  18. Generate Full Report" << endl;
        cout << "  0. Exit" << endl;
        cout << "========================================" << endl;
        cout << "Enter choice : ";
        cin >> choice;

        switch (choice)
        {
            case 1:  analytics.displayTrips();           break;
            case 2:  calculateTotalRevenue(analytics);   break;
            case 3:  revenueRangeQuery(analytics);       break;
            case 4:  averageRevenue(analytics);          break;
            case 5:  maximumRevenuePeriod(analytics);    break;
            case 6:  driverStatistics(analytics);        break;
            case 7:  sortDriversByRating(analytics);     break;
            case 8:  topDrivers(analytics);              break;
            case 9:  highestRatedDriver(analytics);      break;
            case 10: countHighRatedTrips(analytics);     break;
            case 11: searchTripsByFare(analytics);       break;
            case 12: findCheapestRide(analytics);        break;
            case 13: removeCancelledTrips(analytics);    break;
            case 14: filterRidesByZone(analytics);       break;
            case 15: filterRidesByRating(analytics);     break;
            case 16: surgePricingSimulation(analytics);  break;
            case 17: zoneWiseAnalysis(analytics);        break;
            case 18: generateReport(analytics);          break;
            case 0:  cout << "Exiting... Goodbye!" << endl; break;
            default: cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 0);

    return 0;
}
