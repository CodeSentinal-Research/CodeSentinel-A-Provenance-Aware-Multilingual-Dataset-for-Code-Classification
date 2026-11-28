function validParentheses(s) {
    var stack = [];
    for(var i = 0; i < s.length; i++){
        if(s[i] == '('){
            stack.push(s[i]);
        } else if(s[i] == ')'){
            if(stack.length == 0 || stack.pop() != '('){
                return "Invalid";
            }
        } else if(s[i] == '['){
            stack.push(s[i]);
        } else if(s[i] == ']'){
            if(stack.length == 0 || stack.pop() != '['){
                return "Invalid";
            }
        } else if(s[i] == '{'){
            stack.push(s[i]);
        } else if(s[i] == '}'){
            if(stack.length == 0 || stack.pop() != '{'){
                return "Invalid";
            }
        }
    }
    if(stack.length != 0){
        return "Invalid";
    }
    return "Valid";
}