#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>

const unsigned char key = 69;

void encrypt(std::vector<unsigned char>& data) {
	for (auto& c : data) {
		c ^= key;
	}
}

int main(int argc, char* argv[]) {
	if (argc < 3) {
		std::cerr << "Insufficient arguments provided.\nUse the format:\nmain <encrypt/decrypt> <file>\n";
		return 1;
	}

	std::string type = argv[1];
	std::filesystem::path file_path{argv[2]};
	std::ifstream file{file_path, std::ios::binary};

	if (!file.is_open()) {
		std::cerr << "Failed to load file from 2nd argument. Ensure it is valid and accessible.\n";
		return 1;
	}

	auto file_length = std::filesystem::file_size(file_path);

	std::vector<unsigned char> vec(file_length);
	file.read(reinterpret_cast<char*>(vec.data()), file_length);
	file.close();

	if (type == "encrypt") {
		encrypt(vec);
		std::ofstream output{"encrypted.bin", std::ios::binary};
		output.write(reinterpret_cast<char*>(vec.data()), file_length);
	} else if (type == "decrypt") {
		encrypt(vec);
		std::ofstream output{"decrypted.bin", std::ios::binary};
		output.write(reinterpret_cast<char*>(vec.data()), file_length);
	} else {
		std::cerr << "Invalid 1st argument. Must be either \"encrypt\" or \"decrypt\".\n";
	}
}
