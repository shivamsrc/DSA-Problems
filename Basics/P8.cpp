#include<bits/stdc++.h>
using namespace std;

// Count all Digits of a Number
class Solution{
    public:
        // Count all Digits of a Number
        int countDigit(int n){
            int num = n;
            int count = 0;
            while(num>0){
                num = num / 10;
                count++;
            }
            return count;
        }

        // Reverse of a Number
        int reverse(int x) {
            int num = x;
            int revNum = 0;
            while(num != 0){
                int lastDigit = num % 10;
                num = num / 10;
                if(revNum > INT_MAX/10 || revNum == INT_MAX/10 && lastDigit > 7) return 0;
                if(revNum < INT_MIN/10 || revNum == INT_MIN/10 && lastDigit < -8) return 0;
                revNum = (revNum*10)+lastDigit;
            }
            return revNum;
        }

        //Check Palindrome number - revrse of the number is same as the original number
        bool isPalindrome(int x) {
            int num = x;
            int revNum = 0;
            while(num > 0){
                int lastDigit = num % 10;
                num = num / 10;
                if(revNum > INT_MAX/10 || revNum == INT_MAX/10 && lastDigit > 7) return 0;
                revNum = (revNum*10) + lastDigit;
            }
            if(revNum == x) return true;
            else return false;
        }

        // Check Armstrong number - A number that is equal to the sum of its own digits each raised to the power of the number of digits.
        bool isArmstrong(int x){
            int num = x;
            int genNum = 0;
            int digits = int(log10(num) + 1);
            while(num > 0){
                int lastDigit = num % 10;
                num = num / 10;
                genNum = genNum + pow(lastDigit, digits);             // pow(2,5) = 2^5
            }
            if(genNum == x) return true;
            else return false;
        }

        // Print all the divisors of any number
        int divisors(int x){
            int num = x;
            // for(int i=1; i<=num; i++){
            //     if(num % i == 0){
            //         cout<<i<<" ";
            //     }
            // }

            // better TC
            vector<int> v;
            for(int i=1; i<=sqrt(num); i++){
                if(num % i == 0){
                    v.emplace_back(i);
                    if(num / i != i){
                        v.emplace_back((num/i));
                    }
                }
            }
            sort(v.begin(), v.end());
            for(auto it : v){
                cout<<it<<" ";
            }
        }

        // Check Prime no.
        bool isPrime(int x){
            int num = x;
            int count = 0;
            for(int i=1; i<=sqrt(num); i++){
                if(num % i == 0){
                    count++;
                    if(num / i != i){
                        count++;
                    }
                }
            }
            if(count == 2) return true;
            else return false;
        }

        // HCF or GCD
        int GCD(int x, int y){
            int gcd = 1;
            for(int i=min(x,y); i>=1; i--){
                if(x%i == 0 && y%i == 0){
                    gcd = i;
                    break;
                }
            }
            return gcd;
        }

        // GCD using euclidean algorith
        int gcdEuclidean(int x, int y){
            while(x>0 && y>0){
                if(x>y) x = x % y;
                else y = y % x;
            }
            if(x==0) return y;
            else return x;
        }
};

int main(){
    Solution s1;

    cout<<s1.gcdEuclidean(20, 42);
}