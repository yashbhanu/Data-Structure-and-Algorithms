#include <iostream>
#include <queue>
#include <map>
using namespace std;

// Given an input stream of A of n characters consisting only of lower case alphabets. The task is to find the first non repeating character, each time a character is inserted to the stream. 
// If there is no such character then append '#' to the answer // eg Input A=[a,a,b,c] => 1. a is first non-repeating char, push it into output => 2. a is repeating char, hence push '#' into output
// 3. b is non repeating char, push it into output // 4. c is repeating char, but b is still the 'First Non Repeating Char', hence push b into output => Output = [a,#,b,b]

// Approach => iterate the string and store the count of each char by a map // push the char into queue , check if the char is repeating, if repeats then pop out from queue // so when queue is empty, i.e repeating char has occured, then push '#'
//if char has not repeated , push the first non repeat char(i.e queue's front char) into ans

class Solution
{
public:
    string FirstNonRepeating(string A)
    {
        map<char, int> count;
        string ans;
        queue<char> q;

        //iterate string
        for (int i = 0; i < A.length(); i++)
        {

            int ch = A[i];

            // increase count of the characters
            count[ch]++;

            q.push(ch); // push into queue

            while (!q.empty())
            {
                if (count[q.front()] > 1)
                {
                    q.pop(); // popped repeating char
                }
                else
                {
                    // found non-repeating char and pushed into ans and as we have pushed non repeated char, break from the loop
                    ans.push_back(q.front());
                    break;
                }
            }

            //if empty then simply return "#" OR || when queue is empty, i.e repeating char has occured, then push '#'
            if (q.empty())
            {
                ans.push_back('#');
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}