



int main(){
    int N;
    cin >> N;
    vector<int> list(N);
    for (int i = 0; i < N; i ++){
        cin >> list[i];
    }
    merge_sort(list, 0, N - 1);
    for (int i = 0; i < N; i ++){
        cout << list[i] << " ";
    }
}