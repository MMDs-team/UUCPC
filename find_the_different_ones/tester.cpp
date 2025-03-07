/*
 * tester.cpp
 */

#include <iostream>
#include <fstream>
#include <string>
typedef long long ll;

using namespace std;
int main(int argc, char const *argv[])
{

    ifstream test_in(argv[1]);  /* This stream reads from test's input file   */
    ifstream test_out(argv[2]); /* This stream reads from test's output file  */
    ifstream user_out(argv[3]); /* This stream reads from user's output file  */

    int tc;
    test_in >> tc;
    bool accepted = true;

    while (tc--) {
        int n;
        test_in >> n;
        ll a[n];
        for (int i = 0; i < n; i++)
        test_in >> a[i];
        
        int q, left, right, user_left, user_right, left_out, right_out;
        test_in >> q;
    
        while (q--)
        {
            test_in >> left >> right;
            user_out >> user_left >> user_right;
            test_out >> left_out >> right_out;

            if (!accepted) continue;

            if (user_left != left_out || user_right != right_out) {
                cout << "Here:" << q + 1 << ' ' << left_out << ' ' << right_out << '\n';
            }
            
            if (left_out == -1 && right_out == -1)
            {
                if (user_left != -1 || user_right != -1)
                accepted = false;
                continue;
            }
            
            
            if (user_left == -1 || user_right == -1)
            {
                accepted = false;
                continue;
            }
            
            
            if (user_left < left || user_right > right)
            {
                accepted = false;
                continue;
            }


            if (a[user_left - 1] == a[user_right - 1])
            {
                accepted = false;
                continue;
            }
        }
    }
    


    if (accepted){
        return 0;
    }else{
        return 1;
    }
}