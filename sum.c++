#include <iostream>
using namespace std;
int func(int n) {
   int i;
   int flag = 1;
   for(i = 2; i <= n/2; ++i) {
      if(n % i == 0) {
         flag = 0;
         break;
      }
   }
   return flag;
}
int main() {
   int n , i;
   cout << "Enter a positive integer: "<<endl;
   cin >> n;
   for(i = 2; i <= n/2; ++i) {
      if (func(i)) {
         if (func(n - i)) {
            cout << n << " = " << i << " + " << n-i << endl;
         }
      }
   }
   return 0;
}
