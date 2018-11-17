// Program: Assignment 3 -  Individual 2
// Purpose: measuring many commodities using weights and balance pans
// Author:  Shahesta Muhammed
// Date:    17 November 2018
// Version: 1.0
#include <iostream>
#include <vector>

using namespace std;

vector<int>weights1;

bool isMeasurable(int target, vector<int>rest,vector<int> weights = weights1)
{

if(rest.size()==0){ //base case when the weights equal zero , then there is no weights to measure then return false
 return false;
}
    int totalTarget = target; //defining variable totalTarget equals target
    for(int i = 0;i < weights.size();i++) //making the sum of all definite weights plus the target
        totalTarget += weights[i];
    int rest1 = 0;
    for(int i = 0;i < rest.size();i++) // making the sum of all the rest weights on the other side
        rest1 += rest[i];
    if(rest1 == totalTarget) //base case that when both sides became equal , then i can measure the amount
    {
        return true;
    }

for(int i = 0;i < rest.size();i++) // checking all combinations by taking values from rest and adding them to the weights
  {
         vector<int>temp = weights; // to save the main values without changing
         temp.push_back(rest[i]);
         vector<int> temp2=rest;
         temp2.erase( temp2.begin() + i  ); // because rest[i] goes to temp
         if(isMeasurable(target,temp2,temp)) // calling the function with the new weights and rest
            return true;

  }
  return false; // if it reaches this line , then it didn't make true before then it's invalid

}
int main()
{
    vector<int>v;

    v.push_back(3);
    v.push_back(1);

    cout << isMeasurable(2,v) << endl;

}
