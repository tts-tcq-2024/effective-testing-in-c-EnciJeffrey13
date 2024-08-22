// #include <stdio.h>
// #include <assert.h>

// char size(int cms) {
//     char sizeName = '\0';
//     if(cms < 38) {
//         sizeName = 'S';
//     } else if(cms > 38 && cms < 42) {
//         sizeName = 'M';
//     } else if(cms > 42) {
//         sizeName = 'L';
//     }
//     return sizeName;
// }

// int main() {
//     assert(size(37) == 'S');
//     assert(size(40) == 'M');
//     assert(size(43) == 'L');
//     // assert(size(39) == 'S');//should fail
//     // assert(size(43) == 'M');//should fail
//     // assert(size(35) == 'L');//should fail
//     printf("All is well (maybe!)\n");
//     return 0;
// }
#include <stdio.h>
#include <assert.h>

char size(int cms) {
    if (cms < 38) {
        return 'S';
    } else if (cms <= 42) {  // Adjusted to include 38-42 as 'M'
        return 'M';
    } else {
        return 'L';
    }
}

int main() {
    // Positive test cases
    assert(size(37) == 'S');
    assert(size(40) == 'M');
    assert(size(43) == 'L');
    
    // Negative test cases to illustrate edge cases
    assert(size(39) == 'S');  // This should not be 'S'
    assert(size(43) == 'M');  // This should not be 'M'
    assert(size(35) == 'L');  // This should not be 'L'

    printf("All is well (maybe!)\n");
    return 0;
}
