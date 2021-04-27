#pragma once
#include <fstream>
#include <string>

void rickCreateFile(std::string filename);
void rickOpenFile(std::string filename);
void rickCloseFile(std::string filename);
void rickOutputFileContents(std::string filename);
void removeFileContents(std::string filename);
void openFileAndAppend(std::string filename);
