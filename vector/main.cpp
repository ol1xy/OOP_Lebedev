#include "test.h"

int main() {
    setlocale(LC_ALL, "Russian");
    test_push_back();
    test_erase();
    test_insert();
    test_get();

    return 0;
}
