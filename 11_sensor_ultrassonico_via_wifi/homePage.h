const char homePage[] =
R"=====(
<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Ultrassonico</title>
    <style>
        body{
            background-color: rgb(65, 64, 64);
            font-family: Arial, Helvetica, sans-serif;
            text-align: center;
            color: rgba(255, 255, 255, 0.747);
        }
        main{
            margin: auto;
            width: 350px;
            border: 1px solid rgba(255, 255, 255, 0.336);
            box-shadow: 1px 1px 3px rgba(0, 0, 0, 0.425);
        }
        h1{
            text-shadow: 2px 2px 4px rgba(0, 0, 0, 0.719);
        }
        p{
            font-size: 1.2em;
            font-weight: bold;
            text-shadow: 1px 1px 3px black;
        }
        }

    </style>
</head>
<body>
    <h1>Utilizando sensor ultrassônico</h1>
    <main>
      <p id="distancia">Distância: </p>
    </main>

    <script>
        atualiza();
        setInterval(atualiza, 100);
        function atualiza(){
            var req = new XMLHttpRequest();
            req.onreadystatechange = function(){
                if (req.readyState == 4 && req.status == 200){
                    var paragrafo = document.getElementById("distancia");
                    paragrafo.innerText = "Distância: "+ (JSON.parse(req.responseText).distancia) + 'cm'; 
                }

            }
            req.open('GET', 'http://10.0.0.125/distancia', true);
            req.send();
        }
        
    </script>
</body>
</html>
)=====";
