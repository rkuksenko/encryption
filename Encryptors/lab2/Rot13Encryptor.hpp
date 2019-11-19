#pragma once
#include <string>
#include "../BasicEncryptor.hpp"

class Rot13Encryptor : public BasicEncryptor {
public:
    Rot13Encryptor() : m_rot13(13) {}
    void Encrypt(const std::string &raw, std::string &encrypted);
    void Decrypt(const std::string &encrypted, std::string &raw);

private:
    const int m_rot13;
};
