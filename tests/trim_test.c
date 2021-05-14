#include "cester.h"
#include "../trim.h"
#include <ctype.h>
#ifndef __BASE_FILE__
#define CESTER_NO
#endif

CESTER_MOCK_FUNCTION(trim(char *p_word), char*, 
    p_word = "Maftun"; //atanacak deger
    return p_word;
)
/*
@description :Trim fonksiyonun verilen karakter dizisinin sagdan ve soldan bosluklarini silerek bosluksuz sekilde 
geri dondurmesi basari olcutumuzdur.
@author: MAFTUN HASHIMLI - G18120554
*/
CESTER_TEST(check_mocked_function, test_instance,
     char *p_word = "  Maftun ";
     char *trimed = trim(p_word);
    cester_assert_str_equal(trimed, "Maftun");
)
/*
@description : Trim fonksiyonunun eger karakter dizisi NULL degilse NULL dondurmemesi basari olctumuzdur.
@author: MAFTUN HASHIMLI - G18120554
*/
CESTER_TEST(test_assert_not_equal, test_instance, 
    char *p_word = "  Maftun ";
     char *trimed = trim(p_word);
    cester_assert_not_equal(NULL, trimed);
)
/*
@description : Trim fonksiyonunun verilen karakter dizisinin boyutunu dogru dondurmesi basari olcutumuzdur.
@author: MAFTUN HASHIMLI - G18120554
*/
CESTER_TEST(test_assert_cmp_int, test_instance, 
    char *p_word = "  Maftun ";
    cester_assert_int_eq(6, strlen(trim(p_word)));
)
#ifndef __BASE_FILE__
CESTER_BODY(
int main(int argc, char** argv) {
	CESTER_REGISTER_TODO_TEST(a_test_to_implement);
	CESTER_REGISTER_TODO_TEST(write_test_after_implementation);
	return CESTER_RUN_ALL_TESTS(argc, argv);
}
)
#endif


CESTER_OPTIONS(
    CESTER_VERBOSE();
    CESTER_MINIMAL();
)
