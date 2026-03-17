class Solution {
public:
    int reverse(int x) {
        int reverseNo = 0;
        bool isNegative = (x < 0) ? true : false;
        
        if (x < -INT_MAX) return 0;

        int temp = abs(x);
        while (temp!=0) {
            int digit = temp%10;
            temp = temp/10;
            if (reverseNo > (INT_MAX - digit)/10) {
                return 0;
            }
            reverseNo = reverseNo * 10 + digit;
        }
        return (isNegative) ? -reverseNo : reverseNo;
    }
};