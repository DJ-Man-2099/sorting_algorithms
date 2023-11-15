#include <CUnit/Basic.h>
#include "tests.h"

int main()
{
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("Example Suite", NULL, NULL);
    CU_add_test(suite, "Example Test", test_bubble_sort);
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}
