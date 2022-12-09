// Hằng số tương ứng
const ROMAN_NUMERALS = {
  1: "I",
  4: "IV",
  5: "V",
  9: "IX",
  10: "X",
  40: "XL",
  50: "L",
  90: "XC",
  100: "C",
  400: "CD",
  500: "D",
  900: "CM",
  1000: "M",
};

// Các số la tinh lấy từ ROMAN_NUMERALS
let keyOfRomans = [];
for (const key in ROMAN_NUMERALS) {
  keyOfRomans.unshift(parseInt(key));
}

// Lấy phần nguyên của số thập phân
const getIntPart = (num) => {
  return Math.floor(num);
};

// Tạo chuỗi với các ký tự giống nhau
const initStrOfSameChars = (character, quantity) => {
  let result = "";
  while (quantity > 0) {
    result += character;
    quantity--;
  }
  return result;
};

// Chuyển đổi
function convertToRoman(num) {
  let result = "";
  for (const val of keyOfRomans) {
    if (num >= val) {
      result += initStrOfSameChars(ROMAN_NUMERALS[val], getIntPart(num / val));
      num %= val;
    }
  }
  return result;
}

console.log(convertToRoman(2));
