#include "ColTransEncryptor.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

ColTransEncryptor::ColTransEncryptor(const std::string &cipherString) : m_cipherString(cipherString) {

}

void ColTransEncryptor::Encrypt(const std::string &raw, std::string &encrypted) {
    std::vector<char> arr;
    m_ColOrder.clear();
    for (int i = 0; i < raw.length(); i++) {
        arr.push_back(raw[i]);
    }

    int numToAdd = raw.length() % m_cipherString.length();

    if (numToAdd) {
        for (int i = 0; i < m_cipherString.length() - numToAdd; i++) {
            arr.push_back('$');
        }
    }

    showInTableForm(arr);
    getCipherNumericOrder();

    std::cout << m_cipherString.length() << std::endl;
    for (auto i : m_ColOrder) {
        for (int j = 0; j < arr.size(); j += m_cipherString.length()) {
            encrypted.push_back(arr.at(i + j));
        }
    }

    std::cout << std::endl;
}


void ColTransEncryptor::Decrypt(const std::string &encrypted, std::string &raw) {
    m_ColOrder.clear();
    getCipherNumericOrder();

    std::vector<char> arr(encrypted.size());

    std::vector<std::vector<int>> vec;
    std::vector<int> tmp;
    for (int i = 0; i < encrypted.length(); i++) {

        tmp.push_back(encrypted[i]);

         if (!((i + 1) % (encrypted.length() / m_cipherString.length()))) {
            vec.push_back(tmp);
            tmp.clear();
        }
    }
    vec.push_back(tmp);

    std::vector<std::vector<int>> r(m_ColOrder.size());
    
    int j = 0;
    for (auto i : m_ColOrder) {
        r.at(i) = vec[j];
        j++;
    }

    for (int i = 0; i < r.at(0).size(); i++) {
        for (j = 0; j < r.size(); j++) {
            raw.push_back(r.at(j).at(i));
        }
    }

    raw.erase(std::remove_if(raw.begin(), raw.end(), [](int i) { return i == '$'; }), raw.end());
}

void ColTransEncryptor::getCipherNumericOrder() {
    std::vector<int> numOrder;
    for (int i = 0; i < m_cipherString.size(); i++) {
        numOrder.push_back(m_cipherString[i]);
    }

    for (int i = 0; i < m_cipherString.size(); i++) {
        auto m = std::max_element(numOrder.begin(), numOrder.end());
        *m = m_cipherString.size() - i;
    }

    for (int i = 0; i < numOrder.size(); i++) {
        int &n = *(std::min_element(numOrder.begin(), numOrder.end()));
        int pos = -1;
        for (int j = 0; j < numOrder.size(); j++) {
            if (numOrder[j] == n) {
                pos = j;
            }
        }
        m_ColOrder.push_back(pos);
        n = 255;
    }
}

void ColTransEncryptor::showInTableForm(const std::vector<char> &arr) {
    std::cout << "It table form:" << std::endl;

    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
        if (!((i + 1) % m_cipherString.length())) {
            std::cout << std::endl;
        }
    }

    std::cout << std::endl;
}