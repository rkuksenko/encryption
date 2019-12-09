all: main

main:	main.cpp 	basicFileEncryptor.o ColTransEncryptor.o Rot13Encryptor.o RSAEncryption.o\
					GammingEncryptor.o XorCaesarEncryptor.o

	g++ -std=c++14 -o run main.cpp 	basicFileEncryptor.o ColTransEncryptor.o Rot13Encryptor.o \
									RSAEncryption.o GammingEncryptor.o XorCaesarEncryptor.o


XorCaesarEncryptor.o:	Encryptors/lab5/XorCaesarEncryptor.hpp Encryptors/lab5/XorCaesarEncryptor.cpp
	g++ -c -g Encryptors/lab5/XorCaesarEncryptor.cpp

ColTransEncryptor.o: 	Encryptors/lab4/ColTransEncryptor.hpp Encryptors/lab4/ColTransEncryptor.cpp
	g++ -c -g Encryptors/lab4/ColTransEncryptor.cpp

RSAEncryption.o:		Encryptors/lab3/RSAEncryption.hpp Encryptors/lab3/RSAEncryption.cpp
	g++ -c -g Encryptors/lab3/RSAEncryption.cpp

Rot13Encryptor.o: 		Encryptors/lab2/Rot13Encryptor.hpp Encryptors/lab2/Rot13Encryptor.cpp
	g++ -c -g Encryptors/lab2/Rot13Encryptor.cpp

GammingEncryptor.o:		Encryptors/lab1/GammingEncryptor.hpp Encryptors/lab1/GammingEncryptor.cpp
	g++ -c -g Encryptors/lab1/GammingEncryptor.cpp


basicFileEncryptor.o:	basicFileEncryptor.cpp basicFileEncryptor.hpp
	g++ -c basicFileEncryptor.cpp

clean:
	rm -f *.o run
