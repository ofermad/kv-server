#include "storage.h"

#include <iostream>

int main() {
    std::cout << "cpp-prep: week 0\n";

    Storage storage;
    storage.Set("key", "value");
    std::cout << storage.Get("key").value_or("<none>") << "\n";

    return 0;
}