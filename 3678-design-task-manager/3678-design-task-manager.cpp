class TaskManager {
public:
    set<pair<int,int>> spt;
    map<int,int>tp,tu;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto x: tasks)
        {
            spt.insert({-x[2],-x[1]});
            tu[x[1]] = x[0];
            tp[x[1]] = x[2];
        }
    }
    
    void add(int userId, int taskId, int priority) {
        spt.insert({-priority,-taskId});
        tu[taskId] = userId;
        tp[taskId] = priority;
    }
    
    void edit(int taskId, int newPriority) {
        spt.erase({-tp[taskId],-taskId});
        spt.insert({-newPriority,-taskId});
        tp[taskId] = newPriority;
    }
    
    void rmv(int taskId) {
        spt.erase({-tp[taskId],-taskId});
        tu.erase(taskId);
        tp.erase(taskId);
    }
    
    int execTop() {
        if(spt.size()>0)
        {
            int taskId = -1*(spt.begin()->second);
            int userId = tu[taskId];
            rmv(taskId);
            return userId;
        }
        return -1;
        
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */