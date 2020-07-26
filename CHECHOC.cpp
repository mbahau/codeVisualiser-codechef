//Test Case Generator for CHECHOC Codechef

#include<bits/stdc++.h>

using namespace std;

//test case genereator code
vector<int> testCase(void)
{
    vector<int>ret;
    ret.push_back(1+rand()%20);
    ret.push_back(1+rand()%20);
    ret.push_back(1+rand()%200);
    ret.push_back(1+rand()%200);

    return ret;
}

//correct code
int correct(int n, int m, int x, int y)
{
        int ret; int a,b;
        if(y>=2*x) {    ret = n*m*x*10; return ret; }
        if(n*m==1) {    ret = x; return ret; }
        if(x>y) x=y;
        a = (n*m+1)/2,b=n*m-a;
        ret= max( a* x + b*(y-x), a*(y-x) + b*x );
        
        return ret;
}


//doubtful code || paste your code here , carefully
int doubt(int n, int m, int x, int y)
{
        int ret,a,b;

        if(y>=2*x) {    ret = n*m*x; return ret; }
        if(n*m==1) {    ret = x; return ret; }
        if(x>y) x=y;
        a = (n*m+1)/2,b=n*m-a;
        ret= a* x + b*(y-x);
        
        return ret;
}




int main()
{
    cout<<"Enter number of wrong answer you want\n";
    int c=0,t=0; cin>>c; // Number of wrong answer you want
    int CN=1;
    while(true)
    {
        vector<int> v = testCase();      
    
        int A1 = correct(v[0],v[1],v[2],v[3]); 
        int A2 = doubt(v[0],v[1],v[2],v[3]);

        if(A1!=A2)
        {
            cout<<"Wrong answer: \n"<<"n= "<<v[0]<<" m= "<<v[1]<<" x= "<<v[2]<<" y= "<<v[3]<<endl;
            cout<<"Ans: "<<A1<<" || Your Ans: "<<A2<<" \nDifference: "<<A1-A2<<"\n\n";
            CN++;
            if(CN>=c) return 0;
        }
        t++;
        if(t>1000000) {
            cout<<"Your code passed "<<t<<" test cases"<<endl;
            return 0;
        }

    }
}