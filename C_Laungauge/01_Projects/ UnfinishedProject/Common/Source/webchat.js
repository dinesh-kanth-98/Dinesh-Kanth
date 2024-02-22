
// Function to handle any event and access event data
function handleEvent(event) {
    id = event.target.id;
    // console.log("id:" + id);

    if (event.type == "change") {
        switch (id) {
            case 'messageInput':
                // Handle case 1
                MessageData.currentUserMessage = getValue(id);
                MessageData.currentUserName= "tempUser"
                console.log("passMessageData:" + MessageData.currentUserMessage);
                break;

            // case 'username':
            //     userData.username = getValue(id);
            //     console.log("username:" + userData.username);
            //     break;

            // Add more cases as needed
            default:
            // Handle the default case
        }

    }
    if (event.type == "click") {
        switch (id) {
            case 'sendButton':
                // userData.username=getValue(id);
                console.log("send pressed:");
                if (focusFieldIfBlank('messageInput') === true) return;

                var apiUrl = "http://" + window.location.host + "/userMessage&";
                console.log(apiUrl);

                sendPostRequest(apiUrl, MessageData, function (status, error) {
                    if (error) {
                        console.error(error.message);
                    } else {
                        console.log("Received status:", status);
                        if (status == 0) {
                            console.log("message sent:", status);
                            const chatMessages = document.querySelector('.chat-messages');
                            const messageInput = document.getElementById('messageInput');
                            const newMessage = document.createElement('p'); // Create a new <p> element
                            newMessage.textContent = MessageData.currentUserMessage; // Set the text content of the new paragraph
                            chatMessages.appendChild(newMessage); //
                            messageInput.value = '';
                        }
                        else if (status == -2) {
                            message.innerHTML = 'Invalid Password.';
                            setTimeout(clearMessageField, 3000);

                        }
                        else {
                            message.innerHTML = 'Login Success';
                            setTimeout(clearMessageField, 3000);
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

var MessageData = {
    currentUserName: "",
    currentUserMessage: ""
};


function initLogin() {
    // Get a reference to the form element and the event log paragraph
    var div = document.getElementById("window");

    clearAllInpuFields();

    for (var i = 0; i < events.length; i++) {
        div.addEventListener(events[i], handleEvent);
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
