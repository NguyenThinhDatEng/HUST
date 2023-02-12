import { createApp } from "vue";
import App from "./App.vue";
import axios from "axios";
import VueAxios from "vue-axios";


const app = createApp(App);

app.provide("axios", app.config.globalProperties.axios);
app.use(VueAxios, axios);
app.mount("#app");
