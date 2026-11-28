#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cstdint>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <numeric>
#include <sstream>
using namespace std;

#ifndef DATA_STRUCTURES_DEFINED
#define DATA_STRUCTURES_DEFINED
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct Node {
    int val;
    vector<Node*> children;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
};
#endif

/*******************************************************************************

 * ALGORITHM IMPLEMENTAIONS

 *

 *  /\  |  _   _  ._ o _|_ |_  ._ _   _ 

 * /--\ | (_| (_) |  |  |_ | | | | | _> 

 *         _|                      

 *

 * MAXIMUM SUBARRAY

 *

 * In computer science, the maximum subarray problem is the task of finding the 

 * contiguous subarray within a one-dimensional array of numbers (containing at

 * least one positive number) which has the largest sum. For example, for the 

 * sequence of values −2, 1, −3, 4, −1, 2, 1, −5, 4; the contiguous subarray 

 * with the largest sum is 4, −1, 2, 1, with sum 6.

 *

 * The problem was first posed by Ulf Grenander of Brown University in 1977, as 

 * a simplified model for maximum likelihood estimation of patterns in digitized 

 * images. A linear time algorithm was found soon afterwards by Jay Kadane of 

 * Carnegie-Mellon University (Bentley 1984).

 *

 * http://en.wikipedia.org/wiki/Maximum_subarray_problem

 ******************************************************************************/



#ifndef	MAX_SUBARRAY__

#define	MAX_SUBARRAY__



namespace alg {

	/**

	 * To calc the maximum subarray, and return the range.

	 */

	static void max_subarray(int arr[], int len,  int *begin, int *end) {

		int i;

		int subvalue = arr[0];

		int maxvalue = arr[0];

		*begin = 0;

		*end = 0;

		int new_begin;



		for (i = 1;i < len;i++) {

			if (subvalue > 0) {		// positive contribute to the following element

				subvalue +=	arr[i];

			} else {

				subvalue = arr[i];	// negative contribute, drop it!

				new_begin = i;		// then set the new beginning.

			}



			if (maxvalue < subvalue) {	// if a larger subarray appears, record the range

				maxvalue = subvalue;

				*begin = new_begin;

				*end = i;

			}

		}

	}

}



#endif //