#include <string>
#include "RomanEncryptor.hpp"

class BasicFileEncryptor {
public:
    void encrypt();
    void showInitialContent();
    void showEncryptedContent();
    void loadFromFile(const std::string &filename);
    void saveToFile(const std::string &filename);

private:
    std::string m_initBuffer;
    std::string m_encryptedBuffer;

    RomanEncryptor m_rEncryptor;
};