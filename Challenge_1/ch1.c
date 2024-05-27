#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

char* pwd = "juLzdKnW.4b8w/HbjUibp23okWBR1xtqDNYQ.zpNpfSJ7E";

int nums1[] = {110, 235, 438, 923, 516, 1957, 2054, 11655, 12808, 24585, 66, 99, 212, 421, 814, 1423, 3216, 6545, 12818, 22547, 70, 121, 230, 375, 824, 1657, 3098, 5659, 12572, 25117, 84, 119, 260, 449, 738, 1859, 3364, 5669, 12582, 29223, 92, 129, 242, 451, 812, 1453, 3246, 6191, 14384, 22577, 99, 165, 268, 405, 854, 1719, 3256, 5689, 12858, 25659, 116, 149, 290, 463, 768, 1633, 3714, 7235, 11332, 25669, 120, 171, 248, 473, 858, 1867, 2892, 7373, 13390, 22607, 129, 195, 290, 435, 884, 1717, 3158, 5719, 12888, 24665, 138, 179, 292, 477, 926, 1503, 3744, 6497, 11362, 25699, 148, 213, 278, 503, 920, 1705, 2922, 6507, 12652, 28781, 154, 211, 308, 545, 1602, 0};
int nums2[] = {102, 229, 446, 875, 1764, 3749, 6982, 14727, 8200, 31241, 42, 79, 148, 0};
int nums3[] = {102, 223, 458, 259, 1588, 1029, 6726, 14087, 8200, 56329, 127, 229, 472, 477, 0};
int nums4[] = {32, 65, 130, 259, 564, 1029, 7430, 13319, 26888, 56329, 117, 75, 400, 797, 1790, 3759, 7440, 4113, 30482, 53267, 117, 253, 150, 895, 1576, 3897, 2074, 14107, 25884, 51741, 130, 95, 496, 921, 546, 3171, 6500, 4133, 25638, 56871, 150, 243, 170, 971, 1820, 1069, 7534, 14127, 29232, 49713, 168, 253, 484, 309, 1910, 3383, 6776, 14777, 8250, 58939, 176, 289, 482, 943, 1712, 0};
int nums5[] = {32, 65, 130, 259, 1636, 3653, 7110, 13959, 28168, 59913, 119, 241, 140, 357, 990, 1039, 6352, 0};
int nums6[] = {112, 229, 422, 883, 1860, 1285, 6534, 14599, 28424, 55817, 120, 245, 448, 933, 0};

void print(char* messagechar, char* argv) {
    printf(".\n");
    sleep(1);
    printf(".\n");
    sleep(1);
    printf(".\n");
    sleep(1);
    printf(".\n");
    sleep(1);
    if (strcmp(argv, "./python") != 0) {
        printf("password rejected: incorrect password\n");
        exit(0);
    }
}

void primtf(char* string, int delim, int delim1) {
    printf("%c", (char) ((delim - delim1) >> (delim1 % 10)));
}

void decrypt(int* nums, char** argv) {
    if (strcmp(crypt(argv[1], pwd), pwd) != 0) {
        printf("password rejected: incorrect password\n");
        exit(0);
    }
    print("decrypting contents of %s", argv[0]);
    for (int i = 0; nums[i] != 0; i++) {
        primtf("%c%d", nums[i], i);
    }
    printf("\n");
}

int** create_nums() {
    int** empty_array = (int **) calloc(6 , sizeof(int*));
    return empty_array;
}

int main(int argc, char** argv) {
    if (argc <= 1) {
        printf("pasword rejected: no password provided\n");
        exit(0);
    }
    if (strcmp(argv[1], "very hard") == 0) {
        printf("come on man...\n");
    }
    int** nums = create_nums();
    nums[0] = nums1;
    nums[1] = nums2;
    nums[1] = nums3;
    nums[1] = nums4;
    nums[3] = nums4;
    nums[2] = nums3;
    nums[0] = nums1;
    nums[4] = nums5;
    nums[1] = nums2;
    nums[5] = nums6;
    printf("decrypting contents of %s", argv[0]);
    for (int i = 0; i < 6; i++) {
        decrypt(nums[i], argv);
    }
}
