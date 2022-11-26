bool solution(string &inputString) {
    //i pointer that starts from index 0 of string
    //j pointer that starts from last index of string
    
    //while loop that stop once i == j or i and j cross
    //at every loop iteration check wether a[i] = a[j]
        //if true continue loop
        //if not return false
    //return true if while loop reaches the base case
    
    int i{0};
    int j = inputString.size() - 1;
    
    while(i !=j || i < j ){
        if(inputString[i] == inputString[j]){
            i++;
            j--;
            if(i>j){
                break;
            }
        }
        else{
            return false;
        }
    }
    
    return true;
}
