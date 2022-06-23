#include <fstream>
#include <iostream>

int fNreplace(char **argv, std::string str)
{
    std::ofstream outFile;
    int pos;
    outFile.open((std::string(argv[1]) + ".replace").c_str());

    if (outFile.fail())
        return (1);

    for (int i = 0; i < (int)str.size(); i++)
    {
        pos = str.find(argv[2], i);
        if (pos != -1 && pos == i)
        {
            outFile << argv[3];
            i += std::string(argv[2]).size() - 1;
        }
        else
        {
            outFile << str[i];
        }
    }
    outFile.close();
    return (0);
}

int main(int argc, char **argv)
{
    char c;
    std::ifstream infile;
    std::string str;

    if (argc != 4)
    {
        std::cout << "usage: replace <file> old_word new_word" << std::endl;
        return (1);
    }
    infile.open(argv[1]);
    if (infile.fail())
    {
        std::cout << "Error: " << argv[1] << ":"
                  << " no such file or directory" << std::endl;
        return (1);
    }
    while (!infile.eof() && infile >> std::noskipws >> c)
        str += c;
    infile.close();
    return (fNreplace(argv, str));
}
