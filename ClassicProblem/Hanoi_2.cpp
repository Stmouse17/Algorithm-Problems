#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    int n;
    char from, aux, to;
};

void hanoi_iterative(int n, char A, char B, char C)
{
    stack<Node> st;

    st.push({n, A, B, C});

    while (!st.empty())
    {
        Node temp = st.top();
        st.pop();

        if (temp.n == 1)
        {
            cout << "Move disk from "
                 << temp.from << " to "
                 << temp.to << endl;
        }
        else
        {

            st.push({temp.n - 1, temp.aux, temp.from, temp.to});

            st.push({1, temp.from, temp.aux, temp.to});

            st.push({temp.n - 1, temp.from, temp.to, temp.aux});
        }
    }
}

int main()
{
    int n;
    cin >> n;

    hanoi_iterative(n, 'A', 'B', 'C');

    return 0;
}