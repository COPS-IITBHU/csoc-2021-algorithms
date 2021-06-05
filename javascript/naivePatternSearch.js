/* Naive Search Algorithm has the worst case time complexity when compared to other algorithms for pattern searching in a string
*/
var string = prompt("Enter string in which to search for pattern : ")
var patternString = prompt("Enter the pattern string ")

var array=new Array();
let k=0;
if (patternString.length > string.length) {
    console.log("Pattern found: 0 times");
} else {
    function patternSearchInString(string, pattenString) {

  let count = 0;
  for (let i = 0; i < string.length; i++) {
    for (let j = 0; j < pattenString.length; j++) {

      if (pattenString[j] !== string[i + j]) break;

      if (j === pattenString.length - 1) {
        array[k] = i;
        k++;
        count++;}
    }
  }
  return count;
}

var count = patternSearchInString(string, patternString)
console.log("Pattern found: ",count ," times");

if (count > 0) {
    console.log("Positions at which the pattern occur : ")

    for (k=0; k<count; k++){
    console.log("Index: ", array[k])

}
}
}