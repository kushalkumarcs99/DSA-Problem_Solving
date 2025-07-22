class Solution {
public:
    int sum = 0, product = 1;
    void digitsCalc(int number) {
        number = abs(number); // To handle negative numbers
        while (number > 0) {
            sum += number % 10;
            product *= number % 10; // Add the last digit
            number /= 10;       // Remove the last digit
        }
    }
    bool checkDivisibility(int n) {
        digitsCalc(n);
        if(n % (sum + product) == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};