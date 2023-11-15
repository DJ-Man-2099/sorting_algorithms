#include "tests.h"

/**
 * create_listint - Creates a doubly linked list from an array of integers
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
listint_t *create_listint(const int *array, size_t size)
{
    listint_t *list;
    listint_t *node;
    int *tmp;

    list = NULL;
    while (size--)
    {
        node = malloc(sizeof(*node));
        if (!node)
            return (NULL);
        tmp = (int *)&node->n;
        *tmp = array[size];
        node->next = list;
        node->prev = NULL;
        list = node;
        if (list->next)
            list->next->prev = list;
    }
    return (list);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
void test_insertion_sort(void)
{
    int original_stdout = dup(STDOUT_FILENO);
    // Redirect stdout to a file
    freopen("output.txt", "w", stdout);
    listint_t *list;
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    list = create_listint(array, n);
    if (!list)
        return;
    print_list(list);
    printf("\n");
    insertion_sort_list(&list);
    printf("\n");
    print_list(list);
    // Redirect back
    freopen("/dev/tty", "a", stdout);
    FILE *file = fopen("output.txt", "r");
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
                                  "19, 48, 13, 71, 99, 52, 96, 73, 86, 7\n"
                                  "19, 13, 48, 71, 99, 52, 96, 73, 86, 7\n"
                                  "13, 19, 48, 71, 99, 52, 96, 73, 86, 7\n"
                                  "13, 19, 48, 71, 52, 99, 96, 73, 86, 7\n"
                                  "13, 19, 48, 52, 71, 99, 96, 73, 86, 7\n"
                                  "13, 19, 48, 52, 71, 96, 99, 73, 86, 7\n"
                                  "13, 19, 48, 52, 71, 96, 73, 99, 86, 7\n"
                                  "13, 19, 48, 52, 71, 73, 96, 99, 86, 7\n"
                                  "13, 19, 48, 52, 71, 73, 96, 86, 99, 7\n"
                                  "13, 19, 48, 52, 71, 73, 86, 96, 99, 7\n"
                                  "13, 19, 48, 52, 71, 73, 86, 96, 7, 99\n"
                                  "13, 19, 48, 52, 71, 73, 86, 7, 96, 99\n"
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
