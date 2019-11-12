#include "basicFileEncryptor.hpp"
#include <iostream>
#include <fstream>

void BasicFileEncryptor::encrypt() {
    m_rEncryptor.Encrypt(m_initBuffer, m_encryptedBuffer);
}

void BasicFileEncryptor::showInitialContent() {
    std::cout << "Initial file content:\n" << m_initBuffer << std::endl;
}

void BasicFileEncryptor::showEncryptedContent() {
    std::cout << "Encrypted file content:\n" << m_encryptedBuffer << std::endl;
}

void BasicFileEncryptor::loadFromFile(const std::string &filename) {
    try {
        std::ifstream file(filename.c_str(), std::ios::in);

        if (!file) {
            throw std::runtime_error("Failed to load file: \"" + filename + "\"");
        }

        std::string tmp;
        while (getline(file,tmp)) {
            m_initBuffer.append(tmp);
        }

        file.close();
    }
    catch (std::runtime_error &e) {
        std::cerr << "[BasicFileEncryptor::loadFromFile] " << e.what() << std::endl;
    }
}

void BasicFileEncryptor::saveToFile(const std::string &filename) {
    try {
        std::ofstream file(filename.c_str(), std::ios::ate);

        if (!file) {
            throw std::runtime_error("Failed to open file: \"" + filename + "\"");
        }

    }
    catch (std::runtime_error &e) {
        std::cerr << "[BasicFileEncryptor::saveToFile] " << e.what() << std::endl;
    }
}