#include <iostream>
#include <vector>

using namespace std;

int sqrt(int x) {
    if(x < 0) return -1;
    if(x == 0) return 0;
    if(x == 1) return 1;

    int low = 0;
    int high = x - 1;
    int mid; double tmp;
    while(low < high){
        mid = low + ((high - low) >> 1);
        tmp = (0.0 + x) / mid;
        if(tmp == 0.0 + mid) return mid;

        if(tmp < 0.0 + mid) {
            high = mid;
        }
        else{
            low = mid + 1;
        }
    }
    if(low * low > x) return low - 1;
    return low;

}


int main()
{
   int x = 3;
   int ans = sqrt(x);
   cout << ans << endl;
   return 0;
}
