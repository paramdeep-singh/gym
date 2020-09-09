#include <bits/stdc++.h>

using namespace std;

int minCostForTrips(
    int totalTrips, 
    int specialTicketTrips, 
    int normalTicketCost, 
    int specialTicketCost
) {
    if (specialTicketTrips >= totalTrips) {
        return min(specialTicketCost, totalTrips * normalTicketCost);
    }

    double normalTicketCostPerTrip = normalTicketCost;
    double specialTicketCostPerTrip = 
        specialTicketCost / (double) specialTicketTrips;
    if (normalTicketCostPerTrip <= specialTicketCostPerTrip) {
        return totalTrips * normalTicketCostPerTrip;
    } else {
        int specialTicketTotalCost = 
            (totalTrips / specialTicketTrips) * specialTicketCost;
        return specialTicketTotalCost + minCostForTrips(
            totalTrips % specialTicketTrips,
            specialTicketTrips,
            normalTicketCost,
            specialTicketCost
        );
    }
}

int main() {
    int totalTrips, specialTicketTrips, normalTicketCost, specialTicketCost;
    scanf("%d %d %d %d", 
        &totalTrips, 
        &specialTicketTrips, 
        &normalTicketCost, 
        &specialTicketCost
    );
    
    printf("%d", minCostForTrips(
        totalTrips, 
        specialTicketTrips, 
        normalTicketCost, 
        specialTicketCost
    ));

    return 0;
}