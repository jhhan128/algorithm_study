int n; cin >> n;
int arr[n];
for (int i = 0; i < n; i++) cin >> arr[i];

vector<int> v = { arr[0] };
for (int i = 0; i < n; i++) {
    if (arr[i] > v.back()) v.push_back(arr[i]);
    else *lower_bound(v.begin(), v.end(), arr[i]) = arr[i];
}

// v.size() is length of LIS
