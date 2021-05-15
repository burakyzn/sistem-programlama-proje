#include "cester.h"
#include "../jsonparser.h"
#include <ctype.h>
#ifndef __BASE_FILE__
#define CESTER_NO_MAIN
#endif

CESTER_MOCK_FUNCTION(parse_json_file(int p_parse_option), JRB, 
    JRB tree;
    p_parse_option = 1;
    tree = parse_json_file(1); 
    return tree;
)
/*
@description :parse_json_file fonksiyonunun geriye NULL dondurmemesi basari olucutumuzdur.
@author: MAFTUN HASHIMLI - G18120554
*/
CESTER_TEST(json_parse_fonksiyonu_null_deger_donduremez, test_instance,
    JRB tree;
    JRB tmp;
    char* ilk_dugum;
    cester_assert_not_equal(parse_json_file(0), NULL);

)
CESTER_TEST(json_parse_fonksiyonun_donus_tipi_dogru_mu, test_instance,
    JRB tree;
    JRB tmp;
  
    cester_assert_equal(parse_json_file(0), tmp);

)
#ifndef __BASE_FILE__
CESTER_BODY(
int main(int argc, char** argv) {
    CESTER_REGISTER_TEST(json_parse_fonksiyonu_null_deger_donduremez);
    CESTER_REGISTER_TEST(json_parse_fonksiyonun_donus_tipi_dogru_mu);
	return CESTER_RUN_ALL_TESTS(argc, argv);
}
)
#endif

CESTER_OPTIONS(
    CESTER_VERBOSE();
    CESTER_MINIMAL();
)
