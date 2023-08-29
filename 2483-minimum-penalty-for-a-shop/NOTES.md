Approach
The function starts by initializing three variables:
​
points: This variable keeps track of the difference between the number of 'Y' and 'N' characters encountered so far.
hour: This variable will store the index of the hour with the maximum number of 'Y' characters encountered.
z: This variable keeps track of the maximum value of points encountered.
The code then enters a loop that iterates through each character in the customers string.
​
Inside the loop:
​
If the current character is 'Y', the points variable is incremented by 1, indicating a customer arrival.
If the current character is 'N', the points variable is decremented by 1, indicating a customer departure.
After updating the points variable, the code checks if the current value of points (representing the difference between customers arrived and departed) is greater than the current maximum value z. If it is, z is updated to the current points value, and the hour is updated to the current index i. This keeps track of the hour with the maximum number of customers.
​
Finally, the function returns hour + 1 as the best closing time. Adding 1 is done to convert the 0-based index to a 1-based hour representation.
​
In summary, this code snippet aims to find the hour with the maximum number of customers based on the given input string of 'Y' and 'N' characters. It uses a sliding window approach to track the difference between customer arrivals and departures, and it updates the best closing time whenever the current window yields a higher number of customers than previous windows.
​
Complexity
Time complexity:O(N)
Space complexity:O(1)