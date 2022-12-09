import { isAlphaNum } from "../../common/function.js";

function palindrome(str) {
  // Viết thường các ký tự trong chuỗi
  str = str.toLowerCase();
  // Tạo chuỗi kí tự chỉ gồm chữ và số từ str
  let characters = "";
  for (const c of str) {
    if (isAlphaNum(c)) characters += c;
  }
  // Kiểm tra
  const len = characters.length; // chiều dài chuỗi characters
  for (let i = 0; i < len; i++) {
    if (characters[i] != characters[len - i - 1]) {
      return false;
    }
  }
  return true;
}

const words = [
  "eye",
  "_eye",
  "race car",
  "A man, a plan, a canal. Panama",
  "My age is 0, 0 si ega ym.",
  "0_0 (: /-\\ :) 0-0",
  "five|\\_/|four",
];

for (const word of words) {
  console.log(palindrome(word));
}
