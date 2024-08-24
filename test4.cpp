#include <bits/stdc++.h>
using namespace std;

string findYoungestMissingMember(const vector<int> &ages, const vector<string> &members)
{
    set<int> ageSet(ages.begin(), ages.end());
    int youngestMissingAge = INT_MAX;
    string youngestMember = "";

    for (const auto &member : members)
    {
        size_t firstComma = member.find(',');
        size_t lastComma = member.rfind(',');
        int age = stoi(member.substr(lastComma + 1));

        if (ageSet.find(age) == ageSet.end() && age < youngestMissingAge)
        {
            youngestMissingAge = age;
            youngestMember = member.substr(0, firstComma);
        }
    }

    return youngestMissingAge == INT_MAX ? "null" : youngestMember;
}

int main()
{
    vector<int> ages = {1, 2, 3, 4, 5};
    vector<string> members = {"Ram,D,1", "Dev,B,2", "Adam Jobs,3", "Adam jobs,4",
                              "Ema,K,5", "Leena,Jack,7", "Patric,Queen,8",
                              "Liam,Jones,9", "Riya,N,10", "Dilip,K,2"};

    cout << "Output: " << findYoungestMissingMember(ages, members) << endl;
    return 0;
}
