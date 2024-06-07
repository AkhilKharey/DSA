// class Solution{
//   public:--------------------------------APPROACH 1
  
//     //Function to find starting point where the truck can start to get through
//     //the complete circle without exhausting its petrol in between.
//     int tour(petrolPump p[],int n)
//     {
//        //Your code here
//        int total=0;
//        int current=0;
//        int start=0;
//        for(int i=0;i<n;i++)
//        {
//            total+=p[i].petrol-p[i].distance;
//            current+=p[i].petrol -p[i].distance;
//            if(current<0)
//            {
//                current=0;
//                start=i+1;
//            }
//        }
//        if(total<0)
//        return -1;
//        return start;
//     }

