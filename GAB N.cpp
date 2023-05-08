#include<iostream>
#include<time.h>
#include<cstdlib>

using namespace std;
void goback(int i,int N,int fno) {
  while (i <= fno) {
    int z = 0;
    for (int k = i; k < i + N && k <= fno; k++) {
      cout << "Sending Frame " << k << "..." << endl;
      
    }
    for (int k = i; k < i + N && k <= fno; k++) {
      int f = rand() % 5;
      if (f!=0) {
        cout << "Acknowledgment for Frame " << k << "..." << endl;
        z++;
      } else {
        cout << "Timeout!! Frame Number : " << k << " Not Received" << endl;
        cout << "Retransmitting Window..." << endl;
        break;
      }
    }
    cout << "\n";
    i = i + z;
  }
}
int main() {
  int fno, N;
  srand(time(NULL));
  cout << "Enter the Total number of frames : ";
  cin >> fno;
  cout << "Enter the Window Size : ";
  cin >> N;
  int i = 1;
  goback(i, N, fno);
  
  return 0;
}
