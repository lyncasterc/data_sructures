#include <iostream>
#include <stack>
#include <string>


char opening_brace(char brace){
  switch (brace){
      case ')':
        return '(';
      
    case '}':
        return '{';
      
    case ']':
        return '[';   
  }
}

bool valid_braces(std::string braces) {
  std::stack<char> s;
  
  for(auto &i : braces){
    
   if(i == '(' || i == '{' || i == '['){
     s.push(i);
   }
    
   else {
    
    if(s.top() != opening_brace(i)){
      return false;
    }
    else{
      s.pop();
    }
   }
  }
  
  if(!s.empty()){
    return false;
  }
  
  return true;
}

int main()
{
    std::stack<char> s;

    s.push('[');
    s.push(']');
    char s_top = s.top();

    std::cout << s_top;
    

}