<template>
  <div class="main">
    <div class="main_top">
      <div class="weather_top">
        <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 320 512">
          <!--! Font Awesome Pro 6.3.0 by @fontawesome - https://fontawesome.com License - https://fontawesome.com/license (Commercial License) Copyright 2023 Fonticons, Inc. -->
          <path
            d="M144 64c-26.5 0-48 21.5-48 48V276.5c0 17.3-7.1 31.9-15.3 42.5C70.2 332.6 64 349.5 64 368c0 44.2 35.8 80 80 80s80-35.8 80-80c0-18.5-6.2-35.4-16.7-48.9c-8.2-10.6-15.3-25.2-15.3-42.5V112c0-26.5-21.5-48-48-48zM32 112C32 50.2 82.1 0 144 0s112 50.1 112 112V276.5c0 .1 .1 .3 .2 .6c.2 .6 .8 1.6 1.7 2.8c18.9 24.4 30.1 55 30.1 88.1c0 79.5-64.5 144-144 144S0 447.5 0 368c0-33.2 11.2-63.8 30.1-88.1c.9-1.2 1.5-2.2 1.7-2.8c.1-.3 .2-.5 .2-.6V112zM192 368c0 26.5-21.5 48-48 48s-48-21.5-48-48c0-20.9 13.4-38.7 32-45.3V272c0-8.8 7.2-16 16-16s16 7.2 16 16v50.7c18.6 6.6 32 24.4 32 45.3z"
          />
        </svg>
      </div>
      <div class="weather_body">
        <div class="body_left">
          <h1>{{ temperature }} ℃</h1>
          <div class="location">
            <h3>Hà Nội</h3>
            <h5>Việt Nam</h5>
          </div>
        </div>
        <div class="body_right">
          <h1>{{ moment(date).format("DD/MM/YYYY") }}</h1>
          <h1>{{ time }}</h1>
        </div>
      </div>
    </div>
    <div class="table">
      <div class="table__title">Daily Observations</div>
      <table>
        <thead>
          <th style="width: 50%">Time</th>
          <th>Temperature</th>
          <!-- <th>Dew Point</th>
          <th>Humidity</th>
          <th>Wind</th>
          <th>Wind Speed</th>
          <th>Wind Gust</th>
          <th>Pressure</th>
          <th>Precip.</th>
          <th>Condition</th> -->
        </thead>
        <tbody>
          <tr v-for="(time, index) in timeShow" :key="index">
            <td style="width: 50%">
              {{ getTime(time, index) }}
            </td>
            <td>{{ convertToC(data[index]) }} ℃</td>
            <!-- <td>{{ item["dew_point"] }} ℃</td>
            <td>{{ item["humidity"] }} %</td>
            <td>
              {{ item["wind"] }}
            </td>
            <td>{{ item["wind_speed"] }} mph</td>
            <td>{{ item["wind_gust"] }} mph</td>
            <td>{{ item["pressure"] }} in</td>
            <td>{{ item["precip"] }} in</td>
            <td>
              {{ item["condition"] }}
            </td> -->
          </tr>
        </tbody>
      </table>
    </div>
  </div>
</template>

<script>
import moment from "moment";
import axios from "axios";

export default {
  name: "MyApp",
  // Before render Dom
  created() {
    // get current time
    this.time = moment().format("LT");
    // get current temperature
    this.temperature = this.getCurrentTemp();
    // get time milestones to show temp in table
    let pmTimes = this.timeDefault.slice(2, -2);
    this.timeShow = [...this.timeDefault, ...pmTimes];
    // get Data
    this.getData();
  },
  // Update Dom
  mounted() {
    setInterval(() => {
      this.time = moment().format("LT");
      this.temperature = this.getCurrentTemp();
    }, 10000);
  },
  // Methods
  methods: {
    /**
     * Chuyen doi do F sang do C
     * @param {Number} F nhiet do tinh theo do F
     */
    convertToC: function (F) {
      return (((F - 32) * 5) / 9).toFixed(2);
    },

    getTime: function (time, index) {
      if (index < 26) {
        return time + " " + "AM";
      }
      return time + " " + "PM";
    },

    getCurrentTemp: function () {
      const dateNow = new Date();
      const hour = dateNow.getHours();
      const minute = dateNow.getMinutes();
      let index = hour * 2;
      if (hour > 12) {
        if (minute >= 30) {
          return this.convertToC(this.data[index + 1]).replace(".", ",");
        }
        return this.convertToC(this.data[index]).replace(".", ",");
      }
      // hour <= 12
      if (minute >= 30) {
        return this.convertToC(this.data[index + 1]).replace(".", ",");
      }
      return this.convertToC(this.data[index]).replace(".", ",");
    },

    // CALL API
    getData: async function () {
      const url = "http:localhost/predict_results";
      // POST request using axios with error handling
      const article = { title: "Vue POST Request Example" };
      axios
        .post(url, article)
        .then((response) => (this.articleId = response.data.id))
        .catch((error) => {
          this.errorMessage = error.message;
          console.error("There was an error!", error);
        });
    },
  },
  data() {
    return {
      moment: moment,
      temperature: "",
      time: "",
      date: new Date(),
      data: [
        56, 58, 60, 56, 58, 60, 56, 58, 60, 56, 58, 60, 56, 58, 60, 56, 58, 60,
        56, 58, 60, 56, 58, 60, 56, 58, 60, 56, 58, 60, 56, 58, 60, 56, 58, 60,
        56, 58, 60, 56, 58, 60, 56, 58, 60, 56, 58, 60, 56, 58, 60, 56, 58, 60,
      ],
      timeDefault: [
        "00:00",
        "00:30",
        "01:00",
        "01:30",
        "02:00",
        "02:30",
        "03:00",
        "03:30",
        "04:00",
        "04:30",
        "05:00",
        "05:30",
        "06:00",
        "06:30",
        "07:00",
        "07:30",
        "08:00",
        "08:30",
        "09:00",
        "09:30",
        "10:00",
        "10:30",
        "11:00",
        "11:30",
        "12:00",
        "12:30",
      ],
      timeShow: [],
    };
  },
};
</script>

<style >
@import url(./assets/base.css);

.main {
  display: flex;
  flex-direction: column;
  align-items: center;
  width: 100%;
}

.main_top {
  display: flex;
  flex-direction: column;
  background-color: #fff;
  height: 400px;
  width: 500px;
  border-radius: 15px;
  margin-bottom: 24px;
  box-shadow: 0 2px 6px rgba(0, 0, 0, 0.3);
}

.weather_top {
  display: flex;
  justify-content: center;
  align-items: center;
  flex: 1;
}

.weather_body {
  display: flex;
  flex: 1;
  width: 100%;
}

svg {
  height: 80px;
}

.body_left {
  display: flex;
  justify-content: space-evenly;
  align-items: center;
  color: #fff;
  background-color: #000;
  flex: 2;
  border-bottom-left-radius: 15px;
}

.body_right {
  display: flex;
  flex-direction: column;
  justify-content: center;
  align-items: center;
  background-color: #70c1b3;
  flex: 1;
  border-bottom-right-radius: 15px;
}

.body_right h1 {
  margin: 0;
}

/* -------- Table ------------ */
.table {
  width: 50%;
}

.table__title {
  margin-bottom: 12px;
  font-size: 36px;
}

table {
  font-family: arial, sans-serif;
  border-collapse: collapse;
  width: 100%;
}

th {
  background-color: #f7f7f7;
}

td,
th {
  border: 1px solid #dddddd;
  text-align: left;
  padding: 8px;
}

tr:nth-child(even) {
  color: #000;
  background-color: #d6eeee;
}
</style>