string Caesar_Encryption(string msg, const int& key) {
    int msgLen = msg.length();
    for (int i = 0; i < msgLen; i++) {
        if (isalpha(msg[i]) == 0) continue;
        if (isalpha(msg[i]) == 1)
            msg[i] = (msg[i] - 'A' + key) % 26 + 'A';
        else
            msg[i] = (msg[i] - 'a' + key) % 26 + 'a';
    }

    return msg;
}
string Caesar_Decryption(string ciphertext, const int& key) {
    int cLen = ciphertext.length();
    for (int i = 0; i < cLen; i++) {
        if (isalpha(ciphertext[i]) == 0) continue;
        if (isalpha(ciphertext[i]) == 1) {
            int temp = (ciphertext[i] - 'A' - key);
            if (temp < 0) temp += 26;
            ciphertext[i] = temp % 26 + 'A';
        }
        else {
            int temp = (ciphertext[i] - 'a' - key);
            if (temp < 0) temp += 26;
            ciphertext[i] = temp % 26 + 'a';
        }
    }
    return ciphertext;
}