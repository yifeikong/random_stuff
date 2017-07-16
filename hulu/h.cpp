#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int binary_search(vector<int>& nums, int target) {
    int first = 0, last = nums.size() - 1;
    while (first <= last) {
        int middle = first + (last - first) / 2;
        if (nums[middle] == target)
            return middle;
        else if (target > nums[middle]) 
            first = middle + 1;
        else
            last = middle - 1;
    }
}

int main() {
      int n;
      cin >> n;
      vector<int> houses(n), rain(n, 0);
      for (int i = 0; i < n; i++)
          cin >> houses[i];
      int m;
      cin >> m;
      int l, u, w;
      while (m--) {
            cin >> l >> u >> w;
            int low, up;
            low = binary_search(houses, l);
            up = binary_search(houses, u);
            for (int i = low; i <= up; i++)
                rain[i] += w;
      }
      while (n--)
            cout << houses[n] << endl;
      return 0;
}
