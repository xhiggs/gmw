#include "fasta.hpp"
#include <fstream>
#include <iostream>

FastaFileContent::FastaFileContent(std::string filename) : filename(filename)
{
    std::string line;
    std::ifstream in("./data/" + filename);
    std::cout << "FILENAME: " << "../data/" + filename << std::endl;
    if (in.is_open())
    {
        while (getline(in, line))
        {
            if (line.find('>') != std::string::npos)
            {
                sequences.push_back(new FastaSequence(new std::string(line), new std::string("")));
            }
            else
            {
                sequences.back()->source->append(line);
            }
        }
    }
    else
    {
        std::cerr << "Fasta file not found" << std::endl;
    }
    in.close();
}