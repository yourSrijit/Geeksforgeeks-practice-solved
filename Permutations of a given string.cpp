    public:
        vector<string>find_permutation(string S)
        {
            // Code here there
            set<string> ans;
            sort(S.begin(), S.end());
            do {
                ans.insert(S);
            }while(next_permutation(S.begin(), S.end()));
            vector<string> res(ans.begin(), ans.end());
            
            return res;
        }
