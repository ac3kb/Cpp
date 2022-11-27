int solution(vector<int> &statues) {
    //loop through array
    //at eveery iteration check if arr[i] - (arr[i+1]) - 1
    //if 0 continue
    //if greater than zero add to sum value
    //stop loop when i reaches last index
    sort(statues.begin(), statues.end());
    int sum{0};
    for(int i = 0; i < statues.size(); i++){
        if(i == statues.size() - 1) break;
        if((statues[i+1] - statues[i]) - 1 >= 0){
            sum+=(statues[i+1] - statues[i]) - 1;
        }
    }
    return sum;
}
