#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "ParSNPPlugin.h"

void ParSNPPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
   }
}

void ParSNPPlugin::run() {
   
}

void ParSNPPlugin::output(std::string file) {
	std::string command;
   command = "parsnp ";
   command += " -r "+std::string(PluginManager::prefix())+"/"+parameters["reference"];
   command += " -d "+std::string(PluginManager::prefix())+"/"+parameters["genomes"];
   command += " -o "+file;
 std::cout << command << std::endl;

 system(command.c_str());
}

PluginProxy<ParSNPPlugin> ParSNPPluginProxy = PluginProxy<ParSNPPlugin>("ParSNP", PluginManager::getInstance());
