int solution(int year) {
    double century = 100.0;
    double result = year / century;
    
    if(year % 100){
        result+=1;
    }
    
    return static_cast<int>(result);
}
