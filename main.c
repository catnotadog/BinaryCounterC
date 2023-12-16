#include <stdio.h>

int main() {
    printf("cnad binary counter\npress enter to start\n");
    getchar(); // Waits for user input

    int bits[32] = {0};
    bits[0] = 0;
    int decimalNum = 0;

    while (decimalNum < 2147483647) {
        bits[0]++;
        for (size_t i = 0; i < sizeof(bits) / sizeof(bits[0]); i++) {
            if (bits[i] <= 1) continue;
            bits[i] = 0;
            bits[i + 1]++;
        }
        decimalNum++;
        char output[33];
        for (int i = 31; i >= 0; i--) {
            output[i] = bits[31-i]+48; // NOLINT(*-narrowing-conversions)
        }
        output[32] = '\0';
        printf("%s (%d)\n", output, decimalNum);
    }

    return 0;
}