class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while(x!=0){
            int digit = x%10;
            if(rev > INT_MAX/10 || rev < INT_MIN/10){ //this is the major step in this question
                return 0;
            }
            rev = (rev * 10) + digit; //this one is normal reversing the array
            x = x/10;
        }  
        return rev;
    }
};