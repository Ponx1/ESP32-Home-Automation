const char INDEX[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Smart Home</title>
    <style>
        .button {
            background-color: #4CAF50;
            border: none;
            color: white;
            padding: 15px 25px;
            margin: 5px 5px;
            text-align: center;
            font-size: 16px;
            cursor: pointer;
        }

        .button:hover {
            background-color: green;
        }

        .buttonGroup {
            background-color: lightgray;
            padding: 10px 15px;
            margin-right: auto;
            margin-left: auto;
            margin-top: 15px;
            width: 50%;
            text-align: center;
        }

        .description {
            font-family: Lato, Calibri, Arial;
            font-size: 18px;
        }

        .title {
            margin: auto;
            text-align: center;
        }

        #Title {
            font-family: Lato, Calibri, Arial;
        }

        .footer {
            text-align: right;
            margin: 5% 5%
        }
    </style>

</head>

<body>
    <!-- partial:index.partial.html -->

    <head>
        <div class="title">
            <h1 id="Title">Auto - Casa</h1>
        </div>
    </head>

    <body>
        <div>
            <div class="buttonGroup">
                <p class="description">Patio</p>
                <button class="button" type="button" id="btn0" onclick="turnRelay('Relay1')">Riego</input>
                <button class="button" type="button" id="btn0" onclick="turnRelay('Relay2')">Luz</input>
            </div>
            <div class="buttonGroup">
                <p class="description">Sala</p>
                <button class="button" type="button" onclick="turnRelay('Relay3')">Lampara</input>
                <button class="button" type="button" onclick="turnRelay('Relay4')">Ventilador</input>
            </div>
        </div>
        <div class="footer">
            <p class="description">Made by PONX</p>
        </div>
    </body>
    <!-- partial -->

</body>

<script>

    var xmlHttp = createXmlHttpObject();
    // function to create XML object
    function createXmlHttpObject() {
        if (window.XMLHttpRequest) {
            xmlHttp = new XMLHttpRequest();
        }
        else {
            xmlHttp = new ActiveXObject("Microsoft.XMLHTTP");
        }
        return xmlHttp;
    }
    function turnRelay1(roomName) {
        const xhttp = new XMLHttpRequest();
        console.log("Sending request for: " + roomName)
        xhttp.open("PUT", roomName, true);
        xhttp.send();
    }

    function turnRelay(roomName) {
        fetch(roomName, {
            method: "PUT",
            headers: {"Content-type": "application/json;charset=UTF-8"}
        })
        console.log("Sending request for: " + roomName)

    }

    function response(){
        //update UI elements
    }

    function process(){
     
     if(xmlHttp.readyState==0 || xmlHttp.readyState==4) {
        xmlHttp.open("PUT","xml",true);
        xmlHttp.onreadystatechange=response;
        xmlHttp.send(null);
      }       
        // you may have to play with this value, big pages need more porcessing time, and hence
        // a longer timeout
        setTimeout("process()",100);
    }
</script>

</html>

)=====";
