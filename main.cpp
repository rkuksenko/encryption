#include <iostream>
#include <memory>

#include "basicFileEncryptor.hpp"
#include "Encryptors/BasicEncryptor.hpp"
#include "Encryptors/lab2/Rot13Encryptor.hpp"
#include "Encryptors/lab1/ColTransEncryptor.hpp"

int main(int argc, char** argv) {
    std::unique_ptr<BasicEncryptor> encryptor;
    
    bool isCorrect = true;
    do {
        isCorrect = true;
        std::cout   << "Hello choose encryption type: " << std::endl
                    << "1. Columnar transposition encryption (LaboratoryWork#1)" << std::endl
                    << "2. Rot13 Encryption (LaboratoryWork#2)" << std::endl
                    << "0. Exit" << std::endl;

        char choice = -1;
        std::cin >> choice;

        if (choice == '1') {
            bool isCipherWordCorrect = true;
            std::string cipherWord;
            do {
                std::cout << "Generate cipher word (up to 6 symbols): ";
                std::cin >> cipherWord;

                if (cipherWord.length() > 6) {
                    std::cout << "Please, use maximum 6-symbol word. Try again" << std::endl;
                    isCipherWordCorrect = false;
                }
            } while(!isCipherWordCorrect);

            encryptor = std::make_unique<ColTransEncryptor>(cipherWord);
        } else if (choice == '2') {
            encryptor = std::make_unique<Rot13Encryptor>();
        } else {
            std::cout << "Wrong input! Please, try again" << std::endl;
            while (std::cin.get() != '\n');
            isCorrect = false;
        }
    } while(!isCorrect);
                
   

    BasicFileEncryptor enc(std::move(encryptor));
    enc.Run();

    return 0;
}