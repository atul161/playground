// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Alien Fred wants to destroy the Earth.
But before he does that, he wants to solve the following problem.




He has the set {1, 2, 3, ..., 2N}.
He wants to split this set into two new sets A and B.
The following conditions must all be satisfied:

Each element of the original set must belong to exactly one of the sets A and B.
The two new sets must have the same size. (I.e., each of them must contain exactly N numbers.)
For each i from 1 to N, inclusive: 
    Let A[i] be the i-th smallest element of A, and let B[i] be the i-th smallest element of B.
    The difference |A[i] - B[i]| must be greater than or equal to K.





You are given the two ints N and K.
Let X be the total number of ways in which Fred can choose the sets A and B.
Return the value (X modulo 1,000,000,007).


DEFINITION
Class:AlienAndSetDiv1
Method:getNumber
Parameters:int, int
Returns:int
Method signature:int getNumber(int N, int K)


CONSTRAINTS
-N will be between 1 and 50, inclusive.
-K will be between 1 and 10, inclusive.


EXAMPLES

0)
2
2

Returns: 2

The initial set is {1, 2, 3, 4}.
The following 6 pairs of subsets are possible in this case:


A={1, 2} and B={3, 4}


A={1, 3} and B={2, 4}


A={1, 4} and B={2, 3}


A={2, 3} and B={1, 4}


A={2, 4} and B={1, 3}


A={3, 4} and B={1, 2}


The first option and the last option are both valid.
The other 4 options are invalid.


Note that order of the two sets matters: the option A={1,2} and B={3,4} differs from the option A={3,4} and B={1,2}.

1)
3
1

Returns: 20



2)
4
2

Returns: 14



3)
10
7

Returns: 40



*/
// END CUT HERE
#line 106 "AlienAndSetDiv1.cpp"
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

#define mp make_pair

class AlienAndSetDiv1
{
public:
 int getNumber(int N, int K)
 {
 //$CARETPOSITION$
 }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 20; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 2; int Arg2 = 14; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 7; int Arg2 = 40; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE

}; 
// BEGIN CUT HERE
int main()
{
 AlienAndSetDiv1 ___test;
 ___test.run_test(-1);
}
// END CUT HERE
