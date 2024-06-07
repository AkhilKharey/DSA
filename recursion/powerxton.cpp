class Solution {
public:
double exp(double x,int n)
{
   if(n==0)
        return 1;
        if(n==1)
        return x;
        double ans=myPow(x,n/2);        
        if(n%2==0)
        return ans*ans;
        else
        return x*ans*ans;
}
    double myPow(double x, int n) {
        if (n>0)
        return exp(x,n);
        else
       return 1/exp(x,abs(n));  //if n is negative
      
    }
};