# ESP32-Wi-Fi-LED-Control-Panel
An Embedded C++ Project for Wireless LED Control Using ESP32, an HTTP Web Server, and a Responsive Web Interface.

📌Overview:

This project implements a web-based LED control system using the ESP32 development board. The ESP32 connects to a Wi-Fi network and hosts an HTTP server that allows users to control an external LED through a web browser.

The control panel is built with HTML, CSS, and JavaScript and is served directly by the ESP32. Users can turn the LED on or off using two buttons without installing a dedicated mobile application.

This project demonstrates the integration of embedded programming, wireless networking, HTTP request handling, and front-end web technologies in a simple IoT application.

📌Features:


✨ Features

📶 Wi-Fi Connectivity: Connects the ESP32 to a configured wireless network.

🌐 Embedded HTTP Server: Hosts a web interface on port 80 using the Arduino WebServer library.

💡 Wireless LED Control: Turns an external LED on and off through a web browser.

🔗 HTTP Endpoints: Uses /on and /off routes to control GPIO output.

📱 Responsive Web Interface: Adapts the layout to mobile screens using CSS and the viewport meta tag.

⚡ Page Updates Without Reloading: Uses JavaScript fetch() to send requests without navigating to a new page.

📊 LED Status Display: Updates the displayed status after receiving a successful HTTP response.

🖥️ Serial Monitoring: Prints Wi-Fi connection progress and the ESP32's local IP address.

⚙️ How It Works

The application consists of three main components.

1️⃣ Wi-Fi Connection 📶

The ESP32 attempts to connect to the configured Wi-Fi network using WiFi.begin().

While the connection is being established, the firmware checks WiFi.status() and prints connection messages to the Serial Monitor. Once connected, the local IP address is printed so the user can access the web interface.

2️⃣ HTTP Server & GPIO Control 🌐

The program creates a web server on port 80:

WebServer myserver(80);

Three routes are registered:

Route

Function

/

Serves the HTML control panel

/on

Sets GPIO 33 to HIGH

/off

Sets GPIO 33 to LOW

When a request reaches /on or /off, the ESP32 changes the GPIO output and returns a plain-text HTTP response.

3️⃣ Interactive Web Interface 📱

The HTML page contains two buttons and a status paragraph.

JavaScript functions use fetch() to send requests to the ESP32:

🟢 Clicking LED ON sends a request to /on.

🔴 Clicking LED OFF sends a request to /off.

✅ When the HTTP response is successful, JavaScript updates the displayed LED status.

Because the requests use fetch(), the browser does not need to navigate to a new page for each action.

The CSS styles the page with centered content, large buttons, rounded corners, and a visual button-press effect.

🖥️📽️YouTube video link:https://youtu.be/hx7xFWmEdck
