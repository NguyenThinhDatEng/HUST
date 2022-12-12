import _enum from "../../common/enum.js";
import resource from "../../common/resource.js";

// Hàm đảo ngược đối tượng
const reversedObj = (obj) => {
  let newObj = {};
  // Mảng chứa các key đã được đảo ngược
  const keys = Object.keys(obj).reverse();
  // Thực hiện đảo ngược
  for (const key of keys) {
    newObj[key] = obj[key];
  }
  // Trả về đối tượng đã được đảo ngược
  return newObj;
};

function checkCashRegister(price, cash, cid) {
  // cash-in-drawer
  // Máy tính tiền có 2 thuộc tính: trạng thái + giá trị và mệnh giá tiền trả lại
  let cashRegister = {
    status: resource.Status.Open,
    change: [],
  };
  let change = cash - price; // Tiền thừa
  const money = reversedObj(_enum.CURRENCY_UNIT); // Đối tượng chứa mệnh giá ($) của từng đơn vị
  cid = cid.reverse();

  // Tính tiền
  for (const arr of cid) {
    if (change >= money[arr[0]]) {
      if (change >= arr[1]) {
        cashRegister.change.push([arr[0], arr[1]]);
        change -= arr[1];
        change = Math.round(change * 1e10) / 1e10;
      } else if (change < arr[1]) {
        let divisionResult = Math.floor(change / money[arr[0]]);
        change -= divisionResult * money[arr[0]];
        change = Math.round(change * 1e10) / 1e10;
        cashRegister.change.push([arr[0], divisionResult * money[arr[0]]]);
      }
    }
  }
  // Cập nhật kết quả trả về
  if (change > 0) {
    cashRegister.status = resource.Status.InsufficientFunds;
    cashRegister.change = [];
  }
  return cashRegister;
}

const b = checkCashRegister(19.5, 20, [
  ["PENNY", 0.5],
  ["NICKEL", 0],
  ["DIME", 0],
  ["QUARTER", 0],
  ["ONE", 0],
  ["FIVE", 0],
  ["TEN", 0],
  ["TWENTY", 0],
  ["ONE HUNDRED", 0],
]);

console.log(b);
