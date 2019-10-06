#include "avm.hpp"

int main(int argc, char **argv)
{
    CmdStack cmdStack;
    bool noError = true;
    bool fromFile = false;
    std::ifstream fileInput;
    std::istream *cmdInput;
    int line = 1;

    if (argc > 2)
    {
		std::cerr << "Usage : either '.avm' or './avm <filename>' " << std::endl;
		return (EXIT_FAILURE);
    }
    if (argc = 2)
    {
        fileInput.open(argv[1]);
        if(fileInput.fail() || !fileInput.good())
        {   
            std::cerr << "Error: " << strerror(errno) << std::endl;
            return(EXIT_FAILURE);
        }
         fromFile = true;
         cmdInput =  &fileInput;
    }
    else
	{
		cmdInput = &std::cin;
	}
    while (cmdInput->eof())
    {
        std::string input;
        std::getline(*cmdInput,input);
        if (!fromFile && std::regex_match(input, std::regex(";;.*")))
			break;
        try
		{
		    cmdStack.runLine(input);
		}
		catch (std::exception &e)
		{
		    noError = false;
			g_Global::errorOutput << "Error on line : " << line <<  std::endl;
		}
		line++;
    }
    if(!cmdStack)
    {
        noError=false;
        g_Global::errorOutput <<"Fatal Error. make sure to compile -Wfatal-error flags\n";
    }
    if (noError)
        std::cout << g_Global::output.str();
    else
        std::cout <<g_Global::errorOutput.str();
}