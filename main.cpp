#include <iostream>

#include "basicFileEncryptor.hpp"


int main() {
    BasicFileEncryptor enc;
    enc.loadFromFile("./data.txt");
    enc.showInitialContent();
    enc.encrypt();
    enc.showEncryptedContent();

    return 0;
}