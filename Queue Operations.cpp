  public:
    void insert(queue<int> &q, int k) {
        q.push(k);
    }
   
    int findFrequency(queue<int> q, int k){
        int count = 0;
        
        while(!q.empty()) {
            if(q.front() == k)
                count++;
                
            q.pop();
        }
        
        return count;
    }
    
};
