#include "StringUtils.h"

namespace StringUtils{

std::string Slice(const std::string &str, ssize_t start, ssize_t end) noexcept{
    int len = str.length();
    if (start <= 0){
        start += len; //this ultimately checks the bounds
    }
    if (end <= 0){ 
        end+= len; //checks negative bounds here
    }
    if (start < 0){ 
        return 0; //again checking for negative bound
    }
    if (end > len){ 
        end = len;  //if end is less than the string length then end is just set equal
    }
    if (start >= end){ 
        return""; }
    
    return str.substr(start, end-start); //I found the substring

}

std::string Capitalize(const std::string &str) noexcept{
    std::string r;
    for (auto ch: str){ //iterate through the string
        r += tolower(ch);  //you need to lowercase everything
   }
   r[0] = toupper(r[0]); //index through and capitalize only the first letter
   return r;
}

std::string Upper(const std::string &str) noexcept{
    std:: string up; //initialize a variable called up 
    for (char c: str ){ 
        if (std::isupper(static_cast<unsigned char>(c))){ //iterate through and we check if it is upper 
            up += c;
        }
    }
   return up; //if so then we return the uppercase elements 

}

std::string Lower(const std::string &str) noexcept{
    std:: string lower; //establish string lower
    for (char c: str){ //iterate through 
        if (std:: islower(static_cast<unsigned char> (c))){ //utilized islower from the website and check which letterare lower 
            lower += c;
       }
   }
   return lower; //return all lowercased letters 
}

std::string LStrip(const std::string &str) noexcept{
    size_t ind = 0; //set an index = 0 
    //while index is less than string length and isspace (found from website)
    while (ind < str.length() && std::isspace(static_cast<unsigned char>(str[ind]))){
        ind++; //iterate through because we are strpping through left 
   }
   return str.substr(ind); //return the actual values without whitespace 
}

std::string RStrip(const std::string &str) noexcept{
    size_t ind = str.length(); //we want to capture string's full length 
    while (ind < str.length() && std::isspace(static_cast<unsigned char>(str[ind - 1]))){
        ind--; //using isspace we extract the spaces 
   }
   return str.substr(0, ind); //substrip the 0 to index to return the string 
}


std::string Strip(const std::string &str) noexcept{
    return LStrip(RStrip(str));; //to fully strip call on both lstrip + rstrip to fully strip the whitespace off the string 
}

std::string Center(const std::string &str, int width, char fill) noexcept{
    if ((str.size() >= width)){ //if width less than or equal to size 
        return str;
    } //then we have to return the 
    return str + std::string(((width - str.size())/2), fill) + std::string(((width - str.size()/2) - (width - str.size())), fill);
}

std::string LJust(const std::string &str, int width, char fill) noexcept{
    if ((str.size() >= width)){
        return str;
    }
    return str + std::string(width-str.size(), fill);
}

std::string RJust(const std::string &str, int width, char fill) noexcept{
    if ((str.size() >= width)){ //bounds checking else return string 
       return str;
   }
   return str + std::string(width-str.size(), fill); //this would simply return the strin + a new string of number of spaces  
   //found the fill function via the webstie 
}



std::string Replace(const std::string &str, const std::string &old, const std::string &rep) noexcept{
    std:: string result = str; //this creates the string 
    size_t position = 0; //initialize position 
    while (position < result.size()){ //bounds checking 
        position = result.find(old, position); 
        if (position < result.size()){
            result.replace(position, old.length(), rep);
            position += rep.length(); //resize the position 
        } else{
            break;
       }
   }
   return result;

}

std::vector< std::string > Split(const std::string &str, const std::string &splt) noexcept{
    size_t index = 0; //initialize an index 
    size_t end = str.find_first_of(splt); //found find_first of in the website 
    std::vector<std::string> output; //needed to create a vector output 
    while (end != std:: string::npos){ //checks until no delimiter found 
        output.emplace_back(str.substr(index, end-index)); //this gets substring for us 
        index = end +1; //index continues to iterate thru 
        end = str.find_first_of(splt, index); //find the next char 
    }
    output.emplace_back(str.substr(index)); //inputs final part of string 
    return output;
}


std::string Join(const std::string &str, const std::vector< std::string > &vect) noexcept{
    if (vect.empty()) return; 

    std:: string result; //intialize string 
    for (size_t index = 0; index < vect.size(); ++index){
        result += vect[index]; //iterate vect to string 
        if (index < vect.size()-1){
            result += str; 
        }
    }
    return result; //outputs a string 

}

std::string ExpandTabs(const std::string &str, int tabsize) noexcept{
    std::string output; //initialize that output is a string 
    int ind = 0; //index is set to 0 
    for (char c: str){ //iterate thru 
        if (c == '\t'){ //base case --> if c is some tab 
            int sp = tabsize - (ind % tabsize); //then we initialize space which subtracts index mod tabsize 
            output += std::string(sp,' '); //this just updates output 
            ind += sp; //index also takes in numerical value of space s
        } else {
            output += c;//output results with the characters // string output 
            ind++; //index grows 
        }
    }
    return output;

}

int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept{
    // Replace code here
    return 0;
}

};