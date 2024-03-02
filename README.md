# RailFenceCipher

The Rail Fence Cipher is a transposition cipher that jumbles up the order of the letters of a message in a zigzag pattern. This simple encryption technique can be applied repeatedly to enhance security.

## Compilation

Compile the encryption and decryption files separately using a C++ compiler such as g++:

```bash
g++ encrypt.cpp -o encrypt
g++ decrypt.cpp -o decrypt
```

## Usage

### Encryption

Run the encryption program to encrypt a message using the Rail Fence Cipher:

```bash
./encrypt
```

This will prompt you to enter the message and the key (depth and repetitions).

Example:

```plaintext
Enter the message: CRYPTOLOGY IS THE PRACTICE AND STUDY OF TECHNIQUES FOR SECURE COMMUNICATION IN THE PRESENCE OF THIRD PARTIES CALLED ADVERSARIES
Enter the depth and repetitions (e.g., 4 5): 4 5
```

### Decryption

Run the decryption program to decrypt an encrypted message using the Rail Fence Cipher:

```bash
./decrypt
```

This will prompt you to enter the encrypted message and the key (depth and repetitions).

Example:

```plaintext
Enter the encrypted message: TPSNIONFRMHANOIREEOIBTSEAKLAPSEHISOBPEGTBRQREPTTMHRTHTTAWEAACTFVAECAOLHANSEEKFHALOITUEEAICNLEYOLTOLEPADFKATATSJMSIINSHROCTITRIEEAKYNHYUEOTTSTATSIIRSARERUYUEDPCLETEROINEIYEHC
Enter the depth and repetitions (e.g., 3 3): 3 3
```



## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

--- 
