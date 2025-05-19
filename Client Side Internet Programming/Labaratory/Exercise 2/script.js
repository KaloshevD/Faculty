let supperator_String = prompt("Enter Sepparator String");
supperator_String = supperator_String.split(";");
console.log(supperator_String);
let string = prompt("Enter String");
console.log(string);
for (let i = 0; i < string.length; i++) {
    if(string[i] === supperator_String[0] || string[i] === supperator_String[1]) {
        document.write("<br />");
    }
    else{
        document.write(string[i]);
    }
}