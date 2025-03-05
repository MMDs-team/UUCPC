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

    int n;
    test_in >> n;
    ll a[n];
    for (int i = 0; i < n; i++)
        test_in >> a[i];

    int q, left, right, user_left, user_right;
    test_in >> q;

    bool accepted = true;

    while (q--)
    {
        test_in >> left >> right;
        user_out >> user_left >> user_left;
        test_out >> left >> right;

        if (left == -1 && right == -1)
        {
            if (user_left != -1 || user_right != -1)
                accepted = false;
            break;
        }

        if (user_left == -1 || user_right == -1)
        {
            accepted = false;
            break;
        }

        if (user_left < left || user_right > right)
        {
            accepted = false;
            break;
        }

        if (a[user_left] == a[user_right])
        {
            accepted = false;
            break;
        }

        if (!accepted)
            break;
    }

    if (accepted)
        return 0;
    else
        return 1;
}