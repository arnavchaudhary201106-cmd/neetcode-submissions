class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int , int>forS;
        unordered_map<int , int>forT;
        for(int i =0;i<s.size();i++){
            forS[s[i]]++;
        }
        for(int i = 0;i<t.size();i++){
            forT[t[i]]++;
        }
        if(forS==forT){
        return true;
        }
        else{
            return false;
            }
    }

};
