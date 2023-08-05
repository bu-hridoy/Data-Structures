#include<bits/stdc++.h>
using namespace std;

int prec(char ch) {
   if(ch == '+' || ch == '-') {
      return 1;
   } else if(ch == '*' || ch == '/') {
      return 2;
   }

   return 0;
}

string getPostfix(string S)
{
   int sz = S.size();
   stack<char> st;
   string postfix = "";

   for(int i = 0; i < sz; i++) {
      if(S[i] >= '0' && S[i] <= '9')
         postfix += S[i];
      else if(S[i] == '(')
         st.push(S[i]);
      else if(S[i] == ')') {
         while(st.size() && st.top() != '(') {
            postfix += st.top();
            st.pop();
         }
         if(st.size())
            st.pop();
      }else {
        while(st.size() && prec(st.top()) >= prec(S[i])) {
           postfix += st.top();
           st.pop();
        }
        st.push(S[i]);
      }
   }

   while(st.size()) {
      postfix += st.top();
      st.pop();
   }

   return postfix;
}

double getSum(double a, double b, char sign)
{
    if(sign == '+') return a+b;
    else if(sign == '-') return a-b;
    else if(sign == '*') return a*b;
    return (double)a/(double)b;
}

double evaluteExp(string S)
{
   int sz = S.size();
   stack<double> st;
   double res = 0;

   for(int i = 0; i < sz; i++) {
      if(S[i] >= '0' && S[i] <= '9')
         st.push(S[i] - '0');
      else {
        double t1 = st.top();
        st.pop();
        double t2 = st.top();
        st.pop();
        res = getSum(t2,t1,S[i]);
        st.push(res);
      }
   }

   return res;
}

int main() {
   string S;
   cin>>S;

   string postfix = getPostfix(S);
   cout << evaluteExp(postfix) << endl;
}


