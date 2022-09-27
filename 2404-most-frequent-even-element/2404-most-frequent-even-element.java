class Solution {
    public int mostFrequentEven(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        int ans = -1, freq = 0;
        for(int i: nums) {
            if(i%2 == 0) {
                map.put(i, map.getOrDefault(i, 0)+1);
                int f = map.getOrDefault(i, 0);
                if(f>freq) {
                    freq = f;
                    ans = i;
                } else if(f==freq) {
                    ans = Math.min(ans, i);
                }
            }
        }
        return ans;
    }
}