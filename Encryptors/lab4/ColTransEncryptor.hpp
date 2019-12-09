#ifndef COLTRANSENCRYPTOR
#define COLTRANSENCRYPTOR

#include <string>
#include <vector>
#include "../BasicEncryptor.hpp"

class ColTransEncryptor : public BasicEncryptor {
public:
    ColTransEncryptor(const std::string &cipherString);
    void Encrypt(const std::string &raw, std::string &encrypted);
    void Decrypt(const std::string &encrypted, std::string &raw);

    void getCipherNumericOrder();
private:

    void showInTableForm(const std::vector<char> &arr);
    const std::string m_cipherString;
    std::vector<int> m_ColOrder;
};

#endif COLTRANSENCRYPTOR