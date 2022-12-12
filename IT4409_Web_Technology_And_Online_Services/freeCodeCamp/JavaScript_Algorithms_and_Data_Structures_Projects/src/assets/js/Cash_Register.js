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

// cid: cash-in-drawer
function checkCashRegister(price, cash, cid) {
  // Máy tính tiền có 2 thuộc tính: trạng thái + giá trị và mệnh giá tiền trả lại
  let output = {
    status: resource.Status.Open,
    change: [],
  };
  let change = cash - price; // Tiền thừa
  const money = reversedObj(_enum.CURRENCY_UNIT); // Đối tượng chứa mệnh giá ($) của từng đơn vị

  // Tỉnh tổng số tiền có ở hiện tại trong register
  const register = cid.reduce(
    function (acc, currentValue) {
      acc.total += currentValue[1];
      return acc;
    },
    { total: 0 }
  );

  // Tổng số tiền có trong máy không đủ để trả lại
  if (register.total < change) {
    output.status = resource.Status.InsufficientFunds;
    return output;
  }

  // Tổng số tiền có trong máy bằng đúng số tiền trả lại
  if (register.total === change) {
    output.status = resource.Status.Close;
    output.change = cid;
    return output;
  }

  // Trường hợp còn lại
  cid = cid.reverse(); // Xét mảng từ cuối lên đầu
  for (const arr of cid) {
    if (change >= money[arr[0]]) {
      if (change >= arr[1]) {
        output.change.push([arr[0], arr[1]]);
        change -= arr[1];
        change = Math.round(change * 1e10) / 1e10;
      } else if (change < arr[1]) {
        let divisionResult = Math.floor(change / money[arr[0]]);
        change -= divisionResult * money[arr[0]];
        change = Math.round(change * 1e10) / 1e10;
        output.change.push([arr[0], divisionResult * money[arr[0]]]);
      }
    }
  }

  // Không có loại tiền phù hợp để trả lại
  if (change > 0) {
    output.status = resource.Status.InsufficientFunds;
    output.change = [];
    return output;
  }

  return output;
}

const res = checkCashRegister(19.5, 20, [
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

console.log(res);
