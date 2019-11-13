#include "cmpfiles.h"
#include <fstream>
#include <string>
#include <iostream>



namespace cmpfiles {


CmpFiles::CmpFiles(const std::string &filename1, const std::string &filename2): filename1_(filename1), filename2_(filename2) {
  textstream1_.open(filename1_);
  textstream2_.open(filename2_);
}


std::optional<std::string> CmpFiles::FilesEqual() {

  // Streams are open by this time. If not return false
  if ((!textstream1_.is_open()) || (!textstream2_.is_open())) {
    return(std::make_optional(""));
  }

  // We know both are open
  std::string line1(""), line2("");
  while (textstream1_.good() && textstream2_.good()) {
    // Read a line from each
    std::getline(textstream1_, line1);
    std::getline(textstream2_, line2);
    if (line1 != line2) {
       return(std::make_optional(line1+line2));
    }
  }

  // True if they both EOF together
  if ((textstream1_.eof()) && (textstream2_.eof())) {
    return (std::nullopt);
  }

  return(std::make_optional(line1+line2));
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







