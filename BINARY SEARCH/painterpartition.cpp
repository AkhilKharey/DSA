// https://practice.geeksforgeeks.org/problems/the-painters-partition-problem1535/1
bool isPossible(int arr[],int n,int k ,long long int mid)
    {
        int painter=1;
        long long tempsum=0;
        for(int i=0;i<n;i++)
        {
            tempsum=tempsum+arr[i];
            if(arr[i]>mid)
            return false;
            if(tempsum>mid)
            {
                painter++;
                tempsum=arr[i];
            }
            
        }
        if(painter<=k)
            return true;
        return false;
    }
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        long long int sum=0;
        long long int min=arr[0];
        for(int i=0;i<n;i++)
        {
            sum=sum+arr[i];
            if(arr[i]<min)
            {
             min=arr[i];
            }
        }
       long long int s=min;
       long long int e=sum;
        long long int mid=s+(e-s)/2;
        long long int ans=-1;
        while(s<=e)
        {
            if(isPossible(arr,n,k,mid))
            {
                ans=mid;
                e=mid-1;
            }
            else
            s=mid+1;
            mid=s+(e-s)/2;
            
        }
        return ans;