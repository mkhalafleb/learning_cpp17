#include "cmpfiles.h"
#include <fstream>
#include <string>
#include <iostream>



namespace cmpfiles {


CmpFiles::CmpFiles(const std::string &filename1, const std::string &filename2): filename1_(filename1), filename2_(filename2) {
  textstream1_.open(filename1_);
  textstream2_.open(filename2_);
}


std::string CmpFiles::FilesEqual() {
  return("");
}


CmpFiles::~CmpFiles() {
  // close the stream
  if (textstream1_.is_open()) {
    textstream1_.close();
  }

  if (textstream2_.is_open()) {
    textstream2_.close();
  }
}



} // namespace cmpfiles







