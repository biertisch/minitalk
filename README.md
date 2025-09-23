# Minitalk

![C](https://img.shields.io/badge/language-C-blue.svg)

### Overview

Minitalk is a lightweight **data exchange programme** using **Unix signals**. It enables a **client** to send binary-encoded messages to a **server**, which reconstructs and prints them.

The main challenges of the project are:
* **Reliability**: ensuring no data is lost or corrupted, even under rapid signal transmission.
* **Responsiveness**: the server must handle multiple clients in sequence without crashing, freezing, or leaking memory, while processing messages at high speed.

This project is part of the 42 curriculum, introducing students to **inter-process communication (IPC) through low-level signal handling**.

---
### Features

* Server receives messages from **multiple clients in a sequence** without restarting.
* **Unicode characters** are supported (bonus).
* **Acknowledgement system**: the server confirms each received message to the client (bonus).

---
### Implementation details

* Use of **SIGUSR1** and **SIGUSR2** with **custom signal handlers** to encode binary data.
* Each character is transmitted **bit by bit** and reassembled by the server.
* The client waits for the server's **acknowledgement** before sending the next bit, ensuring process synchronization and reliable delivery.

---
### Installation

**Requirements**: `gcc`, `make`

```
git clone https://github.com/biertisch/minitalk.git
cd minitalk
make		# mandatory
make bonus	# bonus
```

---
### Usage

Start the server first. It will print its PID, which the client uses to connect.

```
./server								# server
./client <server_pid> <message>			# client

./server_bonus							# bonus server
./client_bonus <server_pid> <message>	# bonus client
```

---
### About 42

42 is a computer science school founded in Paris in 2013. It follows a project-based, peer-to-peer pedagogy focused on low-level programming and algorithmic thinking.

---
### License & Contact

This repository is open for learning and reuse. Contributions, suggestions, and discussions are welcome — feel free to open an issue or reach out.
work in progress
