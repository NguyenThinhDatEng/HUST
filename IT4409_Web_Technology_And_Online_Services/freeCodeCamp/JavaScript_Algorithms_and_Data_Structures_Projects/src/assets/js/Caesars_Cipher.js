import { isAlphaNum } from "../../common/function.js";

// Coding the cipher
// Identify the character within the sentence.
const ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Decode string
function rot13(str) {
  // Chiều dài của ALPHABET
  const len = ALPHABET.length;
  // Xâu được giải mã
  let decodedStr = "";
  // Giải mã
  // Chỉ số của ký tự đã mã hóa và đã giải mã
  let encodedCharIndex, decodedCharIndex;
  for (const c of str) {
    if (isAlphaNum(c)) {
      // Chỉ số hiện tại
      encodedCharIndex = ALPHABET.indexOf(c);
      // Chỉ số sau khi giải mã
      decodedCharIndex = encodedCharIndex - 13;
      // Kiểm tra chỉ số phù hợp
      if (decodedCharIndex < 0) {
        decodedCharIndex += len;
      }
      // Cập nhật kết quả
      decodedStr += ALPHABET[decodedCharIndex];
    } else {
      decodedStr += c;
    }
  }
  // Trả về
  return decodedStr;
}

console.log(rot13("SERR PBQR PNZC"));
