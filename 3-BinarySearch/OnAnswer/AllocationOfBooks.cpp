#include<bits/stdc++.h>
using namespace std;

int findPages(vector<int>& arr, int n, int m) {
    int maxi = INT_MIN;
    int sum = 0;
    for(int i =0;i<arr.size();i++){
        sum += arr[i];
        if(arr[i]>maxi){
            maxi = arr[i];
        }
    }
    int result = -1;
    for(int k = maxi;k<=sum;k++){
        int currentPages = k;
        int studentCount = 1;
        bool isValid = true;

        for(int i =0;i<n;i++){
                currentPages = currentPages - arr[i];
            if(currentPages<0){
                studentCount++;
                currentPages=k-arr[i];
            }

            if(studentCount>m){
                isValid = false;
                break;
            }
        }

        if(studentCount==m){
            result = k;
            break;
        }else{
            studentCount = 1;
        }
    } 
    return result;
    
}


int findStudentCount(vector<int>& arr,int n,int pages){
    int currentPages = 0;
    int studentCount = 1;
    for(int i =0;i<n;i++){
        if(arr[i]+currentPages<=pages){
            currentPages+= arr[i];
        }else{
            studentCount++;
            currentPages = arr[i];
        }
    }
    return studentCount;    
}

int OptimalfindPages(vector<int>& arr, int n, int m) {
    int maxi = INT_MIN;
    int sum = 0;
    for(int i =0;i<arr.size();i++){
        sum += arr[i];
        if(arr[i]>maxi){
            maxi = arr[i];
        }
    }
    int result = -1;
    for(int pages = maxi;pages<=sum;pages++){
        int studentCount = findStudentCount(arr,n,pages);
        if(studentCount==m){     
            result = pages;
            break;
        }
    }
    return result;
} 

int main() {
    vector<int> books = {12, 34, 67, 90};  // Example book pages
    int n = books.size();
    int m = 2;  // Number of students

    cout << "Brute Force Result: " << findPages(books, n, m) << endl;
    cout << "Optimal Linear Search Result: " << OptimalfindPages(books, n, m) << endl;

    return 0;
}
