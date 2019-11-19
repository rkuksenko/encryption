#pragma once
#include <string>
#include <memory>

class BasicEncryptor;

class BasicFileEncryptor {
public:
    BasicFileEncryptor(std::unique_ptr<BasicEncryptor> encryptor);
    void Run();

private:
    void loadFromFile(const std::string &filename);
    void saveResultToFile(const std::string &filename);
    void saveToFilePrompt();
    bool updateIsContinue();

    std::string m_initBuffer;
    std::string m_resultBuffer;
    bool m_isContinue;

    std::unique_ptr<BasicEncryptor> m_rEncryptor;
};