#include "basicFileEncryptor.hpp"
#include "Encryptors/BasicEncryptor.hpp"
#include <iostream>
#include <fstream>

BasicFileEncryptor::BasicFileEncryptor(std::unique_ptr<BasicEncryptor> encryptor) : m_isContinue(false) {
    m_rEncryptor = std::move(encryptor);
}

void BasicFileEncryptor::Run() {
    do {
        std::cout << "Hello, choose input filename: " << std::endl;
        std::string filename;
        std::cin >> filename;
        loadFromFile(filename);
    
        std::cout   << "Available options: " << std::endl
                    << "1. Encrypt " << std::endl
                    << "2. Decrypt " << std::endl
                    << "0. Exit " << std::endl;
        char choice = -1;
        bool correctInput = true;
    
        do {
            correctInput = true;
            std::cin >> choice;
    
            if (choice == '1') {
                std::cout << "Going to encrypt data. " << std::endl;
                m_rEncryptor->Encrypt(m_initBuffer, m_resultBuffer);
            } else if (choice == '2') {
                std::cout << "Going to decrypt data. " << std::endl;
                m_rEncryptor->Decrypt(m_initBuffer, m_resultBuffer);
            } else if (choice == '0') {
                std::cout << "Finishing.. " << std::endl;
                exit(0);
            } else {
                std::cout << "Wrong input, try one more times: ";
                correctInput = false;
                while(std::cin.get() != '\n');
            }
        } while (!correctInput);
    
        std::cout << "Result: " << m_resultBuffer << std::endl;
    
        saveToFilePrompt();
        updateIsContinue();
    } while (m_isContinue);
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

        std::cout << "File content: " << m_initBuffer << std::endl;
    }
    catch (std::runtime_error &e) {
        std::cerr << "[BasicFileEncryptor::loadFromFile] " << e.what() << std::endl;
        exit(1);
    }
}

void BasicFileEncryptor::saveResultToFile(const std::string &filename) {
    try {
        std::ofstream file(filename.c_str(), std::ios::ate);

        if (!file) {
            throw std::runtime_error("Failed to open file: \"" + filename + "\"");
        }

        file << m_resultBuffer;

        std::cout << "Saved to file: " << filename << std::endl;
    }
    catch (std::runtime_error &e) {
        std::cerr << "[BasicFileEncryptor::s'\n'aveToFile] " << e.what() << std::endl;
        exit(1);
    }
}


void BasicFileEncryptor::saveToFilePrompt() {
    std::cout << "Save result to file (y/n)?:";
    char choice = -1;
    bool correctInput = true;
    do {
        correctInput = true;
        std::cin >> choice;

        if (choice == 'n') {
            std::cout << "Exiting.." << std::endl;
        } else if (choice == 'y') {
            std::cout << "Input result filename: ";
            std::string filename;
            std::cin >> filename;

            saveResultToFile(filename);
        } else {
            std::cout << "Incorrect input try again.." << std::endl;
            correctInput = false;
            while(std::cin.get() != '\n');
        }
    } while (!correctInput);
}

bool BasicFileEncryptor::updateIsContinue() {
    std::cout << "Continue (y/n)?: " << std::endl;

    char choice = -1;
    bool correctInput = true;
    do {
        correctInput = true;
        std::cin >> choice;

        if (choice == 'y') {
            m_isContinue = true;
            m_initBuffer.clear();
            m_resultBuffer.clear();
        } else if (choice != 'n') {
            std::cout << "Incorrect input try again.." << std::endl;
            correctInput = false;
            m_isContinue = false;
            while(std::cin.get() != '\n');
        }
    } while (!correctInput);
}