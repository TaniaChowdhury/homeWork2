//November 9, 2020
//Student name: Tania Chowdhury
//Professor’s name: Matthew Fried
//Course: CSCI313(48186)

#include<iostream>
#include <fstream>
#include<stack>
#include<string>
using namespace std;
void reverseWordsInString(string);
int main()
{
    string input;
    //file stream for input
    ifstream infile;
    infile.open("input.txt");
    //get input form the file in input varibale
    getline(infile,input);
    //reverseWordsInString function calleds
    reverseWordsInString(input);
    return 0;
}
void reverseWordsInString(string input)
{
    //reverse whole string
    reverse(input.begin(), input.end());
    //declare stack
    stack<char>s;
    int j = 0;
    //loop to get words one by one and push them to stack
    for (int i = 0; i <= input.size(); i++)
    {
        if (input[i] == ' ' || i == input.size())
        {
            //declare new string to store single words
            string newStr = "";
            for (j = j; j < i; j++)
            {
                newStr = newStr + input[j];
            }
            j = i + 1;
            //revrse single words
            reverse(newStr.begin(), newStr.end());
            newStr = newStr + ' ';
            //push single word to stack
            for (int k = 0; k < newStr.length(); k++)
            {
                s.push(newStr[k]);
            }
        }
    }
    s.pop();
    //display stack
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
}
