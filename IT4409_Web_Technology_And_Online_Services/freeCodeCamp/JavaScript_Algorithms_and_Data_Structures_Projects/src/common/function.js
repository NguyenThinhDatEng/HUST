// Trả về true nếu c là 1 ký tự chữ hoặc số
const isAlphaNum = function (c) {
  if (
    (c >= "a" && c <= "z") ||
    (c >= "A" && c <= "Z") ||
    (c >= "0" && c <= "9")
  ) {
    return true;
  }
  return false;
};

export { isAlphaNum };
