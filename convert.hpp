#pragma once
#include <sstream>
#include <bitset>
#include <vector>
#include <algorithm>

union conv {
  static const std::string bin_to_ascii(const std::string & bin) {
    std::stringstream ss(bin);
    std::string r;
    while(ss.good()) {
      std::bitset<8> bits;
      ss >> bits;
      char c = char(bits.to_ulong());
      r += c;
    }
    return r;
  }

  static const std::string ascii_to_bin(const std::string & ascii) {
    std::stringstream ss(ascii);
    for (size_t i = 0; i < ascii.length(); ++i) {
      std::bitset<8> bits(ascii[i]);
      ss << bits;
      if (ss.str().length() % 8 == 0){
        ss << " ";
      }
    }
    return ss.str();
  }

  static const std::string bin_to_hex(std::string bin) {
    bin.erase(std::remove(bin.begin(), bin.end(), ' '), bin.end() );
    std::bitset<16> bits(bin);
    std::stringstream res;
    res << std::hex << std::uppercase << bits.to_ulong();
    return res.str();
  }
  
  static const std::string ascii_to_hex(std::string ascii) {
    return bin_to_hex(ascii_to_bin(ascii));
  }
};
