
// Checks whether given partioned string is palindrome or not 
bool isPalindrome(string s, int start, int end){
    while(start <= end){
        if(s[start++] != s[end--]){
            return false;
        }
    }
    return true;
}

void palindromePart(int ind, string s, vector<string> &ds, vector<vector<string>> &res){
    // Base - when we reach at the end of string
    if(ind == s.size()){
        res.push_back(ds);
        return;
    }
    
    // Iterate the string from ind to n-1 and check where we can put the partitions
    for(int i = ind; i < s.size(); ++i){
        if(isPalindrome(s, ind, i)){
            ds.push_back(s.substr(ind, i - ind + 1));
            palindromePart(i+1, s, ds, res);
            ds.pop_back();
        }
    }
}

int main()
{
    string s = "aabb";
    
    vector<vector<string>> res;
    vector<string> ds;
    
    palindromePart(0, s, ds, res);
    
    for(auto it : res){
        for(auto s : it){
            cout<<s<<" ";
        }
        cout<<endl;
    }
    return 0;
}
