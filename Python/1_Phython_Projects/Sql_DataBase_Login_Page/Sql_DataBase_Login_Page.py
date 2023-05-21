
from tkinter import *
import mysql.connector
from mysql.connector import Error


def insta_login():
    username = entry_username.get()
    password = entry_password.get()

    # Perform login authentication logic here
    # You can check the entered username and password against a database or any other authentication mechanism

    if username == "admin" and password == "password":
        welcome_window.destroy()

        # Create the welcome window
        Login_Page = Tk()
        Login_Page.title("Login Page")
        Login_Page.configure(bg="#333333")
        Login_Page.geometry('400x350')

        # Create and position the welcome message label
        label_welcome = Label(Login_Page, text="Login Page",
                              fg="white", bg="#333333", font=("Verdana", 20))
        label_welcome.pack(pady=50)

        Login_Page.mainloop()
    else:

        label_status.config(text="Login failed", fg="red")
        # Schedule a callback to clear the label after 3 seconds
        root.after(3000, clear_label_status)


def show_WelcomeScreen():
    global entry_username, entry_password, welcome_window, label_status

    root.destroy()
    # Create the welcome window
    welcome_window = Tk()
    welcome_window.title("Instagram")
    welcome_window.configure(bg="#333333")
    welcome_window.geometry('400x350')

    # Create and position the welcome message label
    label_welcome = Label(welcome_window, text="Welcome to Instagram!",
                          fg="white", bg="#333333", font=("Verdana", 16))
    label_welcome.pack(pady=30)

    # Create and position the username label and entry
    label_username = Label(welcome_window, text="User_ID:",
                           fg="white", bg="#333333", font=("Verdana", 14))
    label_username.pack()
    entry_username = Entry(welcome_window, font=("Verdana", 14))
    entry_username.pack(pady=5)

    # Create and position the password label and entry
    label_password = Label(welcome_window, text="Password:",
                           fg="white", bg="#333333", font=("Verdana", 14))
    label_password.pack()
    entry_password = Entry(welcome_window, show="*", font=("Verdana", 14))
    entry_password.pack(pady=10)

    # Create and position the login button
    button_login = Button(welcome_window, text="Login", command=insta_login,
                          bg="#555555", fg="white", font=("Verdana", 14))
    button_login.pack(pady=10)

    label_status = Label(welcome_window, text="", fg="white",
                         bg="#333333", font=("Verdana", 14))
    label_status.pack(pady=20)

    # Start the welcome window's event loop
    welcome_window.mainloop()


def login():
    username = entry_username.get()
    password = entry_password.get()

    try:
        # Create a MySQL connection
        connection = mysql.connector.connect(
            host='localhost',
            user=username,
            password=password,
            database='Mine'
        )

        if connection.is_connected():
            print('Connected to MySQL database')
            show_WelcomeScreen()
        # Close the connection
        connection.close()
        print('Disconnected from MySQL database')

    except Error:
        print(f'Error connecting to MySQL database:')
        # Handle the specific error or show an error message to the user
        print("Connection failed")
        label_status.config(text="Login failed", fg="red")
        # Schedule a callback to clear the label after 3 seconds
        root.after(3000, clear_label_status)


def clear_label_status():
    label_status.config(text="")


# Create the main window
root = Tk()
root.title("Data Base Login Page")
root.configure(bg="#333333")
root.geometry('400x300')

# Create and position the UI elements
frame = Frame(root, bg="#333333")
frame.pack(pady=50)

label_username = Label(frame, text="Username:", fg="white",
                       bg="#333333", font=("Verdana", 14))
label_username.grid(row=0, column=0, pady=10)

entry_username = Entry(frame, font=("Verdana", 14))
entry_username.grid(row=0, column=1, padx=10, pady=10)

label_password = Label(frame, text="Password:", fg="white",
                       bg="#333333", font=("Verdana", 14))
label_password.grid(row=1, column=0, pady=10)

entry_password = Entry(frame, show="*", font=("Helvetica", 14))
entry_password.grid(row=1, column=1, padx=10, pady=10)

button_login = Button(frame, text="Login", command=login,
                      bg="#555555", fg="white", font=("Verdana", 14))
button_login.grid(row=2, column=0, columnspan=2, pady=10)

label_status = Label(root, text="", fg="white",
                     bg="#333333", font=("Verdana", 14))
label_status.pack(pady=20)

# Start the main event loop
root.mainloop()
