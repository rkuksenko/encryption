#include "RomanEncryptor.hpp"

void RomanEncryptor::Encrypt(const std::string &raw, std::string &encrypted) {
    for (char it : raw) {
        encrypted.push_back(it + 1);
    }
}

void RomanEncryptor::Decrypt(const std::string &encrypted, std::string &raw) {
    for (char it : raw) {
        raw.push_back(it - 1);
    }
}