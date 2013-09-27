// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Little Elephant from the Zoo of Lviv likes balls.
He has some balls that he wants to arrange into a row on the table.
Each of those balls has one of three possible colors: red, green, or blue.




You are given a string S.
This string represents all of the balls Little Elephant has, in the order in which he will be placing them onto the table.
Red, green, and blue balls are represented by the characters 'R', 'G', and 'B', respectively.
Each time Little Elephant places a new ball onto the table, he may add it anywhere into the row of already placed balls.




Additionally, each time Little Elephant adds a ball to the table, he scores some points (possibly zero).
The number of points is calculated as follows:

If this is the first ball being placed on the table, there are 0 points for it.
If he adds the current ball to one of the ends of the row, the number of points scored is equal to the number of different colors of the balls on the table, excluding the current ball.
If he adds the current ball between two other balls, the number of points scored is equal to the number of different colors of the balls before the current ball, plus the number of different colors of the balls after the current ball.





For example, suppose that the balls currently on the table form the row "GBBG". 
Little Elephant now wants to add a new red ball ('R').
One of the options is to add it to the beginning.
This scores 2 points and produces the row "RGBBG".
Another option is to add it between "GBB" and "G".
There are 2 distinct colors in "GBB" and 1 in "G", so this move is worth 2+1 = 3 points.
This move produces the row "GBBRG".




Return the maximum total number of points that Little Elephant can earn for placing the balls onto the table.


DEFINITION
Class:LittleElephantAndBalls
Method:getNumber
Parameters:string
Returns:int
Method signature:int getNumber(string S)


CONSTRAINTS
-S will contain between 1 and 50 characters, inclusive.
-S will consist only of characters 'R', 'G' and 'B'.


EXAMPLES

0)
"RGB"

Returns: 3

Any strategy is optimal here. Each strategy scores 0+1+2 = 3 points.

1)
"RGGRBBB"

Returns: 21



2)
"RRRGBRR"

Returns: 16



3)
"RRRR"

Returns: 5



4)
"GGRRRGR"

Returns: 18



5)
"G"

Returns: 0



*/
// END CUT HERE
#line 105 "LittleElephantAndBalls.cpp"
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define range(i, n) for (int i=0; i<(n); ++i)
#define all(a) (a).begin(),a.end()
#define two(i) (1<<(i))

typedef vector<int> VI;
typedef pair<int, int> PII;

class LittleElephantAndBalls
{
public:
 int getNumber(string S)
 {
 //$CARETPOSITION$
    int n = S.size();
    set<char> l, r;
    int ans = 0;
    range(i, n) {
        char ch = S[i];
        ans += l.size() + r.size();
        if (l.find(ch) == l.end()) l.insert(ch); else r.insert(ch);
    }
    return ans;
 }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "RGB"; int Arg1 = 3; verify_case(0, Arg1, getNumber(Arg0)); }
	void test_case_1() { string Arg0 = "RGGRBBB"; int Arg1 = 21; verify_case(1, Arg1, getNumber(Arg0)); }
	void test_case_2() { string Arg0 = "RRRGBRR"; int Arg1 = 16; verify_case(2, Arg1, getNumber(Arg0)); }
	void test_case_3() { string Arg0 = "RRRR"; int Arg1 = 5; verify_case(3, Arg1, getNumber(Arg0)); }
	void test_case_4() { string Arg0 = "GGRRRGR"; int Arg1 = 18; verify_case(4, Arg1, getNumber(Arg0)); }
	void test_case_5() { string Arg0 = "G"; int Arg1 = 0; verify_case(5, Arg1, getNumber(Arg0)); }

// END CUT HERE

}; 
// BEGIN CUT HERE
int main()
{
 LittleElephantAndBalls ___test;
 ___test.run_test(-1);
}
// END CUT HERE
