// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Little Elephant from the Zoo of Lviv likes balls. He has some balls arranged in a row. Each of those balls has one of three possible colors: red, green, or blue.




You are given a string S. This string represents all the balls that are initially in the row (in the order from left to right). Red, green, and blue balls are represented by characters 'R', 'G', and 'B', respectively. In one turn Little Elephant can remove either the first ball in the row, or the last one. 




Little Elephant wants to obtain a row in which all balls have the same color.
Return the smallest number of turns in which this can be done.


DEFINITION
Class:LittleElephantAndBallsAgain
Method:getNumber
Parameters:string
Returns:int
Method signature:int getNumber(string S)


CONSTRAINTS
-S will contain between 1 and 50 characters, inclusive.
-S will consist only of characters 'R', 'G' and 'B'.


EXAMPLES

0)
"RRGGBB"

Returns: 4

One possible optimal solution is to remove 2 balls from the front and 2 from the back. The total number of turns is 2+2 = 4. After those 4 turns only green balls remained on the table.

1)
"R"

Returns: 0

You don't need to do any turns in this case, so the answer is 0.

2)
"RGBRGB"

Returns: 5

In any optimal solution only one of these six balls will remain on the table.

3)
"RGGGBB"

Returns: 3



4)
"RGBRBRGRGRBBBGRBRBRGBGBBBGRGBBBBRGBGRRGGRRRGRBBBBR"

Returns: 46



*/
// END CUT HERE
#line 72 "LittleElephantAndBallsAgain.cpp"
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

class LittleElephantAndBallsAgain
{
public:
 int getNumber(string S)
 {
 //$CARETPOSITION$
 }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "RRGGBB"; int Arg1 = 4; verify_case(0, Arg1, getNumber(Arg0)); }
	void test_case_1() { string Arg0 = "R"; int Arg1 = 0; verify_case(1, Arg1, getNumber(Arg0)); }
	void test_case_2() { string Arg0 = "RGBRGB"; int Arg1 = 5; verify_case(2, Arg1, getNumber(Arg0)); }
	void test_case_3() { string Arg0 = "RGGGBB"; int Arg1 = 3; verify_case(3, Arg1, getNumber(Arg0)); }
	void test_case_4() { string Arg0 = "RGBRBRGRGRBBBGRBRBRGBGBBBGRGBBBBRGBGRRGGRRRGRBBBBR"; int Arg1 = 46; verify_case(4, Arg1, getNumber(Arg0)); }

// END CUT HERE

}; 
// BEGIN CUT HERE
int main()
{
 LittleElephantAndBallsAgain ___test;
 ___test.run_test(-1);
}
// END CUT HERE
