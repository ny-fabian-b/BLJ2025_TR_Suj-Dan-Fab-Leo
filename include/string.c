//
// Created by fabia on 19.09.2025.
//

#include "string.h"


size_t strFind(const char* str, const char target) {
    for (size_t i = 0; i < strlen(str); i++) {
        if (str[i] == target) {
            return i;
        }
    }
    return SIZE_MAX;
}
