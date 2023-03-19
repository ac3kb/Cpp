/*Reduce a string of lowercase characters in range ascii[‘a’..’z’]by doing a series of operations. In each operation, select a pair of adjacent letters that match, and delete them.

Delete as many characters as possible using this method and return the resulting string. If the final string is empty, return Empty String

Example.


aab shortens to b in one operation: remove the adjacent a characters.


Remove the two 'b' characters leaving 'aa'. Remove the two 'a' characters to leave ''. Return 'Empty String'.

Function Description

Complete the superReducedString function in the editor below.

superReducedString has the following parameter(s):

string s: a string to reduce
Returns

string: the reduced string or Empty String
Input Format

A single string, .*/
///////////////////////////////////////////////////////////////////////////////////

function superReducedString(s) {
    // Write your code here
    //consider casing
    //empty strings
    //strings with only one kind of unique letter
    //while loop
    //a start pointer and a next pointer
    //if start  == next cut start and next
    //if not move start up and next up
    
    if(s.length == 0 ) return "Empty String"
    
    s = s.split('');
    //console.log(s)
    let start = 0;
    let next = 1;
    
    while(next < s.length){
        let first = s[start].toLowerCase();
        let second = s[next].toLowerCase();
        
        if(first == second){
            //cut out both
            s = s.slice(0, start).concat(s.slice(next+1)); //cut out last two elements
            //console.log(s)
            if(start == 0 && next == 1)continue;
            start--
            next--
        }else{
            start++;
            next++;
        }
        console.log(s);
    }
    
    let sol = s.join('');
    if(sol.length == 0){
        return "Empty String"
    }
    else if(sol.length == 2 && sol[0] == sol[1]){
        return "Empty String"
    }else{
        return sol;
    }
    
    
}
