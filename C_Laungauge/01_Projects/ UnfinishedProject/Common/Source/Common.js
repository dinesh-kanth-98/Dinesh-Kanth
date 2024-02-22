
function post(data) {
    console.log("post got called")
    // Convert the data object to JSON
    var jsonData = JSON.stringify(data);

    // Get the current host (including hostname and port)
    var currentHost = window.location.host;

    // Construct the URL with the current host and the desired path
    var url = "http://" + currentHost + "/api/data";

    // Create a new XMLHttpRequest object
    var xhr = new XMLHttpRequest();

    // Configure the request (GET or POST, URL, and whether it's asynchronous)
    xhr.open("POST", url, true); // Change to "POST" for POST requests

    // Set the request header to indicate that you're sending JSON data
    xhr.setRequestHeader("Content-Type", "application/json");

    // Set up a callback function to handle the response
    xhr.onload = function () {
        if (xhr.status >= 200 && xhr.status < 300) {
            // Request was successful
            // var response = xhr.responseText;
            // console.log(response);
            var jsonData = JSON.parse(xhr.responseText); // Parse the JSON string

            // Access the parsed data
            var status = jsonData.status;
            console.log(status); // Output: 0
        } else {
            // Request failed
            console.error("Request failed with status code: " + xhr.status);
        }
    };

    // Send the JSON data in the request body
    xhr.send(jsonData);
}
function sendPostRequest(url, data, callback) {
    var jsonData = JSON.stringify(data);
    var xhr = new XMLHttpRequest();
    xhr.open("POST", url, true);
    xhr.setRequestHeader("Content-Type", "application/json");

    xhr.onload = function () {
        if (xhr.status >= 200 && xhr.status < 300) {
            var responseData = JSON.parse(xhr.responseText);
            var status = responseData.status;
            callback(status, null); // Call the success callback
        } else {
            callback(null, new Error("Request failed with status code: " + xhr.status)); // Call the error callback
        }
    };

    xhr.onerror = function () {
        callback(null, new Error("Network error occurred")); // Call the error callback for network errors
    };

    xhr.send(jsonData);
}

// Example usage with callback functions
var postData = {
    // Your data goes here
};

function focusFieldIfBlank(id) {
    var field = document.getElementById(id);

    if (field.value.trim() === '') {
        field.focus()
        return true;
    }
    else {
        return false;
    };
}

function getValue(id) {
    return document.getElementById(id).value;
}

function clearAllInpuFields() {
    // Get all input elements on the page
    var inputElements = document.querySelectorAll('input');

    // Loop through the input elements and set their values to an empty string
    inputElements.forEach(function (input) {
        input.value = '';
    });
}

function setElementValue(elementId, newValue) {
    var element = document.getElementById(elementId);
    if (element) {
        element.value = newValue;
    }
}

function clearMessageField()
{
    var field = document.getElementById("message");
    if (field) {
        field.textContent = '';
    }
}
