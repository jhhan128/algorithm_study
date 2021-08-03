int n; cin >> n; // n: length of an array
int arr[n];
for (int i = 0; i < n; i++) cin >> arr[i];

vector<int> v = { arr[0] };
for (int i = 0; i < n; i++) {
    if (arr[i] > v.back()) v.push_back(arr[i]);
    else *lower_bound(v.begin(), v.end(), arr[i]) = arr[i];
}

cout << v.size(); // length of v is length of LIS of arr
