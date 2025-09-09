package Lab0;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            // 读入target
            int target = sc.nextInt();
            sc.nextLine(); 

            // 读入数组
            String[] parts = sc.nextLine().split(" ");
            int[] nums = new int[parts.length];
            for (int i = 0; i < parts.length; i++) {
                nums[i] = Integer.parseInt(parts[i]);
            }

            for (int i = 0; i < nums.length; i++) {
                for (int j = i + 1; j < nums.length; j++) {
                    if (nums[i] + nums[j] == target) {
                        System.out.println(i + " " + j);
                        return; // 找到答案后直接退出
                    }
                }
            }
        }
    }
}
