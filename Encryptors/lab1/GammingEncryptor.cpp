#include "GammingEncryptor.hpp"
#include <iostream>

void GammingEncryptor::Encrypt(const std::string &raw, std::string &encrypted) {
    for (int i = 0; i < raw.size() - subStrLen - 1; i += subStrLen) {
        for (int offset = subStrLen - 1; offset >= 0; offset--){
            encrypted.push_back(raw.at(i + offset));
        }
    }
}

void GammingEncryptor::Decrypt(const std::string &encrypted, std::string &raw) {
    for (int i = 0; i < encrypted.size() - subStrLen - 1; i += subStrLen) {
        for (int offset = subStrLen - 1; offset >= 0; offset--){
            raw.push_back(encrypted.at(i + offset));
        }
    }
}
