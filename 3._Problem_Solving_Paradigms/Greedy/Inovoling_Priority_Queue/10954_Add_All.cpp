#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n,s;
    while (cin>>n, n!=0){
        priority_queue<int> pq;
        while (n--){
            cin >> s; pq.push(-s);
        }
        int sum=0, cost=0;
        while (pq.size()>1){
            sum += -pq.top();
            pq.pop();
            sum += -pq.top();
            pq.pop();
            pq.push(-sum);
            cost += sum;
            sum = 0;
        }
        cout << cost << "\n";
    }
    
}