#pragma once
#include <string>
#include "../BasicEncryptor.hpp"

class XorCaesarEncryptor : public BasicEncryptor {
public:
    XorCaesarEncryptor(const std::string cipherWord) : m_cipher(cipherWord) {}
    void Encrypt(const std::string &raw, std::string &encrypted);
    void Decrypt(const std::string &encrypted, std::string &raw);

private:
    const std::string m_cipher;
};
