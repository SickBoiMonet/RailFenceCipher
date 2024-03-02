#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
std::string encryptRailFence(std::string text, std::pair<int, int> key)
{
    // Convert message to lower case and remove spaces
    std::transform(text.begin(), text.end(), text.begin(), ::tolower);
    text.erase(std::remove(text.begin(), text.end(), ' '), text.end());

    std::string encryptedMessage = text;
    for (int i = 0; i < key.second; i++) {
        std::vector<std::string> rail(key.first);
        bool dir_down = false;
        int row = 0;

        for (char c : encryptedMessage) {
            rail[row].push_back(c);
            if (row == 0 || row == key.first - 1)
                dir_down = !dir_down;
            dir_down ? row++ : row--;
        }

        encryptedMessage.clear();
        for (const std::string& r : rail)
            encryptedMessage.append(r);
    }

    return encryptedMessage;
}

int main()
{
    std::string message = "CRYPTOLOGY IS THE PRACTICE AND STUDY OF TECHNIQUES FOR SECURE COMMUNICATION IN THE PRESENCE OF THIRD PARTIES CALLED ADVERSARIES";
    std::pair<int, int> key = {4, 5};
    std::string encryptedMessage = encryptRailFence(message, key);
    std::cout << "Encrypted Message: " << encryptedMessage <<std::endl;
}
