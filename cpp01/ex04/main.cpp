#include <iostream>
#include <fstream>

int	main(int argc, char **argv)
{
	std::string src;
	std::string dst;
	std::string line;
	std::string outFile;

	if (argc != 4)
	{
		std::cout << "Usage: ./sed <file> <strToReplace> <strReplaceBy>" << std::endl;
		return (1);
	}
	src = argv[2];
	dst = argv[3];
	std::ifstream myinFile(argv[1]);
	if (!myinFile.is_open())
	{
		std::cout << "Error: could not open file" << std::endl;
		return (1);
	}
	outFile = std::string(argv[1]) + ".replace";
	std::ofstream myOutFile(outFile.c_str());
	if (!myOutFile.is_open())
	{
		std::cout << "Error: could not create file" << std::endl;
		myinFile.close();
		return (1);
	}
	while (std::getline(myinFile, line))
	{
		size_t pos = 0;
		while ((pos = line.find(src, pos)) != std::string::npos)
		{
			line.erase(pos, src.length());
			line.insert(pos, dst);
			pos += dst.length();
		}
		myOutFile << line << std::endl;
	}
	myinFile.close();
	myOutFile.close();
	return (0);
}