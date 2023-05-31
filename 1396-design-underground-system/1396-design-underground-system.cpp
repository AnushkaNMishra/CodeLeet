// class UndergroundSystem {
// public:
//     UndergroundSystem() {
        
//     }
    
//     void checkIn(int id, string stationName, int t) {
        
//     }
    
//     void checkOut(int id, string stationName, int t) {
        
//     }
    
//     double getAverageTime(string startStation, string endStation) {
        
//     }
// };

// /**
//  * Your UndergroundSystem object will be instantiated and called as such:
//  * UndergroundSystem* obj = new UndergroundSystem();
//  * obj->checkIn(id,stationName,t);
//  * obj->checkOut(id,stationName,t);
//  * double param_3 = obj->getAverageTime(startStation,endStation);
//  */

class UndergroundSystem {
public:
    map<int,pair<string,int>>m;
    map<pair<string,string>,vector<double>>av ;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        m[id] = make_pair(stationName , t);
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string,string>p =make_pair(m[id].first , stationName);
        av[p].push_back(t - m[id].second);
    }
    
    double getAverageTime(string startStation, string endStation) {
        double sum = 0 ;
        vector<double>v = av[make_pair(startStation , endStation)] ;
        for(auto x : v){
            sum += x ;
        }

        return sum / v.size();
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */