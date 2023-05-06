#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

std::string replaceContent(std::string file_content, std::string s1, std::string s2)
{
    std::string result;
    size_t position = 0;
    size_t last_pos = 0;
    position = file_content.find(s1, last_pos);
    while (position != std::string::npos)
    {
        result += file_content.substr(last_pos, position - last_pos) + s2;
        last_pos = position + s1.length();
        position = file_content.find(s1, last_pos);
    }
    result += file_content.substr(last_pos, file_content.length());
    return result;
}
int main(int argc, char const *argv[])
{
    if (argc != 4)
    {
        std::cerr << "Usage: ./replace <file> <s1> <s2>\n";
        return 0;
    }

    std::string filename(argv[1]);
    std::string s1(argv[2]);
    std::string s2(argv[3]);

    if (s1.empty()) {
        std::cerr << "Error : s1 cannot be empty\n";
        return 1;
    }

    std::ifstream input_file(filename.c_str());
    if (!input_file.is_open()) {
        std::cerr << "Error : Cannot open file '" << filename << "'" << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << input_file.rdbuf();
    std::string file_content = buffer.str();

    std::string replace_file_content = replaceContent(file_content, s1, s2);
    std::cout << replace_file_content << std::endl;

    std::string output_file_name = filename + ".replace";
    std::ofstream output_file(output_file_name.c_str());
    if (!output_file.is_open()) {
        std::cerr << "Error : Cannot create the file '" << output_file_name << "'\n";
        return 1;
    }

    output_file << replace_file_content;
    output_file.close();

    std::cout << "Le fichier '" << output_file_name << "' a été créé avec succès.\n";
    return 0;
}
