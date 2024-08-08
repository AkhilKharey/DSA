#include <iostream>
#include <list>
#include <string>

using namespace std;

class StudentList
{
private:
    list<string> students;

public:
    void addStudent(const string &rollNumber)
    {
        students.push_front(rollNumber);
    }

    void deleteByPrefix(const string &prefix)
    {
        for (auto it = students.begin(); it != students.end();)
        {
            if (it->substr(0, prefix.size()) == prefix)
            {
                it = students.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }

    void printList() const
    {
        for (const auto &rollNumber : students)
        {
            cout << "Roll: " << rollNumber << endl;
        }
    }
};

int main()
{
    StudentList list;

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        string rollNumber;
        cin >> rollNumber;
        list.addStudent(rollNumber);
    }

    string prefix;
    cin >> prefix;

    list.deleteByPrefix(prefix);

    list.printList();

    return 0;
}
