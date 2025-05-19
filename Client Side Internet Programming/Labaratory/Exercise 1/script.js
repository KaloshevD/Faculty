let string1 = prompt("vnesi prv string");
let string2 = prompt("vnesi vtor string");
let string3 = prompt("vnesi tret string");
string1 = string1 + " " + string2 + " " + string3;
string1 = string1.split(" ");
let max = 0;
let rememberer = 0;
for(let i = 0; i < string1.length; i++){
    if(string1[i].length > max){
        max = string1[i].length;
        rememberer = i;
    }
}
document.write(string1[rememberer]);