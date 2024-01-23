/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:18:52 by wayden            #+#    #+#             */
/*   Updated: 2024/01/23 16:51:06 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Includes.hpp"

void format_output(std::string& content, std::string s1, std::string s2)
{
	size_t pos;
	
	pos = content.find(s1);
	while(pos != std::string::npos)
	{
		content.erase(pos, s1.length());
		content.insert(pos, s2);		
		pos = content.find(s1, pos + s2.length());
	}
}



int main(int argc, char **argv)
{
	std::string s1;
	std::string s2;
	std::string infilename;
	std::string outfilename;
	std::stringstream buffer;
	std::string content;
	
	if( argc < 4)
		return(std::cout << "Usage [filename] [toreplace] [replacewith]" << std::endl, 1);
	s1 = argv[2];
	s2 = argv[3];
	infilename = argv[1];
	outfilename = infilename +".replace";
	std::ifstream infile(infilename);
	if (!infile)
		return(std::cout << "Impossible d'ouvrir le fichier d'entrée" << argv[1] << std::endl, 1);
	buffer << infile.rdbuf();
	content = buffer.str();
	std::ofstream outfile(outfilename);
	if (!outfile)
		return(std::cout << "Impossible de créer ou le lire le fichier de sortie" << argv[1] << std::endl, 1);
	format_output(content, s1, s2);
	outfile << content; 
}