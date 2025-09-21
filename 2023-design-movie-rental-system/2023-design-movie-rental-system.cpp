class MovieRentingSystem {
public:
    map<int,set<pair<int,int>>>unrented; // movie ->[price,shop]
    map<pair<int,int>,int> db; // [shop,movie] -> price 
    set<pair<int,pair<int,int>>> rented; // [price,[shop,movie]]
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto x: entries)
        {
            int shop= x[0], movie= x[1], price = x[2];
            // cout<<shop<<" "<<movie<<" "<<price<<endl;
            unrented[movie].insert({price,shop});
            db[{shop,movie}] = price;
            // rented.insert({price,{shop,movie}});
        }
    }
    
    vector<int> search(int movie) {
        auto data = unrented[movie];
        vector<int> ans;
        int count = 0;

        for (auto it = data.begin(); it != data.end() && count < 5; ++it, ++count) {
            ans.push_back(it->second);  
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        int price = db[{shop,movie}];
        unrented[movie].erase({price,shop});
        rented.insert({price,{shop,movie}});
    }
    
    void drop(int shop, int movie) {
        int price = db[{shop,movie}];
        rented.erase({price,{shop,movie}});
        unrented[movie].insert({price,shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        int count = 0;
        for(auto it = rented.begin();it!=rented.end() && count<5 ;++it,++count)
        {
            int shop = it->second.first;
            int movie = it->second.second;
            // cout<<shop<<" "<<movie<<endl;
            ans.push_back({shop,movie});
        }
        
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */