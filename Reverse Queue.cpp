queue<int> rev(queue<int> q)
    {
        // add code here.
        queue<int> que;
        vector<int>v;
        for(int i = q.size(); i!=NULL; i--){
            v.push_back(q.front());
            q.pop();
        }
        for(int i = v.size()-1; i>=0; i--) que.push(v[i]);
        return que;
    }
