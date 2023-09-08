#include <bits/stdc++.h>
using namespace std;

//MultiSet Solution
// class MedianFinder
// {
// public:
//     multiset<int> s;
//     MedianFinder()
//     {
//         s= {};
//     }

//     void addNum(int num)
//     {
//         s.insert(num);
//     }

//     double findMedian()
//     {
//         int n = s.size();
//         auto it = s.begin();        
//         if (n%2!=0) {
//             advance(it, n/2);
//             return *it;
//         }
//         else {
//             double sum = 0;
//             advance(it,n/2-1);
//             sum+=*it;
//             advance(it, 1);
//             sum+=*it;
//             return sum/2;
//         }
//     }
// };

// Two Heap Solution

// We need 2 heaps, one min heap (large elements) one max heap (small elements)
// All elements in the large elements should be greater than or equal to all elements in the small elements
// The size of the two heaps should be nearly equal -> diff <=1
// If the sizes are unequal, we check which heap has more elements 
// -> if small elements has more elements then the max of that is the median
// Otheriwse the min of max elements is the median
// If the two heaps are of equal size then the mean of min of large elements and max of small elements is the median


class MedianFinder
{
public:
    priority_queue<int> small_elements;
    priority_queue<int, vector<int>, greater<int>> large_elements;
    MedianFinder()
    {
        small_elements = {};
        large_elements = {};
    }

    void addNum(int num)
    {
        // By default we add it to the small heap
        // Then we check the size condition and the greater than or equal condition
        small_elements.push(num);
        if (!large_elements.empty() &&small_elements.top() > large_elements.top()) {
            int x = small_elements.top();
            small_elements.pop();
            large_elements.push(x);
        }

        if (abs((int)small_elements.size()-(int)large_elements.size())>1) {
            if (large_elements.size()>small_elements.size()) {
                int x = large_elements.top();
                large_elements.pop();
                small_elements.push(x);
            }

            else {
                int x = small_elements.top();
                small_elements.pop();
                large_elements.push(x);
            }
        }
    }

    double findMedian()
    {
        if (small_elements.size()<large_elements.size()) {
            return large_elements.top();
        }

        else if (small_elements.size()>large_elements.size()) {
            return small_elements.top();
        }

        else {
            double s = large_elements.top() + small_elements.top();
            return s/2;

        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


int main () {
    MedianFinder mf;
    mf.addNum(5);
    mf.addNum(4);
    mf.addNum(6);
    cout<<mf.findMedian();
}