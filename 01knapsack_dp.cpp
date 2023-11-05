


#include <iostream>
using namespace std;

struct obj {
    int weight;
    int p;
};

struct obj t[4];

void wt_sort(int n) {
    struct obj temp;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (t[i].weight > t[j].weight) {
                temp.weight = t[i].weight;
                temp.p = t[i].p;

                t[i].weight = t[j].weight;
                t[i].p = t[j].p;

                t[j].weight = temp.weight;
                t[j].p = temp.p;
            }
        }
    }
}

void displayIP(int n) {
    cout << "\n"<< "User Input:"<< "\n";
    cout << "Weight"<< "\t"<< "Profit";
    for (int i = 0; i < n; i++) {
        cout << "\n";
        cout << t[i].weight << "\t" << t[i].p;
    }
}

void displaySorted(int n) {
    cout << "\n"<< "Values after sorting of weights:"<< "\n";
    cout << "Weight"<< "\t"<< "Profit";
    for (int i = 0; i < n; i++) {
        cout << "\n";
        cout << t[i].weight << "\t" << t[i].p;
    }
}

// 2D array to calculate all possible combinations

int calculate(int n, int wt, int x[]) {
    int v[n + 1][wt + 1];

    //i represents rows and w represents columns

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= wt; w++) {
            if (i == 0 || w == 0) {
                v[i][w] = 0;
                cout << v[i][w] << "\t";
            } 
            else {
                int val = w - (t[i - 1].weight);
                if (val < 0) {
                    v[i][w] = v[i - 1][w];
                    cout << v[i][w] << "\t";
                } 
                else {
                    int val1 = v[i - 1][w];
                    int val2 = (v[i - 1][val] + t[i - 1].p);
                    v[i][w] = max(val1, val2);
                    cout << v[i][w] << "\t";
                }
            }
        }
        cout << "\n";
    }

    int i=n,j=wt;

    while(i>0 && j>0){
        if(v[i][j]!=v[i-1][j]){
            x[i]=1;
            j=j-(t[i-1].weight);   //as the element is taken subtract its weight from overall weight of bag
            i=i-1;
        }
        else{
            i=i-1;
        }
    }

    cout<<"\n";
    for(int i=1;i<=n;i++){
        cout<<x[i]<<"\t";
    }
    
    return v[n][wt]; // Return the maximum profit
}

int main() {
    int n = 4;
    int wt = 8;
    int x[10]={0};

    for (int i = 0; i < n; i++) {
        cout << "\n"<< "Enter the weight of the element:"<< "\n";
        cin >> t[i].weight;
        cout << "\n"<< "Enter the profit for the element:"<< "\n";
        cin >> t[i].p;
    }
    cout << "\n";
    displayIP(n);
    wt_sort(n);
    cout << "\n";
    displaySorted(n);
    cout <<"\n"<<"\n";

    int max_profit = calculate(n, wt, x);
    cout <<"\n"<<"The maximum profit that can be obtained is: " << max_profit << "\n";
    return 0;
}


/* OUTPUT : 

PS D:\DAA> g++ knapsack_dynamic.cpp
PS D:\DAA> ./a.exe

Enter the weight of the element:
2

Enter the profit for the element:
1

Enter the weight of the element:
3

Enter the profit for the element:
2

Enter the weight of the element:
4

Enter the profit for the element:
5

Enter the weight of the element:
5

Enter the profit for the element:
6


User Input:
Weight  Profit
2       1
3       2
4       5
5       6

Values after sorting of weights:
Weight  Profit
2       1
3       2
4       5
5       6

0       0       0       0       0       0       0       0       0
0       0       1       1       1       1       1       1       1
0       0       1       2       2       3       3       3       3
0       0       1       2       5       5       6       7       7
0       0       1       2       5       6       6       7       8

0       1       0       1
The maximum profit that can be obtained is: 8 */
