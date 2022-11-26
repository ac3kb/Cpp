int solution(vector<int> inputArray) {
    //have pointer i go through array
    //for every i have a pointer j that looks at the next element
    //find product of those two values and save it
    //continue process until i reaches end of array
    
    int max = inputArray[0] * inputArray[1];
    for(int i = 0; i<inputArray.size(); i++){
        if(i == inputArray.size() - 1){
            break;
        }
        for(int j = i+1; j ; j++){
            cout<< i << " " << j << endl;
            int test = inputArray[i] * inputArray[j];
            if(test > max){
                max = test;
            }
            break;
        }
    }
    
    cout << max;
    return max;
    
}
