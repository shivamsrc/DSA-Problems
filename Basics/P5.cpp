#include<iostream>
using namespace std;

void print1(int n){

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

void print2(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

void print3(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

void print4(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}

void print5(int n){
    // for(int i=n; i>0; i--){
    //     for(int j=i; j>0; j--){
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=(n-i+1); j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

void print6(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=(n-i+1); j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

void print7(int n){
    for(int i=0; i<n; i++){
        // space
        for(int j=0; j<(n-i-1); j++){
            cout<<" ";
        }

        // star
        for(int j=0; j<(2*i+1); j++){
            cout<<"*";
        }

        //space
        for(int j=0; j<(n-i-1); j++){
            cout<<" ";
        }
        cout<<endl;
    }
}

void print8(int n){
    for(int i=0; i<n; i++){
        //space
        for(int j=0; j<i; j++){
            cout<<" ";
        }
        
        //star
        for(int j=0; j<(2*n - (2*i+1)); j++){
            cout<<"*";
        }

        //space
        for(int j=0; j<i; j++){
            cout<<" ";
        }
        cout<<endl;
    }
}

void print9(int n){
    print7(n);
    print8(n);
}

void print10(int n){
    for(int i=0; i<(2*n-1); i++){
        int stars = i;
        if(i>n){
            stars = 2*n - i;
        }
        for(int j=0; j<=stars; j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void print11(int n){
    int start = 1;
    for(int i=0; i<n; i++){
        if(i%2==0) start = 1;
        else start = 0;

        for(int j=0; j<=i; j++){
            cout<<start;
            start = 1 - start;
        }
        cout<<endl;
    }
}

void print12(int n){
    for(int i=1; i<=n; i++){
        //number
        for(int j=1; j<=i; j++){
            cout<<j;
        }

        //space
        for(int j=1; j<=(2*n-2*i); j++){
            cout<<" ";
        }

        //number
        for(int j=1; j<=i; j++){
            cout<<i+1-j;
        }
        cout<<endl;
    }
}

void print13(int n){
    int num = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<num<<" ";
            num++;
        }
        cout<<endl;
    }
}

void print14(int n){
    for(int i=1; i<=n; i++){
        char start = 'A';
        for(int j=1; j<=i; j++){
            cout<<start;
            start++;
        }
        cout<<endl;
    }
}

void print15(int n){
    for(int i=0; i<n; i++){
        char start = 'A';
        for(int j=0; j<n-i; j++){
            cout<<start;
            start++;
        }
        cout<<endl;
    }
}

void print16(int n){
    char ch = 'A';
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cout<<ch;
        }
        ch++;
        cout<<endl;
    }
}

void print17(int n){
    for(int i=1; i<=n; i++){
        char ch = 'A';

        //space
        for(int j=1; j<=n-i; j++){
            cout<<" ";
        }

        //char
        for(int j=1; j<=(2*i-1); j++){
            cout<<ch;
            if(j<i) ch++;
            else ch--;
        }

        //space
        for(int j=1; j<=n-i; j++){
            cout<<" ";
        }
        cout<<endl;
    }
}

void print18(int n){
    char ch = 'A';
    for(int i=1; i<=n; i++){
        int num = i;
        for(int j=1; j<=i; j++){
            cout<<char(ch+(n-num));
            num--;
        }
        cout<<endl;
    }
}

void print19(int n){
    // upper half
    for(int i=0; i<n; i++){
        //star
        for(int j=1; j<=(n-i); j++){
            cout<<"*";
        }
        //space
        for(int j=1; j<=2*i; j++){
            cout<<" ";
        }
        //star
        for(int j=1; j<=(n-i); j++){
            cout<<"*";
        }
        cout<<endl;
    }

    // lower half
    for(int i=1; i<=n; i++){
        //star
        for(int j=1; j<=i; j++){
            cout<<"*";
        }
        //space
        for(int j=1; j<=(2*n-2*i); j++){
            cout<<" ";
        }
        //star
        for(int j=1; j<=i; j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void print20(int n){
    for(int i=1; i<=(2*n-1); i++){
        int star;
        if(i<=n) star = i;
        else star = 2*n-i;
        //star
        for(int j=1; j<=star; j++){
            cout<<"*";
        }
        //space
        for(int j=1; j<=(2*n-2*star); j++){
            cout<<" ";
        }
        //star
        for(int j=1; j<=star; j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void print21(int n){
    // for(int i=1; i<=n; i++){
    //     int num = 1;
    //     if(i==1 || i==n) num = n;

    //     //star
    //     for(int j=1; j<=num; j++){
    //         cout<<"*";
    //     }
    //     //space
    //     for(int j=1; j<=n-2; j++){
    //         if(num == 1) cout<<" ";
    //     }
    //     //star
    //     for(int j=1; j<=num; j++){
    //         if(num == 1) cout<<"*";
    //     }
    //     cout<<endl;
    // }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==0 || j==0 || i==n-1 || j==n-1){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}

void print22(int n){
    for(int i=0; i<(2*n-1); i++){
        for(int j=0; j<(2*n-1); j++){
            int top = i;
            int left = j;
            int right = (2*n-2)-j;
            int down = (2*n-2)-i;
            cout<<n-min(min(top,down), min(left,right));
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;

    print22(n);

    return 0;
}