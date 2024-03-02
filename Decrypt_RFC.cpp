#include <iostream>
#include <string>
#include <vector>

std::string decryptRailFence(std::string encryptedMessage, std::pair<int, int> key)
{
    // Initialize a matrix to hold the decrypted message
    std::vector<std::vector<char>> rail(key.first, std::vector<char>(encryptedMessage.length(), ' '));

    // Variables to keep track of position in the zigzag pattern
    int row = 0, col = 0;
    bool dir_down = false;

    std::transform(encryptedMessage.begin(), encryptedMessage.end(), encryptedMessage.begin(), ::tolower);
    encryptedMessage.erase(std::remove(encryptedMessage.begin(), encryptedMessage.end(), ' '), encryptedMessage.end());
    // Fill the matrix with '*' markers in the zigzag pattern
    for (int i = 0; i < encryptedMessage.length(); ++i) {
        if (row == 0 || row == key.first - 1)
            dir_down = !dir_down;
        rail[row][col++] = '*';
        dir_down ? ++row : --row;
    }

    // Replace '*' markers with characters from the encrypted message
    int index = 0;
    for (int i = 0; i < key.first; ++i) {
        for (int j = 0; j < encryptedMessage.length(); ++j) {
            if (rail[i][j] == '*' && index < encryptedMessage.length()) {
                rail[i][j] = encryptedMessage[index++];
            }
        }
    }

    // Read characters from the matrix in the zigzag pattern to obtain the decrypted message
    std::string decryptedMessage;
    row = 0, col = 0;
    dir_down = false;
    for (int i = 0; i < encryptedMessage.length(); ++i) {
        if (row == 0 || row == key.first - 1)
            dir_down = !dir_down;
        decryptedMessage.push_back(rail[row][col++]);
        dir_down ? ++row : --row;
    }

    return decryptedMessage;
    
}

int main()
{
    std::string encryptedMessage = "TPSNIONFRMHANOIREEOIBTSEAKLAPSEHISOBPEGTBRQREPTTMHRTHTTAWEAACTFVAECAOLHANSEEKFHALOITUEEAICNLEYOLTOLEPADFKATATSJMSIINSHROCTITRIEEAKYNHYUEOTTSTATSIIRSARERUYUEDPCLETEROINEIYEHC";
    std::pair<int, int> key = {3, 3};
    std::string decryptedMessage = decryptRailFence(encryptedMessage, key);
    for (int k = 1; k < key.second; k++) 
       {
        decryptRailFence(decryptedMessage, key);
        decryptedMessage = decryptRailFence(decryptedMessage, key);
        
       }

    std::cout << "Decrypted Message: " << decryptedMessage << std::endl;

    return 0;
}
