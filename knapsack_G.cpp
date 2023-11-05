

// Fractional KnapSack


#include<iostream>
using namespace std;

//pw1 contains original p/w ratio and pw2 contains sorted p/w order

//calculate the profit/weight ratio
void calc_pw(float p[],float w[],float pw1[],float pw2[],int n){
    for(int i=0;i<n;i++){
        pw1[i]=pw2[i]=(p[i])/(w[i]);
    }
}

//sort the p/w ratio in decreasing order
void sort_pw(float pw2[],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(pw2[i]<pw2[j]){
                float temp;
                temp=pw2[i];
                pw2[i]=pw2[j];
                pw2[j]=temp;
            }
        }
    }
}

void display_pw(float pw[],int n){
    for(int i=0;i<n;i++){
        cout<<pw[i]<<"\t";
    }
}

void input(float a[],int n){
    for(int i=0;i<n;i++){
        cout<<"\n"<<"Enter the values:"<<"\n";
        cin>>a[i];
    }
}

void knapSack(float p[],float w[],float pw1[], float pw2[],int n,int max_wt){
    float net_profit= 0;
    float remaining_wt=max_wt;
    float sum_wt=0;
    int trackArray[n];

        for(int i=0;i<n;i++){
            trackArray[i]=0;
        }

        while(sum_wt < max_wt){
            for(int i=0;i<n;i++){
            int temp;
            for(int j=0;j<n;j++){
                if(pw2[i]==pw1[j] && trackArray[j]==0){
                    temp=j;
                    if(w[temp]<=remaining_wt){
                        trackArray[j]=1;
                        cout<<w[temp]<<"\n";
                        remaining_wt=remaining_wt-w[temp];
                        sum_wt=sum_wt+w[temp]; 
                        net_profit=net_profit+p[temp];
                        break;
                    }
                    else{
                        trackArray[j]=1;
                        float wt = (remaining_wt/w[temp]);
                        cout<<wt<<"\n";
                        remaining_wt=remaining_wt-wt;
                        sum_wt=sum_wt+wt;
                        net_profit=net_profit + (wt*pw1[temp]);
                        break;
                }
            }
        }
    }
    // // Break the loop if the sum_wt exceeds max_wt 
        if ((sum_wt-max_wt)<=0.000001) {
            break;
        }
}
    //cout<<remaining_wt<<"\n";
    cout<<"\n"<<"Net profit:"<<"\n";
    cout<<net_profit;
}

int main(){
    int n,max_wt=15;
    cout<<"\n"<<"Enter the number of object:"<<"\n";
    cin>>n;
    float p[20];
    float w[20];
    float pw1[20];
    float pw2[20];

    cout<<"\n"<<"Enter the profit for each object:"<<"\n";
    input(p,n);
    cout<<"\n"<<"Enter the weight for each object:"<<"\n";
    input(w,n);

    calc_pw(p,w,pw1,pw2,n);

    sort_pw(pw2,n);

    cout<<"\n"<<"The p/w ratio before sorting :"<<"\n";
    display_pw(pw1,n);
    
    cout<<"\n"<<"The p/w ratio after sorting :"<<"\n";
    display_pw(pw2,n);

    cout<<"\n"<<"Weights added into the bag:"<<"\n";
    knapSack(p,w,pw1,pw2,n,max_wt);

    return 0;
}



/* OUTPUT : 

PS D:\DAA> g++ knap_sack.cpp
PS D:\DAA> ./a.exe

Enter the number of object:
7

Enter the profit for each object:

Enter the values:
10

Enter the values:
5

Enter the values:
15

Enter the values:
7

Enter the values:
6

Enter the values:
18

Enter the values:
3

Enter the weight for each object:

Enter the values:
2

Enter the values:
3

Enter the values:
5

Enter the values:
7

Enter the values:
1

Enter the values:
4

Enter the values:
1

The p/w ratio before sorting :
5       1.66667 3       1       6       4.5     3
The p/w ratio after sorting :
6       5       4.5     3       3       1.66667 1
Weights added into the bag:
1
2
4
5
1
0.666667
0.190476

Net profit:
53.3016 */
