#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

class Each
{
public:
    string name;
    double ratio;
    vector<int> apples;
    int totalWeight = 0;
};

bool comparePersons(Each &a, Each &b)
{
    double propA = (a.totalWeight / a.ratio);
    double propB = (b.totalWeight / b.ratio);
    if (propA == propB)
    {
        return a.totalWeight < b.totalWeight;
    }
    return propA < propB;
}

vector<vector<int>> distributeApples(vector<int> &weights, map<string, double> &proportions)
{
    double totalMoney = 0.0;
    vector<vector<int>> ans(3, vector<int>(0));
    for (auto &proportion : proportions)
    {
        totalMoney += proportion.second;
    }

    for (auto &proportion : proportions)
    {
        proportion.second = proportion.second / totalMoney;
    }
    sort(weights.begin(), weights.end(), greater<int>());

    vector<Each> persons;
    for (auto &proportion : proportions)
    {
        persons.push_back({proportion.first, proportion.second, {}, 0});
    }

    for (int &weight : weights)
    {
        sort(persons.begin(), persons.end(), comparePersons);
        persons[0].apples.push_back(weight);
        persons[0].totalWeight += weight;
    }
    sort(persons.begin(), persons.end(), comparePersons);

    for (int i = 0; i < persons.size(); i++)
    {
        ans[i] = persons[persons.size() - 1 - i].apples;
    }
    return ans;
}

int main()
{
    vector<int> weights;
    int x;
    do
    {
        cout << "Enter Apple Weight in gram (-1 to stop): ";
        cin >> x;
        cout << "\n";
        if (x != -1)
        {
            weights.push_back(x);
        }
    } while (x != -1);
    map<string, double> proportions = {
        {"Ram", 50},
        {"Sham", 30},
        {"Rahim", 20}};
    vector<vector<int>> ans = distributeApples(weights, proportions);
    cout << "Ram: ";
    for (int weight : ans[0])
    {
        cout << weight << " ";
    }
    cout << endl;

    cout << "Sham: ";
    for (int weight : ans[1])
    {
        cout << weight << " ";
    }
    cout << endl;

    cout << "Rahim: ";
    for (int weight : ans[2])
    {
        cout << weight << " ";
    }
    cout << endl;
    return 0;
}