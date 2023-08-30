#include <iostream>
#include <vector>
using namespace std;
    vector<int> stack;
int top(){
    
    return stack[stack.size()-1];

}
int main() {
    vector<int> arr;
    vector<int> result;
    
    while (1) {
        int x;
        cin >> x;
        if(x == -1) 
            break;
        arr.push_back(x);
        result.push_back(-1);
    }

    for (int i = 0; i < arr.size(); i++){
        while(stack.size()!=0 && arr[i]>arr[top()]){
            result[top()] = arr[i];
            stack.pop_back();
        }
        stack.push_back(i);
    }
    
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << ' ';
    }
    
}
