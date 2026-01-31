# XOR Encryption in C++
An implementation of simple XOR encryption in C++.

Learned how to do it from [this video](https://www.youtube.com/watch?v=4KdvcQKNfbQ). I know it's incredibly simple, but after hearing about XOR encryption in the past but never taking the time to learn it, I was so astounded by how simple it is that I had to implement it. It has also given me an excuse to try out Neovim on real project, which is what was used to create the files in this repo.

## Usage
Launch the compiled executable like so:

```
xor_encryptor.exe <encrypt/decrypt> <file>
```

Encrypt will create an `encrypted.bin` and decrypt will create a `descrypted.bin`.

Due to the nature of XOR encryption, these actually do the exact same thing otherwise, but the "intended" use is to first encrypt any file and then descrypt the generated `encrypt.bin`.
