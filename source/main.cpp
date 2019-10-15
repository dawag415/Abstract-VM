/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwagner <iwagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 20:28:23 by iwagner           #+#    #+#             */
/*   Updated: 2019/10/14 16:38:02 by iwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avm.hpp"
Factory	g_Global::factory;
std::stringstream	g_Global::output;
std::stringstream	g_Global::errorOutput;

int main(int argc, char **argv)
{
    CmdStack cmdStack;
    bool noError = true;
    bool fromFile = false;
    std::ifstream fileInput;
    std::istream *cmdInput;
    int line = 1;
    std::string input;
    std::ofstream fileOutput;


    if (argc > 3)
    {
		std::cerr << "Usage : either '.avm' or './avm <input_filename>' or './avm <input_filename> <output_filename>" << std::endl;
		return (EXIT_FAILURE);
    }
    if (argc == 2 || argc == 3)
    {
        fileInput.open(argv[1]);
        if(fileInput.fail() || !fileInput.good())
        {   
            std::cerr << "ERROR READING FROM FILE: " << strerror(errno) << std::endl;
            return(EXIT_FAILURE);
        }
         fromFile = true;
         cmdInput =  &fileInput;
    }
    else
		cmdInput = &std::cin;
    while (!cmdInput->eof())
    {
        std::getline(*cmdInput, input);
        if (!fromFile && std::regex_match(input, std::regex(";;.*")))
			break;
        try
        {
		    cmdStack.runLexer(input);
        }
        catch (std::exception &e)
		{
		    noError = false;
			g_Global::errorOutput << "ERROR - Line " << line << ": " << e.what() <<
            "Please correct instruction and try again.\nInstruction entered line "<<
            line << ": \"" << input << "\" \n\n";
		}
		line++;
    }
    if(!cmdStack.checkExit())
    {
        noError=false;
        g_Global::errorOutput <<"ERROR: exit intruction is mandatory.\n";
    }
    if (argc == 3 && fromFile == true)
    {   
        fileOutput.open(argv[2]);
        if(fileOutput.fail() || !fileOutput.good())
        {   
            std::cerr << "ERROR WRITING TO FILE: " << strerror(errno) << std::endl;
            return(EXIT_FAILURE);
        }
        (noError ? fileOutput << g_Global::output.str() : fileOutput << g_Global::errorOutput.str());
        fileOutput.close();
        if (!fileOutput)
        {   
            std::cerr << "ERROR WRITING TO FILE: " << strerror(errno) << std::endl;
            return(EXIT_FAILURE);
        }
        if (noError)
            return (EXIT_SUCCESS);
        else
            return (EXIT_FAILURE);
    }
    else
    {
        if (noError)
        {
            std::cout << g_Global::output.str();
            return (EXIT_SUCCESS);
        }
        else
            std::cout << g_Global::errorOutput.str();
            return(EXIT_FAILURE);
    }
}
