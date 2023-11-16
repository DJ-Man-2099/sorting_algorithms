#include "tests.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
void test_bubble_sort(void)
{
    // Redirect stdout to a file
    freopen("0-output.txt", "w", stdout);
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    bubble_sort(array, n);
    printf("\n");
    print_array(array, n);
    // Redirect back
    freopen("/dev/tty", "a", stdout);
    FILE *file = fopen("0-output.txt", "r");
    if (file == NULL)
    {
        CU_FAIL("Failed to open file!");
        return;
    }

    // Read the contents of the file
    char buffer[1000];
    fread(buffer, 1000, 1, file);
    const char *multiLineString = "19, 48, 99, 71, 13, 52, 96, 73, 86, 7\n"
                                  "\n"
                                  "19, 48, 71, 99, 13, 52, 96, 73, 86, 7\n"
                                  "19, 48, 71, 13, 99, 52, 96, 73, 86, 7\n"
                                  "19, 48, 71, 13, 52, 99, 96, 73, 86, 7\n"
                                  "19, 48, 71, 13, 52, 96, 99, 73, 86, 7\n"
                                  "19, 48, 71, 13, 52, 96, 73, 99, 86, 7\n"
                                  "19, 48, 71, 13, 52, 96, 73, 86, 99, 7\n"
                                  "19, 48, 71, 13, 52, 96, 73, 86, 7, 99\n"
                                  "19, 48, 13, 71, 52, 96, 73, 86, 7, 99\n"
                                  "19, 48, 13, 52, 71, 96, 73, 86, 7, 99\n"
                                  "19, 48, 13, 52, 71, 73, 96, 86, 7, 99\n"
                                  "19, 48, 13, 52, 71, 73, 86, 96, 7, 99\n"
                                  "19, 48, 13, 52, 71, 73, 86, 7, 96, 99\n"
                                  "19, 13, 48, 52, 71, 73, 86, 7, 96, 99\n"
                                  "19, 13, 48, 52, 71, 73, 7, 86, 96, 99\n"
                                  "13, 19, 48, 52, 71, 73, 7, 86, 96, 99\n"
                                  "13, 19, 48, 52, 71, 7, 73, 86, 96, 99\n"
                                  "13, 19, 48, 52, 7, 71, 73, 86, 96, 99\n"
                                  "13, 19, 48, 7, 52, 71, 73, 86, 96, 99\n"
                                  "13, 19, 7, 48, 52, 71, 73, 86, 96, 99\n"
                                  "13, 7, 19, 48, 52, 71, 73, 86, 96, 99\n"
                                  "7, 13, 19, 48, 52, 71, 73, 86, 96, 99\n"
                                  "\n"
                                  "7, 13, 19, 48, 52, 71, 73, 86, 96, 99\n";
    // Assert that the printed string is as expected
    CU_ASSERT_STRING_EQUAL(buffer, multiLineString);
    fclose(file);
}
