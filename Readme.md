# First Question : No accident please
- Given 3 different set of coordinates of airports for ‘N’ different flights started from same point of time and place. Draw the flight path for the individual flights such that there is no intersection of flight paths for safety and optimization.
- For example:
- Input :
<br/> Flight 1 :  1,1  2,2  3,3 
<br/> Flight 2 : 1,1  2,4  3,2
<br/> Flight 3 : 1,1  4,2  3,4					
- Output :				
<br/> Draw the path of all flights in which they had traveled.

## Explanation : 



# Second Problem : My Money My Shares
- Ram , sham and rahim went for shopping apple. They bought apple worth 100 rupees. Ram paid 50 rupees, sham paid 30 rupees  and rahim paid 20 rupees. Each apple is tagged with its weight on it.  Write a program to distribute apples such that the quantity of apple they get is in best proportionate to the amount they paid. 
- Note : you cannot cut a apple into pieces have to allocate the whole apple to one of them.
- For example : If there is 8 apple  of  400g , 100g  , 400g , 300g , 200g , 300g ,100g , 200g  then we can distribute them as 
- Ram :  400g , 400g , 200g  (total 1kg , 50%) <br/> Sham :  300g , 300g (tatal 600g , 30%) <br/> Rahim , 200g , 100g , 100g  (tatal 400g , 20%)

## Explanation : 

### Approach :
-  We create a list of class containing the persons Ram, Sham, Rahim. We maintain the current weight and added apples using that class. We distribute the apples according to a custom comparator that prioritizes the person with the least proportion of total apple weight to their contribution ratio.

### Each Class

- **Each Class**: Represents a person involved in the distribution process.
  - name: The name of the person.
  - ratio: The proportion of the total money contributed by the person.
  - apples: A vector to store the weights of apples allocated to the person.
  - totalWeight: The total weight of apples allocated to the person.


- **comparePersons**: Custom comparison function to sort the persons based on their current apple weight relative to their share.
  - propA and propB: Calculate the proportion of total weight to their ratio.
  - Returns true if a should come before b, based on the proportion and total weight.

### Apple Distribution Function

```cpp
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
```

- **distributeApples**:
  - Calculates totalMoney as the sum of all contributions, (100 in example)
  - Adjusts proportions so that each value represents the ratio of the total. (0.5, 0.3, 0.2)
  - Sorts weights of apples in descending order. (400, 400, 300, 300, 200, 200, 100, 100)
  - Initializes persons with the name and ratio for each person, and empty apple lists.
  - For each apple weight: 
    - Sorts persons based on the comparison function. The one who has the least comes the first.
    - Assigns the heaviest available apple to the person who needs it most to balance the proportion.
  - Sorts persons one last time and get the answer in ans.


- **Main Function**:
  - Takes the necessary data as given in the input format.
  - Prints the answer as shown in the output format.

### Summary

The code distributes apples to Ram, Sham, and Rahim based on their financial contributions. It ensures that each person gets apples in proportion to their contribution, without cutting any apples. The distribution is balanced using a custom comparator that prioritizes the person with the least proportion of total apple weight to their contribution ratio.

