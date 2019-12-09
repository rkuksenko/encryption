#include "XorCaesarEncryptor.hpp"
#include <iostream>

void XorCaesarEncryptor::Encrypt(const std::string &raw, std::string &encrypted) {
    int pos = 0;

    for (auto c : raw) {
        if (pos == m_cipher.length()) {
            pos = 0;
        }
        encrypted.push_back((c ^ m_cipher.at(pos)) + 31);
        pos++;
    }
}

void XorCaesarEncryptor::Decrypt(const std::string &encrypted, std::string &raw) {
    int pos = 0;

    for (auto c : encrypted) {
        if (pos == m_cipher.length()) {
            pos = 0;
        }

        raw.push_back(((c - 31) ^ m_cipher.at(pos)));
        pos++;
    }
}