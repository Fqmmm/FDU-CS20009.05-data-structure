package Lab0;

import java.util.*;

public class SolutionWithHashCode {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            // 读入 target
            int target = sc.nextInt();
            sc.nextLine(); // 读掉换行

            // 读入数组 nums
            String[] parts = sc.nextLine().split(" ");
            int[] nums = new int[parts.length];
            for (int i = 0; i < parts.length; i++) {
                nums[i] = Integer.parseInt(parts[i]);
            }

            // 用哈希表记录已经遍历过的数和它的下标
            Map<Integer, Integer> map = new HashMap<>();

            for (int i = 0; i < nums.length; i++) {
                int complement = target - nums[i];
                if (map.containsKey(complement)) {
                    System.out.println(map.get(complement) + " " + i);
                    return; // 找到结果立即退出
                }
                map.put(nums[i], i);
            }
        }
    }
}
