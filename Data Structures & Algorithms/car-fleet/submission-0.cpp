class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
     vector<pair<int, double>> cars;
        for(int i =0;i<position.size();i++){
            double time = double(target-position[i])/speed[i];
            cars.push_back({position[i],time});
        }
        sort(cars.rbegin(),cars.rend());
        int fleets = 0;
        double lastTime = 0;
        for(auto &c : cars){
          double currTime = c.second;
          if(lastTime<currTime){
            fleets++;
            lastTime  = currTime;
          }
        }
        return fleets;
    }
    
};
