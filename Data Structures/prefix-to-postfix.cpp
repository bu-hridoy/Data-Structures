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

int main() {
   string S;
   cin>>S;
   int sz = S.size();
   stack<char> st;
   string postfix = "";

   for(int i = 0; i < sz; i++) {
      if(S[i] >= 'a' && S[i] <= 'z')
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

   cout << postfix << endl;

}

