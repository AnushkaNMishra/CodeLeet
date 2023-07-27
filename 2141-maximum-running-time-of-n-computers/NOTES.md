Intuition
The problem asks us to find the maximum run time for a robot with n batteries. We have an array batteries that contains the power of each battery. The robot can only run at a constant speed of time units per battery. We need to find the maximum value of time such that the robot can run for n units of time using the given batteries.
​
Approach
The main function, maxRunTime, uses binary search to find the maximum time value. It starts with the left bound left = 1 and the right bound right = sumPower / n, where sumPower is the sum of all battery powers. Then, it performs binary search to find the maximum value of time that satisfies the condition check(n, batteries, time).
​
The check function calculates the total power that the robot can run using the given time and the battery powers. It iterates through the batteries and sums up the minimum of i and time, where i is the power of the current battery. This ensures that the robot can use at most time units of power from each battery. If the total sum of power obtained from all the batteries is greater than or equal to time * n, the function returns true, indicating that the robot can run for n units of time. Otherwise, it returns false.
​
Complexity
Time complexity:
The binary search takes O(log(sumPower / n)) iterations, and for each iteration, the check function takes O(n) time. So, the overall time complexity is O(n log(sumPower / n)).
Space complexity:
The space complexity is O(1) as we are using a constant amount of extra space to store variables.