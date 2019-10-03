#include "parsehelp.h"
#include <fstream>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <string_view>



namespace parsehelp {



bool ParseHelp::IsAllBlank(const std::string &str) {

  if (str.empty()) {
    return(true);
  } else {
    return std::all_of(str.begin(),str.end(),[](unsigned char c) { return std::isspace(c); });
  }

}


std::optional<unsigned int> ParseHelp::ExtractInt(std::string_view number) {


  // Need to add the fact null is real and all whitespace is real
  try {
    std::string num(number);
    std::string::size_type loc;
    int i_dec = std::stoi(num, &loc);
    if ((loc == std::string::npos) && (i_dec >= 0)) {
      return(i_dec);
    } 
    else if (ParseHelp::IsAllBlank(num)) {
      return(std::nullopt);
    }
    else {
      // Need to Understand what null string or all white space does
      return(std::numeric_limits<unsigned int>::max());
    }
  }
  catch (std::invalid_argument) {
    return(std::numeric_limits<unsigned int>::max());
  }
  catch (std::out_of_range) {
    return(std::numeric_limits<unsigned int>::max());
  }
}



std::optional<std::pair<unsigned int,std::optional<unsigned int>>> ParseHelp::ProcessLine(const std::string &line) {


  // The format is (int, [int|nothing]) per line
  std::string::size_type comma = line.find(',');
  if (comma  == std::string::npos)  {
    // No Comma found
    return(std::nullopt);
  } else {
    // split string in half at comma
    std::string_view  source(line.substr(0, comma));
    std::string_view  dest(line.substr(comma+1, (line.size() - (comma+1))));

    // now convert them to integer and make sure it is pure
    std::optional<unsigned int> source_i = ParseHelp::ExtractInt(source);
    std::optional<unsigned int> dest_i = ParseHelp::ExtractInt(dest);

    bool valid_source = source_i.has_value() && (*source_i != std::numeric_limits<unsigned int>::max());
    bool valid_dest = (dest_i.has_value() && (*dest_i != std::numeric_limits<unsigned int>::max())) || (!dest_i.has_value());
    // We need to build the real number
    if (!valid_source) {
      return(std::nullopt);
    } else if (valid_dest) {
      return(std::make_pair(*source_i, *dest_i));
    } else {
      return(std::make_pair(*source_i, std::nullopt));
    }

  }
  return(std::nullopt);
}






} // namespace parsehelp







