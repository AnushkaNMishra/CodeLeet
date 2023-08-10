​
Please upvote my comment so that i get to win the 2022 giveaway and motivate to make such discussion post.
Happy new Year 2023 to all of you
keep solving keep improving
Link To comment
Leetcode Give away comment
​
Before commig over this Problem solve previous version of it.
33. Search in Rotated Sorted Array
​
The idea is the same as the previous one without duplicates.
The only difference is that due to the existence of duplicates,
arr[l] == arr[mid] could be possible, the first half could be out of order
(i.e. not in the ascending order, e.g. {3, 1, 2, 3, 3, 3, 3})
we have to deal this case separately.
In that case, it is guaranteed that arr[high] also equal to arr[mid],
so the condition arr[mid] == arr[l] == arr[r] can be checked before the original logic,
if so then move left and right both towards the middle by 1 and repeat.
Closer look to the duplicate case
​
let go in detail...
​
{3, 1, 2, 3, 3, 3, 3})
​
I have taken the same eg as above,
​
so we know when we divide array,
​
either of 1 half has to be sorted because since the array is rotated, still one half will be sorted and i fell you understand this case,
​
now the problem is , as in above case if i some how find two halves let say
​
3 1 2 3 is one half, and 3 3 3 is another half and our mid is element 3 also it at index '3'
​
ok i hope you get it
​
now,
​
can we distingusih over which half we should minimize are search space, can we ?