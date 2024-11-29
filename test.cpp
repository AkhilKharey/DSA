#include <iostream>
#include <vector>
#include <algorithm>

// Function to calculate the maximum system throughput
long long getMaxThroughput(std::vector<int> &host_throughput)
{
    // Sort the host throughputs in ascending order
    std::sort(host_throughput.begin(), host_throughput.end());

    int n = host_throughput.size(); // Number of host servers
    int k = n / 3;                  // Maximum number of clusters
    long long total_throughput = 0; // Variable to store the total system throughput

    // Loop over the number of clusters
    for (int i = 0; i < k; ++i)
    {
        // Add the median of each cluster to the total throughput
        total_throughput += host_throughput[n - 2 * i - 2];
    }

    return total_throughput;
}

int main()
{
    int n; // Number of host servers
    std::cin >> n;

    std::vector<int> host_throughput(n); // Vector to store the throughput of each host server

    // Input the throughput values
    for (int i = 0; i < n; ++i)
    {
        std::cin >> host_throughput[i];
    }

    // Calculate and output the maximum system throughput
    std::cout << getMaxThroughput(host_throughput) << std::endl;

    return 0;
}