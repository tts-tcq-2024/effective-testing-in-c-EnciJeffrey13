#include <stdio.h>
#include <assert.h>

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[i]);
        }
    }
    return i * j;
}
void TestPrintColorMap() {
    // Redirect stdout to a string buffer
    char buffer[1024] = {0};
    freopen("/dev/null", "a", stdout);
    setbuf(stdout, buffer);
    
    // Call the function
    int result = printColorMap();

    // Restore stdout
    freopen("/dev/tty", "a", stdout);

    // Verify key outputs
    assert(result == 25);
    assert(strstr(buffer, "0 | White | Blue"));
    assert(strstr(buffer, "24 | Violet | Slate"));
    assert(strstr(buffer, "5 | Red | Blue"));

    // Verify line count
    int lineCount = 0;
    for (char *p = buffer; *p; p++) lineCount += (*p == '\n');
    assert(lineCount == 25);

    printf("All test cases passed!\n");
}
int main() {
    int result = printColorMap();
    assert(result == 25);
    printf("All is well (maybe!)\n");
    return 0;
}
