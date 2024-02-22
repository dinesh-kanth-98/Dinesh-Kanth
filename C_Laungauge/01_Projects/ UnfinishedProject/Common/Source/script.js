//document.getElementById('login-form').addEventListener('submit', function (e) {
//    e.preventDefault();

//    var username = document.getElementById('username').value;
//    var password = document.getElementById('password').value;
//    var message = document.getElementById('message');

//    if (username === 'your_username' && password === 'your_password') {
//        message.innerHTML = 'Login successful! Redirecting...';
//        setTimeout(function () {
//            window.location.href = 'success.html';
//        }, 1000);
//    } else {
//        message.innerHTML = 'Invalid credentials. Please try again.';
//    }
//});

function get_start() {

    // Get the current host (including hostname and port)
    var currentHost = window.location.host;

    // Construct the URL with the current host and the desired path
    var url = "https://" + currentHost + "/api/data";

    // Create a new XMLHttpRequest object
    var xhr = new XMLHttpRequest();

    // Configure the request (GET or POST, URL, and whether it's asynchronous)
    xhr.open("GET", url, true); // Change to "POST" for POST requests

    // Set up a callback function to handle the response
    xhr.onload = function () {
        if (xhr.status >= 200 && xhr.status < 300) {
            // Request was successful
            var response = xhr.responseText;
            console.log(response);
        } else {
            // Request failed
            console.error("Request failed with status code: " + xhr.status);
        }
    };

    // Send the request (for POST requests, include data as a parameter)
    xhr.send();

    // For POST requests, you can set the request header and provide data like this:
    // xhr.setRequestHeader("Content-Type", "application/json");
    // xhr.send(JSON.stringify({ key: "value" }));
}

function post_start() {
    // For a GET request
    fetch("https://example.com/api/data")
        .then(function (response) {
            if (!response.ok) {
                throw new Error("Request failed with status " + response.status);
            }
            return response.text();
        })
        .then(function (data) {
            console.log(data);
        })
        .catch(function (error) {
            console.error(error);
        });

    // For a POST request with JSON data
    fetch("http://example.com/api/data", {
        method: "POST",
        headers: {
            "Content-Type": "application/json"
        },
        body: JSON.stringify({ key: "value" })
    })
        .then(function (response) {
            if (!response.ok) {
                throw new Error("Request failed with status " + response.status);
            }
            return response.text();
        })
        .then(function (data) {
            console.log(data);
        })
        .catch(function (error) {
            console.error(error);
        });
}

// Get a reference to the form element and the event log paragraph
var form = document.getElementById("login-form");
//var eventLog = document.getElementById("eventLog");

// Function to handle any event and access event data
function handleEvent(event) {
    id = event.target.id;
    // console.log("id:" + id);

    if (event.type == "change") {
        switch (id) {
            case 'password':
                // Handle case 1
                userData.password = getValue(id);
                console.log("password:" + userData.password);
                break;
            case 'username':
                userData.username = getValue(id);
                console.log("username:" + userData.username);
                break;

            // Add more cases as needed
            default:
            // Handle the default case
        }

    }
    if (event.type == "click") {
        switch (id) {
            case 'logIn':
                // userData.username=getValue(id);
                console.log("logIn pressed:");
                if (focusFieldIfBlank('username') === true) return;
                if (focusFieldIfBlank('password') === true) return;
                // post(userData);
                var apiUrl = "http://" + window.location.host + "/Login&";

                sendPostRequest(apiUrl, userData, function (status, error) {
                    if (error) {
                        console.error(error.message);
                    } else {
                        console.log("Received status:", status);
                        if (status == -1) {
                            message.innerHTML = 'Invalid User Name.';
                            setTimeout(clearMessageField,3000);
                        }
                        else if (status == -2) {
                            message.innerHTML = 'Invalid Password.';
                            setTimeout(clearMessageField,3000);

                        }
                        else {
                            message.innerHTML = 'Login Success';

                            setTimeout(clearMessageField,3000);
                            window.location.href = "webchat.html";

                        }
                    }
                });

                break;
            // Add more cases as needed
            default:
            // Handle the default case
        }
    }
}

var userData = {
    username: "",
    password: ""
};


function initLogin()
{
    clearAllInpuFields();
    
    for (var i = 0; i < events.length; i++) {
        form.addEventListener(events[i], handleEvent);
    }
    setElementValue("logIn", "LogIn");
}

// Add an event listener to the form for all events
var events = [
    "click", "mousedown", "mouseup", "mousemove", "keydown",
    "keyup", "submit", "input", "change", "focus", "blur"
];

window.addEventListener('load', function () {
    initLogin();
});

