sdkjeke
bool isStraightHand(int N, int groupSize, vector<int> &hand) {
        if(N%groupSize!=0) return false;
        map<int,int> m;
        for(auto i:hand) m[i]++;
        while(!m.empty()){
            auto itr=m.begin();
            int k=itr->first;
            for(int i=0;i<groupSize;i++){
                if(m.count(k+i)==0) return false;
                else {m[k+i]--; if(m[k+i]==0) m.erase(k+i);}
            }
        }
       return true;
    }
