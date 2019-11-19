all: main

main:	main.cpp basicFileEncryptor.o ColTransEncryptor.o Rot13Encryptor.o RSAEncryption.o
	g++ -std=c++14 -o run main.cpp basicFileEncryptor.o ColTransEncryptor.o Rot13Encryptor.o RSAEncryption.o

basicFileEncryptor.o:	basicFileEncryptor.cpp basicFileEncryptor.hpp
	g++ -c basicFileEncryptor.cpp

ColTransEncryptor.o: Encryptors/lab1/ColTransEncryptor.hpp Encryptors/lab1/ColTransEncryptor.cpp
	g++ -c -g Encryptors/lab1/ColTransEncryptor.cpp

Rot13Encryptor.o: Encryptors/lab2/Rot13Encryptor.hpp Encryptors/lab2/Rot13Encryptor.cpp
	g++ -c -g Encryptors/lab2/Rot13Encryptor.cpp

RSAEncryption.o:	Encryptors/lab3/RSAEncryption.hpp Encryptors/lab3/RSAEncryption.cpp
	g++ -c -g Encryptors/lab3/RSAEncryption.cpp

clean:
	rm -f *.o run
