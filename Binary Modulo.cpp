class Solution{
    public:
      int modulo(string s,int m)
        {
            //code here
            long long int num = 0;
            long long int digit = 0;
            int n = s.size();
            long long fact = 1;
            for(int i=n-1;i>=0;i--){
                digit = s[i]-'0';
                num+=(digit*fact)%m;
                fact=(fact*2)%m;
            }
            return num%m ;
        }
};
