#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;

    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int len;
    vector<int> ans(n + 1, 0);

    vector<int> stack;

    vector<int> left(n, 0);
    vector<int> right(n, 0);

    for (int i = 0; i < n; i++) {
        while (!stack.empty()) {
            if (a[i] <= a[stack.back()]) {
                stack.pop_back();
            }
            else {
                left[i] = stack.back();
                stack.push_back(i);
                break;
            }
        }
        if (stack.empty()) {
            left[i] = -1;
            stack.push_back(i);
        }
    }
    stack.clear();
    stack.shrink_to_fit();

    for (int i = n - 1; i >= 0; i--) {
        while (!stack.empty()) {
            if (a[i] <= a[stack.back()]) {
                stack.pop_back();
            }
            else {
                right[i] = stack.back();
                stack.push_back(i);
                break;
            }
        }
        if (stack.empty()) {
            right[i] = n;
            stack.push_back(i);
        }
    }

    for (int i = 0; i < n; i++) {
        len = right[i] - left[i] - 1;
        ans[len] = max(ans[len], a[i]);
    }

    for (int i = n - 1; i >= 0; i--) {
        if (ans[i] < ans[i + 1])ans[i] = ans[i + 1];
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}