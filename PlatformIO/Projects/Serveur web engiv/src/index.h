const char MAIN_page[] PROGMEM = R"=====(
	
<html>
    <head>
        <meta charset="UTF-8" />
        <title>SENGIV</title>
        <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.1.2/css/all.min.css"/>
    </head>

    <body>
        <img class="logo" src="https://i.ibb.co/n8wsmw7/5-DA7-B2-FA-877-C-4420-B0-A9-F34140-AD4015.png" alt="5-DA7-B2-FA-877-C-4420-B0-A9-F34140-AD4015" border="0">
        <div class="buttons">
            <div class="btn-tuyau">Tuyau 1</div>
            <div class="btn-tuyau">Tuyau 2</div>
            <div class="btn-tuyau">Tuyau 3</div>
        </div>

		<div>
            <p id="test"> Test </p> 
			<script> document.getElementById("test").innerHTML = "a"; </script>
        </div>
		

    </body>
</html>

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
  max-width: 100%;
  display: block;
}

/* Inherit fonts for inputs and buttons */
input,
button,
textarea,
select {
  font: inherit;
}

/* Remove all animations, transitions and smooth scroll for people that prefer not to see them */
@media (prefers-reduced-motion: reduce) {
  html:focus-within {
   scroll-behavior: auto;
  }
  
  *,
  *::before,
  *::after {
    animation-duration: 0.01ms !important;
    animation-iteration-count: 1 !important;
    transition-duration: 0.01ms !important;
    scroll-behavior: auto !important;
  }
}
/* #endregion */

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
  width: 150px;
  height: 150px;
  position: absolute;
  padding: 5px;
  background-color: var(--clr-green-opacity);
  border-radius: 10px;
  top: 10px;
  right: 10px;
  backdrop-filter: blur(2px);
}

.hidden{
  visibility: hidden;
}

.buttons{
  display: grid;
  grid-template-rows: 1fr 1fr 1fr;
  row-gap: 30px;
  padding-top: 50px;
}

.btn-tuyau{
  background-color: var(--clr-green);
  display: grid;
  justify-items: center;
  align-items: center;
  padding: 10px 15px;
  margin: 0px 220px;
  border-radius: 5px;
  box-shadow: 3px 3px 2px 0px rgba(0,0,0,0.75);
}

.btn-tuyau:hover{
  cursor: pointer;
}

.disable-button{
  background-color: var(--clr-red);
}

</style>


)=====";