class Solution {
    public String licenseKeyFormatting(String s, int k) {
        int len = s.length();
        String ans = "";
        int temp = 0;
        for (int i = len - 1; i >= 0; i--) {
            if (temp == k) {
                temp = 0;
                ans = '-' + ans;
            }
            if (s.charAt(i) != '-') {
                if (Character.isLowerCase(s.charAt(i)))
                    ans = Character.toUpperCase(s.charAt(i)) + ans;
                else
                    ans = s.charAt(i) + ans;
                temp++;
            }
        }
        if (ans == "") return ans;
        if (ans.charAt(0) == '-') return ans.substring(1, ans.length());
        return ans;
    }
}