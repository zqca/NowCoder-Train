#include <iostream>
#include <vector>

using namespace std;

int patition(vector<int> &vec, int low, int high) {
    int cmp = vec[low];
    while(low < high) {
        while(low < high && vec[high] >= cmp){
            high--;
        }
        vec[low] = vec[high];
        while(low < high && vec[low] <= cmp){
            low++;
        }
        vec[high] = vec[low];
    }
    vec[low] = cmp;
    return low;
}

int findKth(vector<int> a, int n, int K) {
    //TODO:找第K大！！！不是第K小
    K = n - K;
    int low = 0, high = n - 1;

    int p = patition(a, 0, n - 1);
    while(p != K && low < high){
        if(p > K){
            high = p - 1;
            p = patition(a, low, high);
        }
        else{
            low = p + 1;
            p = patition(a, low, high);
        }
    }

    return a[p];
}

void sort(vector<int>& vec, int low, int high){
    int p;
    if(low < high){
        p = patition(vec, low, high);
        sort(vec, low, p - 1);
        sort(vec, p + 1, high);
    }
}

int main() {
    vector<int> a = {1332802,1177178,1514891,871248,753214,123866,1615405,328656,1540395,968891,1884022,252932,1034406,1455178,821713,486232,860175,1896237,852300,566715,1285209,1845742,883142,259266,520911,1844960,218188,1528217,332380,261485,1111670,16920,1249664,1199799,1959818,1546744,1904944,51047,1176397,190970,48715,349690,673887,1648782,1010556,1165786,937247,986578,798663}; 
    int n = 49;
    int K = 24;
    //sort(a,0, n - 1);

    int ans = findKth(a,n,K);//986578
    cout << ans << endl;
    return 0;
}