#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> stack;
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); ++i) {
        string m;
        m.append(1,s[i]);
        stack.push_back(m);
    }
    for (int j = 0; j < stack.size(); ++j) {cout << stack[j] << '\t';}
    cout << endl;
    int counter = 0;
    while(stack.size() > 1){
        if (counter == stack.size()) counter = 0;
        if((stack[counter] == "+" || stack[counter] == "-" || stack[counter] == "*" || stack[counter] == "/") && \
        !(stack[counter+1] == "+" || stack[counter+1] == "-" || stack[counter+1] == "*" || stack[counter+1] == "/") \
        && !(stack[counter+2] == "+" || stack[counter+2] == "-" || stack[counter+2] == "*" || stack[counter+2] == "/"))
        {
            int num1 = stoi(stack[counter+1]);
            int num2 = stoi(stack[counter+2]);
            string finNum;
            if (stack[counter] == "+")
                finNum = to_string(num1 + num2);
            else if (stack[counter] == "-")
                finNum = to_string(num1 - num2);
            else if (stack[counter] == "*")
                finNum = to_string(num1 * num2);
            else if(stack[counter] == "/")
                finNum = to_string(num1 / num2);
            stack.insert(stack.begin()+counter,finNum);
            stack.erase(stack.begin()+(counter+3));
            stack.erase(stack.begin()+(counter+2));
            stack.erase(stack.begin()+(counter+1));
            }
        cout << stack[counter] << endl;

        counter++;


        for (int j = 0; j < stack.size(); ++j) {
            cout << stack[j] << '\t';
        }
        cout << endl;

    }
}