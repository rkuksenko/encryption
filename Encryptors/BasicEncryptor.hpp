#pragma once
#include <string>

class BasicEncryptor {
public:
    virtual void Encrypt(const std::string &raw, std::string &encrypted) = 0;
    virtual void Decrypt(const std::string &encrypted, std::string &raw) = 0;
};