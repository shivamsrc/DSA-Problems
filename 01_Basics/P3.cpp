// switch case problem

#include<iostream>
using namespace std;

class Solution{
    public:
        void whichWeekDay(int num){
            switch(num){
                case 1: 
                    cout<<"Monday";
                    break;

                case 2:
                    cout<<"Tuesday";
                    break;

                case 3:
                    cout<<"Wednesday";
                    break;

                case 4:
                    cout<<"Thursday";
                    break;

                case 5:
                    cout<<"Friday";
                    break;

                case 6:
                    cout<<"Saturday";
                    break;

                case 7:
                    cout<<"Sunday";
                    break;

                default:
                    cout<<"Invalid";
            };
        };
};

int main(){
    int num;
    cout<<"day = ";
    cin>>num;

    Solution s1;
    s1.whichWeekDay(num);

    return 0;
}