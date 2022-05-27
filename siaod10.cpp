#include <iostream>
#include <regex>
#include <string>
#include <windows.h>
#include <fstream>
#include <vector>
using namespace std;

bool check_number(string phone_number)
{
    regex regular("^\\+7-([0-9]){3}-([0-9]){3}-([0-9]){2}-([0-9]){2}$");
    return regex_match(phone_number,regular);
}

int KMPSearch(string strin, string substring) {
    int  sl, ssl;
    int d[150];
    int res = -1;
    sl = strin.size();
    ssl = substring.size();

    int  i = 1, j = 0;


    d[0] = 0;
    while (j < ssl && i<ssl) {



        if (substring[i] == substring[j]) {
            d[i] = j + 1;
            i++;
            j++;
        }
        else if (j == 0) {
            d[i] = 0;
            i++;
        }
        else j = d[j - 1];
    }


    int k = 0;
    int l = 0;

    while (k < sl && l < ssl) {
        if (substring[l] == strin[k]) {
            k++;
            l++;
            if (l == ssl)
                return k-ssl;

        }
        else if (l == 0) {
            k++;
            if (k == sl)
                return -1;

        }
        else
            l = d[l - 1];
    }

    return res;
}


int main() {
    SetConsoleOutputCP(CP_UTF8);
    string pattern = "Raw";
    string ss = "sfkjkjsdRaw";
    int d[3];
    vector <string> vec;
    fstream fout;
    fout.open("C:\\Users\\polon\\CLionProjects\\SiAOD_10\\test.txt");
    string a;
    cmatch res;
    regex regular("([\\w]+\\s[\\w]{1}\\.[\\w]{1}\\.)");
    for (int i = 0; i < 3; ++i)
    {
        getline(fout,a,'\n');
        //cout << a << endl;
        int n;
        n = KMPSearch(a,"Слушали сообщение: ") + 19;
        //cout << KMPSearch(a,"Слушали сообщение: ") + 19<< endl;
        a = a.substr(KMPSearch(a,"Слушали сообщение: ")+35,40);
        int n1;
        n1 = a.find('.') + 4;
        a = a.substr(0,n1);
        cout << a << endl;
        vec.push_back(a);

    }
    cout << res.size() << endl;
    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
    }



    return 0;
}
