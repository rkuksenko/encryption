#include <string>

class RomanEncryptor {
public:
    void Encrypt(const std::string &raw, std::string &encrypted);
    void Decrypt(const std::string &encrypted, std::string &raw);
};