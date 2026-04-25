class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
    int n = position.size();
    vector<pair<int, double>> cars;
    for (int i = 0; i < n; i++) {
        cars.push_back({position[i], (double)(target - position[i]) / speed[i]});
    }
    
    // sort position from big -> small
    sort(cars.rbegin(), cars.rend());
    
    int fleets = 0;
    double maxTime = 0.0;
    
    for (auto& car : cars) {
        if (car.second > maxTime) { // If this car takes more time than the fleet in front of it
            fleets++;               // It forms a new car fleet
            maxTime = car.second;   // Update the slowest time for the current fleet
        }
    }
    return fleets;
    }
};
