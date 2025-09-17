class FoodRatings {
public:
    map<string,int> mp;
    map<string,string> mpc;
    map<string,set<pair<int,string>>>mpv;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i =0;i<foods.size();i++)
        {
            mp[foods[i]] = ratings[i];
            mpc[foods[i]]= cuisines[i];
            mpv[cuisines[i]].insert({-ratings[i],foods[i]});
        }
        
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = mpc[food];
        mpv[cuisine].erase({-mp[food],food});
        mpv[cuisine].insert({-newRating,food});
        mp[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        auto x = mpv[cuisine].begin();
        string ans = x->second; 
        return ans;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */