int solution(vector<int> inputArray) {
    //have a pointer i that points to left element'
    //have a pointer j that points to right element
    //a for loop that goes through the whole array
    //at every iteration check if a[i]*a[j] is great than max
    //if true the reassign max to the product 
    //if not increment i an j by 1
    // stop loop when j is at the last index
    
    int i = 0, j = 1, max = inputArray[0]*inputArray[1];
    for(int x = 0; x < inputArray.size(); x++){
        int test = inputArray[i]*inputArray[j];
        if(test>max){
            max = test;
        }
        j++;
        i++;
        if(j == inputArray.size()){
            break;
        }
        cout << i << " " << j <<endl;
    }
    
    return max;
}
