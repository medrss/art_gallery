#pragma once
#include "list.h"

inline bool checkSpecialCharsNumbers(const std::string& str) {
    for (char c : str) {
        if ((c >= '!' && c <= '&') || (c >= '*' && c <= ',') || (c >= ':' && c <= '@') || (c >= '[' && c <= '`') || (c >= '{' && c <= '\xBF') || (c >= '{' && c <= '~') || (c == '№') || c == '/' || c == '.') {
            return true; // Найден запрещенный символ
        }
    }
    return false; // Запрещенных символов не найдено
}

inline bool checkSpecialChars(const std::string& str) {
    for (char c : str) {
        if ((c >= '!' && c <= '\'') || (c >= '*' && c <= ',') || (c >= '.' && c <= '@') || (c >= '[' && c <= '`') || (c >= '{' && c <= '\xBF') || (c >= '{' && c <= '~')) {
            return true; // Найден запрещенный символ
        }
    }
    return false; // Запрещенных символов не найдено
}
