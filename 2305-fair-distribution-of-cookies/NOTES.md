class Solution {
public:
int distributeCookies(vector<int>& cookies, int k) {
}
};
Intuition
The intuition behind the solution is to explore all possible distributions of cookies among the children and calculate the maximum total cookies obtained by any single child in each distribution. By doing so, we aim to find the distribution that minimizes the maximum total cookies obtained by any child. The process involves backtracking and trying different cookie assignments to the children until all possible distributions are explored, and then returning the minimum unfairness found
​
Approach
Initialize a variable result to keep track of the minimum unfairness. Set it to a very large value initially.
Define a helper function dfs that performs the backtracking.
In the dfs function, the base case is when all cookies are distributed to the children. At this point, we need to calculate the maximum total cookies obtained by any single child in this distribution and update the result accordingly.
For each cookie, we have k options: assign it to one of the k children.
Recursively call the dfs function for the next cookie with updated state (assigning the current cookie to each child).
Call the dfs function to explore all possible distributions.
Return the result after exploring all distributions.
Complexity
Time complexity: The time complexity of this approach is exponential since we explore all possible distributions of cookies among k children.
Space complexity: The space complexity is O(k), where k is the number of children, due to the child array.