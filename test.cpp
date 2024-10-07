#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Define a structure to hold pod information
struct Pod
{
    int count; // Current number of pods
    int cost;  // Cost to increment the pod count by 1
    int index; // Original index to maintain mapping
};

// Function to calculate the minimum total cost
int minCost(vector<int> &pods, vector<int> &cost)
{
    int n = pods.size();
    vector<Pod> podList(n);

    // Create a list of pods with their counts, costs, and original indices
    for (int i = 0; i < n; ++i)
    {
        podList[i] = {pods[i], cost[i], i};
    }

    // Group pods by their counts
    // For counts with duplicates, sort pods in decreasing order of cost
    sort(podList.begin(), podList.end(), [](const Pod &a, const Pod &b)
         {
             if (a.count != b.count)
                 return a.count < b.count; // Sort by count ascending
             else
                 return a.cost > b.cost; // For same counts, higher cost first
         });

    long long totalCost = 0;
    int prevAssignedCount = INT_MIN;

    // Process the pods to assign unique counts
    for (auto &pod : podList)
    {
        // Determine the required count to ensure uniqueness
        int requiredCount = max(pod.count, prevAssignedCount + 1);
        int incrementsNeeded = requiredCount - pod.count;
        // Update the total cost
        totalCost += static_cast<long long>(incrementsNeeded) * pod.cost;
        // Update the pod's count to the required count
        pod.count = requiredCount;
        // Update the previous assigned count
        prevAssignedCount = requiredCount;
    }

    return static_cast<int>(totalCost);
}

int main()
{
    int n = 6;
    vector<int> pods = {5, 4, 9, 3, 3, 3};
    vector<int> cost = {5, 1, 2, 3, 4, 5};

    int result = minCost(pods, cost);

    cout << "Minimum cost to make pod counts unique: " << result << endl;

    return 0;
}
