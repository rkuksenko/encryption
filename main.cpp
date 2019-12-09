#include <iostream>
#include <memory>

#include "basicFileEncryptor.hpp"
#include "Encryptors/BasicEncryptor.hpp"

#include "Encryptors/lab5/XorCaesarEncryptor.hpp"
#include "Encryptors/lab4/ColTransEncryptor.hpp"
#include "Encryptors/lab3/RSAEncryption.hpp"
#include "Encryptors/lab2/Rot13Encryptor.hpp"
#include "Encryptors/lab1/GammingEncryptor.hpp"

int main(int argc, char** argv) {
    std::unique_ptr<BasicEncryptor> encryptor;
    
    bool isCorrect = true;
    do {
        isCorrect = true;
        std::cout   << "Hello choose encryption type: " << std::endl
                    << "1. Gamming Encryptor (LaboratoryWork#1)" << std::endl
                    << "2. Rot13 Encryption (LaboratoryWork#2)" << std::endl
                    << "3. RSAEncryption Encryption (LaboratoryWork#3)" << std::endl
                    << "4. Columnar transposition encryption (LaboratoryWork#4)" << std::endl
                    << "5. Xor \"Caesar\" Encryptor (LaboratoryWork#5)" << std::endl
                    << "0. Exit" << std::endl;
        char choice = -1;
        std::cin >> choice;

        if (choice == '1') {
            encryptor = std::make_unique<GammingEncryptor>();
        } else if (choice == '2') {
            encryptor = std::make_unique<Rot13Encryptor>();
        } else if (choice == '3') {
	        RSAEncryption rsaencryption;
	        Key key = rsaencryption.produce_keys();
	        
            std::cout << "The keys obtained by encryption are as follows:"<< std::endl;
	        std::cout << "Public key:" << key.pkey << std::endl;
	        std::cout << "Encryption key:" << key.ekey << std::endl;
	        std::cout << "Decryption key:" << key.dkey << std::endl;
	        long msg;
	        std::cout << "Please enter the information to be encrypted (number, not too large):" << std::endl;
	        std::cin >> msg;
	        long msg_des = rsaencryption.endecrypt(msg, key.ekey, key.pkey);
	        std::cout << "The encrypted information is:" << msg_des << std::endl;
	        msg_des = rsaencryption.endecrypt(msg_des, key.dkey, key.pkey);
	        std::cout << "After decryption, the information is:" << msg_des << std::endl;
            std::cout << "Finishing..." << std::endl;
            exit(0);
        } else if (choice == '4') {
            bool isCipherWordCorrect = true;
            std::string cipherWord;
            do {
                isCipherWordCorrect = true;
                std::cout << "Generate cipher word (up to 6 symbols): ";
                std::cin >> cipherWord;

                if (cipherWord.length() > 6) {
                    std::cout << "Please, use maximum 6-symbol word. Try again" << std::endl;
                    isCipherWordCorrect = false;
                }
            } while(!isCipherWordCorrect);

            encryptor = std::make_unique<ColTransEncryptor>(cipherWord);
        } else if (choice == '5') {
            bool isCipherWordCorrect = true;
            std::string cipherWord;
            do {
                isCipherWordCorrect = true;
                std::cout << "Generate cipher word (up to 6 symbols): ";
                std::cin >> cipherWord;

                if (cipherWord.length() > 6) {
                    std::cout << "Please, use maximum 6-symbol word. Try again" << std::endl;
                    isCipherWordCorrect = false;
                }
            } while(!isCipherWordCorrect);

            encryptor = std::make_unique<XorCaesarEncryptor>(cipherWord);
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