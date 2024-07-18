class Solution
{
public:
    // -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --APPROACH 1

    // Function to find starting point where the truck can start to get through
    // the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[], int n)
    {
        // Your code here
        int total = 0;
        int current = 0;
        int start = 0;
        for (int i = 0; i < n; i++)
        {
            total += p[i].petrol - p[i].distance;
            current += p[i].petrol - p[i].distance;
            // negative mtlb petrol khatam hogya raste me to starting point krna padega
            // aur current petrol ko wapas se 0 kar denge
            if (current < 0)
            {
                current = 0;
                start = i + 1;
            }
        }
        // total sirf check krne k liye hai ki ans possible h ya ni agar total petrol
        //  total distance se jada  hoga to ans -1 hoga
        if (total < 0)
            return -1;
        return start;
    }
