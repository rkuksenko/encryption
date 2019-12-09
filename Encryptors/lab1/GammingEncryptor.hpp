#pragma once
#include <string>
#include "../BasicEncryptor.hpp"

class GammingEncryptor : public BasicEncryptor {
public:
    GammingEncryptor() : subStrLen(2) {}

    void Encrypt(const std::string &raw, std::string &encrypted);
    void Decrypt(const std::string &encrypted, std::string &raw);

private:
    const size_t subStrLen;
};
