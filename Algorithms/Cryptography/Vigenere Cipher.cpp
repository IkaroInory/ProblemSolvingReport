string Vigenere_Encryption(string msg, const string& key) {
    int msgLen = msg.length();
    int keyLen = key.length();
    int pkey = 0;
    for (int i = 0; i < msgLen; i++) {
        int key_i = isalpha(key[pkey % keyLen]) == 1 ? key[pkey % keyLen] - 'A' : key[pkey % keyLen] - 'a';
        if (isalpha(msg[i]) == 0) continue;
        if (isalpha(msg[i]) == 1)
            msg[i] = (msg[i] - 'A' + key_i) % 26 + 'A';
        else
            msg[i] = (msg[i] - 'a' + key_i) % 26 + 'a';
        pkey++;
    }

    return msg;
}
string Vigenere_Decryption(string ciphertext, const string& key) {
    int msgLen = ciphertext.length();
    int keyLen = key.length();
    int pkey = 0;
    for (int i = 0; i < msgLen; i++) {
        int key_i = isalpha(key[pkey % keyLen]) == 1 ? key[pkey % keyLen] - 'A' : key[pkey % keyLen] - 'a';
        if (isalpha(ciphertext[i]) == 0) continue;
        if (isalpha(ciphertext[i]) == 1) {
            int temp = (ciphertext[i] - 'A' - key_i);
            if (temp < 0) temp += 26;
            ciphertext[i] = temp % 26 + 'A';
        }
        else {
            int temp = (ciphertext[i] - 'a' - key_i);
            if (temp < 0) temp += 26;
            ciphertext[i] = temp % 26 + 'a';
        }
        pkey++;
    }

    return ciphertext;
}