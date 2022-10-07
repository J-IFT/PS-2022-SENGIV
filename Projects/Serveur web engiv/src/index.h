const char MAIN_page[] PROGMEM = R"=====(
	
<html>
    <head>
        <meta charset="UTF-8" />
        <title>SENGIV</title>
    </head>

    <body>
        <img class="logo" src="https://i.ibb.co/n8wsmw7/5-DA7-B2-FA-877-C-4420-B0-A9-F34140-AD4015.png" alt="5-DA7-B2-FA-877-C-4420-B0-A9-F34140-AD4015" border="0">

      <div class= "container">
        <div class="Tuyaux">Tuyau 1 : Vitis labrusca
        <br><br>
          <br> Température : <span id="Capteur">NA</span>°C <br>
          <br> Humidité : 64% <br>
        <br><br>
            <label class="switch">
              <input type="checkbox">
              <span class="slider round"></span>
            </label>
        </div>
        <br><br>
        <div class="Tuyaux">Tuyau 2 : Vitis rupestris
        <br><br>
          <br> Température : <span id="Capteur1">NA</span>°C <br>
          <br> Humidité : 56% <br>
        <br><br>
          <label class="switch">
              <input type="checkbox">
              <span class="slider round"></span>
          </label>
        </div>
        <br><br>
        <div class="Tuyaux">Tuyau 3 : Vitis berlandieri
        <br><br>
          <br> Température : <span id="Capteur2">NA</span>°C <br>
          <br> Humidité : 87% <br>
        <br><br>
          <label class="switch">
              <input type="checkbox">
              <span class="slider round"></span>
          </label>
        </div>
        <br><br>
      </div>

    </body>
</html>

<script>
function sendData(led) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("Capteur").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "setLED?Capteur="+led, true);
  xhttp.send();
}

setInterval(function() {
  // Call a function repetatively with 2 Second interval
  getData();
}, 2000); //2000mSeconds update rate

function getData() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("Capteur").innerHTML =
      this.responseText;
      document.getElementById("Capteur1").innerHTML =
      this.responseText;
      document.getElementById("Capteur2").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "readCapteur", true);
  xhttp.send();
}

</script>


<style>

/* #region ----- RESET CSS -----*/
/* Box sizing rules */
*,
*::before,
*::after {
  box-sizing: border-box;
}

/* Remove default margin */
body,
h1,
h2,
h3,
h4,
p,
figure,
blockquote,
dl,
dd {
  margin: 0;
}


/* Remove list styles on ul, ol elements with a list role, which suggests default styling will be removed */
ul[role='list'],
ol[role='list'] {
  list-style: none;
}

/* Set core root defaults */
html:focus-within {
  scroll-behavior: smooth;
}

/* Set core body defaults */
body {
  min-height: 100vh;
  text-rendering: optimizeSpeed;
  line-height: 1.5;
}

/* A elements that don't have a class get default styles */
a:not([class]) {
  text-decoration-skip-ink: auto;
}

/* Make images easier to work with */
img,
picture {
  max-width: 200%;
  display: block;
}

/* Inherit fonts for inputs and buttons */
input,
button,
textarea,
select {
  font: inherit;
}

/* #region ----- VARIABLES ----- */
:root{
  --clr-background: hsl(242, 28%, 20%);
  --clr-green: hsl(125, 85%, 40%);
  --clr-green-opacity: hsla(125, 85%, 40%, 0.555);
  --clr-green-2: hsl(125, 88%, 35%);
  --clr-red: hsl(0, 74%, 52%);
  --clr-red-2: hsl(0, 76%, 45%);


  --portrait-size: 60px;
}
/* #endregion */

body{
  font-family: 'Trebuchet MS', 'Lucida Sans Unicode', 'Lucida Grande', 'Lucida Sans', Arial, sans-serif;
  background-image: url("https://s2.best-wallpaper.net/wallpaper/iphone/1903/Vineyard-village-sunshine-morning_iphone_1080x1920.jpg");
  background-repeat: no-repeat;
}

.logo{
  width: 250px;
  height: 250px;
  position: absolute;
  padding: 3px;
  background-color: green;
  border-radius: 3px;
  top: 5px;
  right: 5px;
  backdrop-filter: blur(2px);
}

.hidden{
  visibility: hidden;
}

.container {
    width: auto;
    height: 800px;
}

.Tuyaux {
    width: 50%;
    justify-content: right;
    position: relative;
    background-color: #fff;
    border: 5 solid #0d172a;
    border-radius: 1.5rem;
    box-sizing: border-box;
    color: #0d172a;
    cursor: pointer;
    display: inline-block;
    font-family: "Segoe UI", sans-serif;
    font-size: 2rem;
    font-weight: 600;
    line-height: 1;
    padding: 1rem 1.6rem;
    text-align: center;
    text-decoration: none #0d172a solid;
    text-decoration-thickness: auto;
    transition: all .1s cubic-bezier(.4, 0, .2, 1);
    box-shadow: 0px 1px 2px rgba(166, 175, 195, 0.25);
    user-select: none;
    -webkit-user-select: none;
    touch-action: manipulation;
    margin-top: auto;
    margin-left: 25%;
    top: 50%;
}

/* The switch - the box around the slider */
.switch {
  position: relative;
  display: inline-block;
  width: 60px;
  height: 34px;
}

/* Hide default HTML checkbox */
.switch input {
  opacity: 0;
  width: 0;
  height: 0;
}

/* The slider */
.slider {
  position: absolute;
  cursor: pointer;
  top: 0;
  left: 0;
  right: 0;
  bottom: 0;
  background-color: #ccc;
  -webkit-transition: .4s;
  transition: .4s;
}

.slider:before {
  position: absolute;
  content: "";
  height: 26px;
  width: 26px;
  left: 4px;
  bottom: 4px;
  background-color: white;
  -webkit-transition: .4s;
  transition: .4s;
}

input:checked + .slider {
  background-color: #2196F3;
}

input:focus + .slider {
  box-shadow: 0 0 1px #2196F3;
}

input:checked + .slider:before {
  -webkit-transform: translateX(26px);
  -ms-transform: translateX(26px);
  transform: translateX(26px);
}

/* Rounded sliders */
.slider.round {
  border-radius: 34px;
}

.slider.round:before {
  border-radius: 50%;
}

</style>


)=====";