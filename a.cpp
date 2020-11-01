#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

void filter(string& prog)
{
    string ans;
    string maps="+-<>.,[]";
    for (int c=0;c<prog.size();c++)
        {
            if (maps.find(prog[c])!=-1)
                ans+=prog[c];
        }
    prog=ans;
    return;
}
void interpret(string& prog)
{
    unordered_map<int,char> cellArr; // using HashMap for maximum negative and positive offset for counter
    int counter = 0;
    stack<int>st; // for carrying out loop calls
    for (int c=0;c<prog.size();c++)
        {
            //cout << c << " " << counter << " " << (int)cellArr[counter] << " " << 
            //st.size() << endl;
            if (prog[c]=='[')
                {
                    if (cellArr[counter]==0)
                        {
                            vector<int>a;
                            a.push_back(c);
                            c++;
                            for (;c<prog.size()&&!a.empty();c++)
                                {
                                if (prog[c]==']')
                                    a.pop_back();
                                else if (prog[c]=='[')
                                    a.push_back(c);
                                }
                            c--;
                        }
                    else  {
                        st.push(c);
                    }
                }
            else if (prog[c]==']')
                {
                    if (cellArr[counter]==0)
                        {
                            st.pop();
                        }
                    else c=st.top();
                }
            else if (prog[c]=='.')
                cout << cellArr[counter];
            else if (prog[c]==',')
                cin >> cellArr[counter];
            else if (prog[c]=='+')
                cellArr[counter]++;
            else if (prog[c]=='-')
                cellArr[counter]--;
            else if (prog[c]=='>')
                counter++;
            else if (prog[c]=='<')
                counter--;
        }
        return;
}

int main(int argc, char **argv) {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string prog;
    string a;
    while(getline(cin,a))
        prog+=a;
    filter(prog);
    //cout << prog << endl;
    interpret(prog);
    return 0;
}