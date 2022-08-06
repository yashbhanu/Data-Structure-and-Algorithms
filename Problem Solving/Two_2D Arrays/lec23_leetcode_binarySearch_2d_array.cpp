#include <iostream>
using namespace std;

//use binary search on 2d arrays //very similar to binary search on 1d array // (only differnece is searhing mid)
//set start = 0; set end = n - 1; (n = row*col) i.e (12) (12- 1 = 11(lastelem i.e end)) //set mid =  s + (e - s)/2 // search the array from start to end
// if elem found then return true // if elem < target (i.e search on right part) (update s = mid + 1) //if elem >target (i.e search on left part) (update e = mid - 1) 
// update mid // if not found then return false
// int element = matrix[mid/col][mid%col]; => only differnece ie finding mid
//[1,3,5,7,10,11,16,20,23,30,34,60] => in memory arr shall be stored like this //when we remove mid (ans will '11' i.e index '5') //we need to find '11' in 2D matrix (i.e find ith, jth index)
//mid = (0 + 11)/2 = '5' //to find row index , divide mid by col (i.e 5/4 = '1') , so row index = 1 //to find col index , do mod of mid by col (i.e 5%4 = '1') , so col index = 1 
//so element = matrix[1][1] i.e 11 //now we'll apply BS approach on 11 //continue the binary search approach


bool searchMatrix(int matrix[][4], int target) {
        
        int row = 3;   //in stl int row = matrix.size()
        int col = 4;   //in stl int row = matrix[0].size()
        
        int start = 0;
        int end = row*col - 1;
        int mid = start + (end - start/2);
        
        while (start <= end) {
            
            int element = matrix[mid/col][mid%col];
            
            if(element == target)
                return 1;
            
            else if (element < target)
                start = mid + 1;
            
            else
                end = mid - 1;
            
            mid = start + (end - start/2);
        }
        return 0;
}

int main(){

    int arr[3][4] = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 7;

    if(searchMatrix(arr, target)) {
        cout<<"Element found"<<endl;
    } else {
        cout<<"Element not found"<<endl;
    }


return 0;
}