// Perform BFS (bcoz we want shorter sequence)

class Solution {
public:
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // unordered set for storing the wordlist
        unordered_set<string> seq(wordList.begin(),wordList.end());
        // Create a queue to track states for BFS traversal
        queue<pair<string,int>> q;
        // Add {beginWord, 1} to queue
        q.push({beginWord,1}); 
        // Iterate theough the queue
        while(!q.empty())
        {
            // extract steps, string from queue front
            string currWord = q.front().first;
            int steps = q.front().second;
            q.pop();
            // if front element is endWord return the steps
            if(currWord == endWord)
            return steps;
            // if not then pop out the string from set
            seq.erase(currWord);
            // for each string in the queue, do the following
            for(int i =0;i<currWord.size();i++)
            {
                // saving currWord for future use
                char c = currWord[i];
                // Replace each character of the string with characters 'a' to 'z' and check whether they are present in the set
                for(char k = 'a';k<='z';k++ )
                {
                    // if new word is present in set, add to queue
                    currWord[i] = k;
                    if(seq.find(currWord)!= seq.end())
                    q.push({currWord,steps+1}); 

                }
                // REstoring the initialcharacter
                currWord[i]  = c;
                
            }
                

        }
        return 0;
            
    }
};