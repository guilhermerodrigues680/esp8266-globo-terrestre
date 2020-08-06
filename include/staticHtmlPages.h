#ifndef staticHtmlPages_h
#define staticHtmlPages_h

#include <Arduino.h>

const char defaultPageCss[] PROGMEM = R"=====(
body {
  display: grid;
  grid-template-columns: 25vw 75vw;
  grid-template-rows: min-content 1fr min-content;
  grid-template-areas:
  "h h"
  "n m"
  "f f";
  margin: 0;
  padding: 0;
  min-height: 100vh;
  background: #fff;
  color: #4a4a4a;
  font-family: Arial, Helvetica, sans-serif;
}
header, footer {
  font-size: large;
  text-align: center;
  padding: 0.3em 0;
  background-color: #4a4a4a;
  color: #f9f9f9;
}
header {
  grid-area: h;
}
nav {
  padding: 0 10px;
  background: #eee;
  grid-area: n;
}
main {
  padding: 0 20px;
  background: #f9f9f9;
  grid-area: m;
}
footer {
  grid-area: f;
}
)=====";

const char htmlIndexPage[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="pt-br">

<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>ESP8266 - Home</title>
  <link rel="stylesheet" href="default-page.css">
</head>

<body>
  <header>Globo Terrestre - Web App + ESP8266 NodeMCU</header>

  <main>
    <h1>ESP8266 - Home</h1>
    <p>Abaixo estão listadas as rotas disponiveis no ESP8266</p>
    <p>Página Inicial (Você está nela)</p>
    <p><a href="/status">/status</a> - ???</p>
    <p><a href="/globe">/globe</a> - ???</p>
    <p><a href="/config">/config</a> - ???</p>
    <p><a href="/test">/test</a> - ???</p>
    <p><a href="/coord">/coord</a> - ???</p>
    <p><a href="/center-globe">/center-globe</a> - ???</p>
    <p><a href="/health">/health</a> - ???</p>
    <p><a href="/404.html">/... 404 Not Found</a> - ???</p>
  </main>

  <nav>
    <h4>Páginas</h4>
    <p>
      <a href="https://guilhermerodrigues680.github.io/website-terrestrial-globe-with-esp8266/">
        Home - WebApp Globo Terrestre
      </a>
    </p>
  </nav>

  <footer>Autor: Guilherme Rodrigues</footer>
</body>

</html>
)=====";

const char html404Page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="pt-br">

<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>404 Not Found</title>
  <style>
    :root {
      --main-color: #eaeaea;
      --stroke-color: black;

    }

    body {
      background: var(--main-color);
    }

    h1 {
      margin: 100px auto 0 auto;
      color: var(--stroke-color);
      font-family: 'Encode Sans Semi Condensed', Verdana, sans-serif;
      font-size: 10rem;
      line-height: 10rem;
      font-weight: 200;
      text-align: center;
    }

    h2 {
      margin: 20px auto 30px auto;
      font-family: 'Encode Sans Semi Condensed', Verdana, sans-serif;
      font-size: 1.5rem;
      font-weight: 200;
      text-align: center;
    }

    h1,
    h2 {
      -webkit-transition: opacity 0.5s linear, margin-top 0.5s linear;
      /* Safari */
      transition: opacity 0.5s linear, margin-top 0.5s linear;
    }

    .loading h1,
    .loading h2 {
      margin-top: 0px;
      opacity: 0;
    }

    .gears {
      position: relative;
      margin: 0 auto;
      width: auto;
      height: 0;
    }

    .gear {
      position: relative;
      z-index: 0;
      width: 120px;
      height: 120px;
      margin: 0 auto;
      border-radius: 50%;
      background: var(--stroke-color);
    }

    .gear:before {
      position: absolute;
      left: 5px;
      top: 5px;
      right: 5px;
      bottom: 5px;
      z-index: 2;
      content: "";
      border-radius: 50%;
      background: var(--main-color);
    }

    .gear:after {
      position: absolute;
      left: 25px;
      top: 25px;
      z-index: 3;
      content: "";
      width: 70px;
      height: 70px;
      border-radius: 50%;
      border: 5px solid var(--stroke-color);
      box-sizing: border-box;
      background: var(--main-color);
    }

    .gear.one {
      left: -130px;
    }

    .gear.two {
      top: -75px;
    }

    .gear.three {
      top: -235px;
      left: 130px;
    }

    .gear .bar {
      position: absolute;
      left: -15px;
      top: 50%;
      z-index: 0;
      width: 150px;
      height: 30px;
      margin-top: -15px;
      border-radius: 5px;
      background: var(--stroke-color);
    }

    .gear .bar:before {
      position: absolute;
      left: 5px;
      top: 5px;
      right: 5px;
      bottom: 5px;
      z-index: 1;
      content: "";
      border-radius: 2px;
      background: var(--main-color);
    }

    .gear .bar:nth-child(2) {
      transform: rotate(60deg);
      -webkit-transform: rotate(60deg);
    }

    .gear .bar:nth-child(3) {
      transform: rotate(120deg);
      -webkit-transform: rotate(120deg);
    }

    @-webkit-keyframes clockwise {
      0% {
        -webkit-transform: rotate(0deg);
      }

      100% {
        -webkit-transform: rotate(360deg);
      }
    }

    @-webkit-keyframes anticlockwise {
      0% {
        -webkit-transform: rotate(360deg);
      }

      100% {
        -webkit-transform: rotate(0deg);
      }
    }

    @-webkit-keyframes clockwiseError {
      0% {
        -webkit-transform: rotate(0deg);
      }

      20% {
        -webkit-transform: rotate(30deg);
      }

      40% {
        -webkit-transform: rotate(25deg);
      }

      60% {
        -webkit-transform: rotate(30deg);
      }

      100% {
        -webkit-transform: rotate(0deg);
      }
    }

    @-webkit-keyframes anticlockwiseErrorStop {
      0% {
        -webkit-transform: rotate(0deg);
      }

      20% {
        -webkit-transform: rotate(-30deg);
      }

      60% {
        -webkit-transform: rotate(-30deg);
      }

      100% {
        -webkit-transform: rotate(0deg);
      }
    }

    @-webkit-keyframes anticlockwiseError {
      0% {
        -webkit-transform: rotate(0deg);
      }

      20% {
        -webkit-transform: rotate(-30deg);
      }

      40% {
        -webkit-transform: rotate(-25deg);
      }

      60% {
        -webkit-transform: rotate(-30deg);
      }

      100% {
        -webkit-transform: rotate(0deg);
      }
    }

    .gear.one {
      -webkit-animation: anticlockwiseErrorStop 2s linear infinite;
    }

    .gear.two {
      -webkit-animation: anticlockwiseError 2s linear infinite;
    }

    .gear.three {
      -webkit-animation: clockwiseError 2s linear infinite;
    }

    .loading .gear.one,
    .loading .gear.three {
      -webkit-animation: clockwise 3s linear infinite;
    }

    .loading .gear.two {
      -webkit-animation: anticlockwise 3s linear infinite;
    }
  </style>
</head>

<body class="loading">
  <h1>404</h1>
  <h2>Pagina nao encontrada no ESP8266<b>:/</b></h2>
  <div class="gears">
    <div class="gear one">
      <div class="bar"></div>
      <div class="bar"></div>
      <div class="bar"></div>
    </div>
    <div class="gear two">
      <div class="bar"></div>
      <div class="bar"></div>
      <div class="bar"></div>
    </div>
    <div class="gear three">
      <div class="bar"></div>
      <div class="bar"></div>
      <div class="bar"></div>
    </div>
  </div>
  <script>
    var bodyL = document.querySelector('body');
    setTimeout(function () {
      bodyL.className = '';
    }, 1000);
  </script>
</body>

</html>
)=====";

const char centerGlobePage[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="pt-br">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Globo Terrestre - Ajuste de centro</title>
  <link rel="stylesheet" href="default-page.css">
</head>
<body>
  <header>Globo Terrestre - Web App + ESP8266 NodeMCU</header>

  <main>
    <h1>Ajustando centro do globo</h1>
    <p>Latitude 0 e longitude 0 - Ilha Nula</p>
    <p><a href="http://192.168.2.108/center-globe?steps=10">Girar++</a></p>
    <p><a href="http://192.168.2.108/center-globe?steps=-10">Girar--</a></p>
    <p><a href="http://192.168.2.108/center-globe?center=1">Confirmar Centro</a></p>
  </main>

  <nav>
    <h4>Paginas</h4>
    <p>Globo Terrestre - Web App</p>
  </nav>

  <footer>Autor: Guilherme Rodrigues</footer>
</body>
</html>
)=====";

#endif