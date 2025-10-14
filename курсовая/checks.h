#pragma once
#include "list.h"

inline bool checkSpecialCharsNumbers(const std::string& str) {
    for (char c : str) {
        if ((c >= '!' && c <= '&') || (c >= '*' && c <= ',') || (c >= ':' && c <= '@') || (c >= '[' && c <= '`') || (c >= '{' && c <= '\xBF') || (c >= '{' && c <= '~') || (c == '�') || c == '/' || c == '.') {
            return true; // ������ ����������� ������
        }
    }
    return false; // ����������� �������� �� �������
}

inline bool checkSpecialChars(const std::string& str) {
    for (char c : str) {
        if ((c >= '!' && c <= '\'') || (c >= '*' && c <= ',') || (c >= '.' && c <= '@') || (c >= '[' && c <= '`') || (c >= '{' && c <= '\xBF') || (c >= '{' && c <= '~')) {
            return true; // ������ ����������� ������
        }
    }
    return false; // ����������� �������� �� �������
}
