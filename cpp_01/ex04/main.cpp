#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: ./program filename s1 s2" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty())
    {
        std::cerr << "Error: s1 cannot be empty" << std::endl;
        return 1;
    }

    std::ifstream inFile(filename.c_str());
    if (!inFile)
    {
        std::cerr << "Error: cannot open input file" << std::endl;
        return 1;
    }

    std::ofstream outFile((filename + ".replace").c_str());
    if (!outFile)
    {
        std::cerr << "Error: cannot open output file" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inFile, line))
    {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
        outFile << line;
        if (!inFile.eof())
            outFile << '\n';
    }

    return 0;
}
