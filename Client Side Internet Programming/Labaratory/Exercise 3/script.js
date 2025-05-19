let string = prompt("Enter String");
let sum = 0
console.log(string);
for(let i = 0; i < string.length; i++) {
    if(!isNaN(parseInt(string[i]))) {
        if(!isNaN(parseInt(string[i+1]))){
            num = parseInt(string[i]) * 10 + parseInt(string[i+1]);
            console.log(num);
            if (!isNaN(parseInt(string[i+2]))){
                num = parseInt(string[i]) * 100 + parseInt(string[i+1] + parseInt(string[i+2]));
                if(num >= 105){
                    document.write("i");
                }
            }
            if(num >= 32 && num <= 99){
                document.write(" ");
            }
        }
    }
    else {
        document.write(string[i]);
    }
}