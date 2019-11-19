#include "Rot13Encryptor.hpp"
#include <iostream>

void Rot13Encryptor::Encrypt(const std::string &raw, std::string &encrypted) {
    for (int i = 0; i < raw.size(); i++) {
        encrypted.push_back(raw[i] + m_rot13);
    }
}

void Rot13Encryptor::Decrypt(const std::string &encrypted, std::string &raw) {
    for (int i = 0; i < encrypted.size(); i++) {
        raw.push_back(encrypted[i] - m_rot13);
    }
}
