#include <iostream>
using namespace std;
#include <bits/stdc++.h>
#include<algorithm>

int main(){

    //********************Array**************************//

    //array with type 'int' , size = 4 && name = 'arr'
    array<int, 4> arr = {1,2,3,4}; 
    
    int size = arr.size();    //array's size

    //print array
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<endl;
    }

    cout<<"Element at 2nd Index "<<arr.at(2)<<endl;      //find no. at any position
    cout<<"Empty or Not "<<arr.empty()<<endl;
    cout<<"1st elem"<<arr.front()<<endl;
    cout<<"Last elem"<<arr.back()<<endl;

    //**********************************************************************//


    //**************************Vector**************************************//
    //Vector is a dynamic array


    vector<int> v;      //declare vector with type 'int' and name 'v'
    vector <int> a(5,1);    //vector with type 'int' and name 'a' && size = 5 && intialize all the array elems by '1' i.e a = [1,1,1,1,1]

    vector<int> b(a);   //copy vector 'a' in vector 'b'

    //print //for each loop //iterates the whole array/vector
    for(int i:b){
        cout<<i<<" ";
    }

    cout<<"capacity "<<v.capacity()<<endl;      //capacity of vector i.e how much it can hold //capacity keeps on doubling as push more and more elems into the vector

    v.push_back(1); v.push_back(2); v.push_back(3);         //insert into the vector
    cout<<"capacity "<<v.capacity()<<endl;
    cout<<"size "<<v.size()<<endl;      //size //how many elements are present inside the vector

    cout<<"Element at 2nd Index "<<v.at(2)<<endl;      //find no. at any position
    cout<<"Empty or Not "<<v.empty()<<endl;
    cout<<"1st elem"<<v.front()<<endl;
    cout<<"Last elem"<<v.back()<<endl;


    v.pop_back(); //removes last element

    v.clear();      //clears the whole array //i.e size = 0 // but capacity would remain same as earlier

    //*********************************************************************************//


    //*******************************// Deque // **************************************

    //deque is dynamic // we can acces it through both the sides/ends

    deque<int> d;       //create deque with type 'int' and name 'd'

    d.push_back(1);     //insert at end/back
    d.push_front(2);       //insert at front/start


    cout<<"Element at 2nd Index "<<d.at(2)<<endl;      //find no. at any position
    cout<<"Empty or Not "<<d.empty()<<endl;
    cout<<"1st elem"<<d.front()<<endl;
    cout<<"Last elem"<<d.back()<<endl;

    cout<<"size "<<d.size()<<endl;

    d.erase(d.begin(),d.begin() + 1);       //erase function doesnt erase the whole deque // but we need to specify the position on which we need to erase //here it deletes the first elem from deque

    //************************************************************************************//


    //************************** List  ************************************************//

    //list is implemented using doubly linked list in STL

    list<int> l;  //initialize

    list<int> n(5,100); //initialize with size 5 and //allocate 100 on all 5 positions

    l.push_back(1);     //insert at back
    l.push_front(2);       //insert at front

    l.erase(l.begin());     //erase at 1st position
    cout<<"size is "<<l.size()<<endl;

    l.front(); 
    l.back();
    l.empty();

    //***************************************************************************//


    //*************************Stack********************************************//

    //LIFO (last in first out) //jo sabse aakhir/last m jayega wahi sabse pehle aayega //imagine rack of plates

    stack<string> s;

    //insert elements
    s.push("Yash");
    s.push("Bhanu");
    s.push("Harry");

    cout<<"top elem "<<s.top()<<endl;   //it will print 'harry' as the last element inserted was 'harry' //and it will be on top

    s.pop();        //it would pop 'harry' as its on top //LIFO
    cout<<"size "<<s.size()<<endl;
    cout<<"is empty "<<s.empty()<<endl; 

    //*****************************************************************************//


    //*************************Queue *************************************************//
    //FIFO (first in firs out)

    queue<string> q;

    //insert elems
    q.push("Yash");
    q.push("Bhanu");
    q.push("Harry");

    //as its FIFO (first elem would be 'Yash')
    cout<<"first elem"<<q.front()<<endl;
    
    //as its FIFO  (elem would be 'Yash') //joh sabse pehle jayega wohi pehle niklega
    q.pop();
    cout<<"size "<<q.size()<<endl;

    //**********************************************************************************//


    //****************************Priority Queue ****************************************//
    //in priority queue whose first element is always greatest (i.e max heap by default)

    //max heap
    priority_queue<int> maxi;

    //min heap
    priority_queue<int, vector<int>, greater<int> > mini;

    maxi.push(1);
    maxi.push(3);
    maxi.push(2);
    maxi.push(0);

    int n = maxi.size(); //get size
    //iterate through the array // you will get  3 2 1 0 //bcz top starts from element is 3 //display 3 //pop 3 //now top is 2//display 2 //pop 2
    while(!maxi.empty()) 
    {
        cout<<maxi.top()<<" ";
        maxi.pop();
    }
    
    mini.push(1);
    mini.push(3);
    mini.push(2);
    mini.push(0);

    int m =  mini.size();
    //iterate through the array // you will get  0 1 2 3 //bcz top element is smallest incase of min heap
    while(!mini.empty()) 
    {
        cout<<maxi.top()<<" ";
        maxi.pop();
    }

    cout<<maxi.empty()<<endl;

    //*****************************************************************************//


    //*************************** set ********************************************//

    //set stores only unique values //no duplicate values //always returns values in sorted order

    set<int> s1;     //initialize

    s1.insert(5);
    s1.insert(5);
    s1.insert(4);
    s1.insert(4);
    s1.insert(3);

    //auto is a iterator in STL //iterate the set
    for(auto i:s1) {
        cout<<i<<endl;
    }

    //we created a iterator it
    set<int>::iterator it = s1.begin();
    it++;

    s1.erase(it);       //erases 1st elem //bcz our iterator is pointing at s1.begin()

    //iterate whole s1 and print it
    for(auto i:s1) {
        cout<<i<<endl;
    }

    cout<<"5 is present or not "<<s1.count(5);

    //creater a iterator 'itr' that points to the index where 5th elem is present //bcz .find() finds the position of element
    set<int>::iterator itr = s1.find(5);

    //start iterating through '5' (i.e it = itr) till last elem (i.e it!=s1.end) // use '*it' , why ? => bcz when we use .find(), reference of that particular element(i.e 5) is returned //hence we use 'pointer' *it to point at '5' and print it
    for (auto it = itr; it!=s1.end(); it++)
    {
        cout<<*it<<" ";
    }
    
    //**************************************************************************************************//


    //***************************************** Map *********************************************//

    //map stores value in key:value pairs

    map<int,string> m1;

    //insert //'1' is key and "babbar" is value...& so on
    m1[1] = "babbar";
    m1[13] = "yash";
    m1[2] = "kumar";

    //another way to insert
    m1.insert( {5,"harry"} );

    //iterate and print //first = key && second = value
    for(auto i:m1) {
        cout<<i.first<<" "<<i.second<<endl;
    }

    cout<<"find 13 "<<m1.count(13)<<endl;   //it finds keys and returns true or false

    auto itr1 = m1.find(5);     //iterator which return reference of the position of 5

    //start iterating from 5 till m1's end //find return refernce of 5 //hence use pointer (*i)
    for(auto i=itr1; i!=m1.end();i++) {
        cout<<(*i).first<<endl;
    }

    //*******************************************************************************************************//



    //********************************* ALGORITHM *******************************************//

    vector<int> vec;

    v.push_back(7);
    v.push_back(3);
    v.push_back(6);
    v.push_back(2);

    //binary search algo //from vec start to end //search element '6'
    cout<<"Finding 6 -> "<<binary_search(vec.begin(), vec.end(), 6)<<endl;

    cout<<"lower_bound "<<lower_bound(vec.begin(), vec.end(), 6)-vec.begin()<<endl;
    cout<<"upper_bound "<<upper_bound(vec.begin(), vec.end(), 6)-vec.begin()<<endl;

    int a1 = 3,b1=5;

    cout<<"max "<<max(a1,b1);  //max
    cout<<"min "<<min(a1,b1);   //min

    //swapping
    swap(a1,b1);

    string abcd = "abcd";
    reverse(abcd.begin(), abcd.end());      //reverse the order
    cout<<abcd<<endl;

    rotate(vec.begin(),vec.begin() + 1, vec.end());     //rotate the array

    for(int i:vec){
        cout<<i<<" ";
    }

    sort(vec.begin(),vec.end());        //sort the array

return 0;
}