class Spreadsheet {
public:
    vector<vector<int>>sheets;
    Spreadsheet(int rows) {
        sheets.resize(rows+1,vector<int>(26,0));
    }
    
    void setCell(string cell, int value) {
        int col = (int)(cell[0]-'A');
        int row = stoi(cell.substr(1));
        sheets[row][col] = value;
    }
    
    void resetCell(string cell) {
        int col = (int)(cell[0]-'A');
        int row = stoi(cell.substr(1));
        sheets[row][col] = 0;
    }
    int findNumber(string s)
    {
        if(isdigit(s[0]))
        {
            return stoi(s);
        }
        int col = (int)(s[0]-'A');
        int row = stoi(s.substr(1));
        return sheets[row][col];
    }
    int getValue(string formula) {
        bool found = false;
        string str1 = "", str2="";
        for(int i = 1;i<formula.size();i++)
        {
            if(formula[i] == '+')
            {
                found = true;
                continue;
            }
            if(!found)
            {
                str1 +=formula[i]; 
            }
            else
            {
                str2 +=formula[i];
            }
        }
        int n1 = findNumber(str1);
        int n2 = findNumber(str2);
        // cout<<n1<<n2<<endl;
        return n1+n2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */