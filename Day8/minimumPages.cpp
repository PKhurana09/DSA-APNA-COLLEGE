// You are given an array arr[] of integers, where each element arr[i] represents the number of pages in the ith book. You also have an integer k representing the number of students. The task is to allocate books to each student such that :
// Each student receives at least one book.
// Each student is assigned a contiguous sequence of books.
// No book is assigned to more than one student.
// The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.
// Note: Return -1 if a valid assignment is not possible, and the allotment should be in contiguous order (see the explanation for better understanding).


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int minimizedMaximum(vector<int>& pages, int n);
bool isValid(vector<int>& pages, int n, int minMaxPages);

int main(void){
    vector<int> quantitites = {12, 34, 67, 90};

    cout << minimizedMaximum(quantitites, 2);

    return EXIT_SUCCESS;
}

bool isValid(vector<int>& pages, int n, int minMaxPages){
    int nb = pages.size();

    int minPages = 0;
    int student = 1;

    for(int i = 0; i != nb; ++i){
        if(pages[i] > minMaxPages) return false;

        if(minPages + pages[i] <= minMaxPages){
            minPages = minPages + pages[i];
        }else{
            ++student;
            minPages = pages[i];
        }
    }

    return (student <= n);
}

int minimizedMaximum(vector<int>& pages, int n){
    int nums = pages.size();
    int minMaxPages = 0;

    if(n > nums) return -1;
    
    int st = *max_element(pages.begin(), pages.end());

    int end = 0;
    for(int i = 0; i != nums; ++i){
        end = end + pages[i];
    }
    // So my range has been set between st and end. st in case nums = n. end in case n = 0

    while( st <= end){
        int mid = st +(end-st)/2;

        if(isValid(pages, n, mid)){
            minMaxPages = mid;
            end = mid - 1;
        }else{
            st = mid + 1;
        }
    }

    return minMaxPages;
}